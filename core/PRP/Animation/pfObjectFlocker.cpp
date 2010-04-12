/* This file is part of HSPlasma.
 *
 * HSPlasma is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * HSPlasma is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HSPlasma.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "pfObjectFlocker.h"

/* pfObjectFlocker::pfFlock */
pfObjectFlocker::pfFlock::pfFlock()
               : fGoalWeight(8.0f), fRandomWeight(12.0f),
                 fSeparationWeight(12.0f), fSeparationRadius(5.0f),
                 fCohesionWeight(8.0f), fCohesionRadius(9.0f), fMaxForce(10.0f),
                 fMaxSpeed(5.0f), fMinSpeed(4.0f) { }


/* pfObjectFlocker */
pfObjectFlocker::pfObjectFlocker()
               : fNumBoids(0), fUseTargetRotation(false),
                 fRandomizeAnimationStart(false) { }

void pfObjectFlocker::read(hsStream* S, plResManager* mgr) {
    plSingleModifier::read(S, mgr);

    S->readByte();
    fNumBoids = S->readByte();
    fBoidKey = mgr->readKey(S);

    fFlock.fGoalWeight = S->readFloat();
    fFlock.fRandomWeight = S->readFloat();
    fFlock.fSeparationWeight = S->readFloat();
    fFlock.fSeparationRadius = S->readFloat();
    fFlock.fCohesionWeight = S->readFloat();
    fFlock.fCohesionRadius = S->readFloat();
    fFlock.fMaxForce = S->readFloat();
    fFlock.fMaxSpeed = S->readFloat();
    fFlock.fMinSpeed = S->readFloat();

    fUseTargetRotation = S->readBool();
    fRandomizeAnimationStart = S->readBool();
}

void pfObjectFlocker::write(hsStream* S, plResManager* mgr) {
    plSingleModifier::write(S, mgr);

    S->writeByte(1);
    S->writeByte(fNumBoids);
    mgr->writeKey(S, fBoidKey);

    S->writeFloat(fFlock.fGoalWeight);
    S->writeFloat(fFlock.fRandomWeight);
    S->writeFloat(fFlock.fSeparationWeight);
    S->writeFloat(fFlock.fSeparationRadius);
    S->writeFloat(fFlock.fCohesionWeight);
    S->writeFloat(fFlock.fCohesionRadius);
    S->writeFloat(fFlock.fMaxForce);
    S->writeFloat(fFlock.fMaxSpeed);
    S->writeFloat(fFlock.fMinSpeed);

    S->writeBool(fUseTargetRotation);
    S->writeBool(fRandomizeAnimationStart);
}

void pfObjectFlocker::IPrcWrite(pfPrcHelper* prc) {
    plSingleModifier::IPrcWrite(prc);

    prc->startTag("FlockParams");
    prc->writeParam("NumBoids", fNumBoids);
    prc->writeParam("UseTargetRotation", fUseTargetRotation);
    prc->writeParam("RandomizeAnimationStart", fRandomizeAnimationStart);
    prc->endTag(true);

    prc->writeSimpleTag("Boid");
    fBoidKey->prcWrite(prc);
    prc->closeTag();

    prc->startTag("Flock");
    prc->writeParam("GoalWeight", fFlock.fGoalWeight);
    prc->writeParam("RandomWeight", fFlock.fRandomWeight);
    prc->writeParam("SeparationWeight", fFlock.fSeparationWeight);
    prc->writeParam("SeparationRadius", fFlock.fSeparationRadius);
    prc->writeParam("CohesionWeight", fFlock.fCohesionWeight);
    prc->writeParam("CohesionRadius", fFlock.fCohesionRadius);
    prc->writeParam("MaxForce", fFlock.fMaxForce);
    prc->writeParam("MaxSpeed", fFlock.fMaxSpeed);
    prc->writeParam("MinSpeed", fFlock.fMinSpeed);
    prc->endTag(true);
}

void pfObjectFlocker::IPrcParse(const pfPrcTag* tag, plResManager* mgr) {
    if (tag->getName() == "FlockParams") {
        fNumBoids = tag->getParam("NumBoids", "0").toUint();
        fUseTargetRotation = tag->getParam("UseTargetRotation", "false").toBool();
        fRandomizeAnimationStart = tag->getParam("RandomizeAnimationStart", "false").toBool();
    } else if (tag->getName() == "Boid") {
        if (tag->hasChildren())
            fBoidKey = mgr->prcParseKey(tag->getFirstChild());
    } else if (tag->getName() == "Flock") {
        fFlock.fGoalWeight = tag->getParam("GoalWeight", "0").toFloat();
        fFlock.fRandomWeight = tag->getParam("RandomWeight", "0").toFloat();
        fFlock.fSeparationWeight = tag->getParam("SeparationWeight", "0").toFloat();
        fFlock.fSeparationRadius = tag->getParam("SeparationRadius", "0").toFloat();
        fFlock.fCohesionWeight = tag->getParam("CohesionWeight", "0").toFloat();
        fFlock.fCohesionRadius = tag->getParam("CohesionRadius", "0").toFloat();
        fFlock.fMaxForce = tag->getParam("MaxForce", "0").toFloat();
        fFlock.fMaxSpeed = tag->getParam("MaxSpeed", "0").toFloat();
        fFlock.fMinSpeed = tag->getParam("MinSpeed", "0").toFloat();
    } else {
        plSingleModifier::IPrcParse(tag, mgr);
    }
}
