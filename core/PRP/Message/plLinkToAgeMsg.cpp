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

#include "plLinkToAgeMsg.h"
#include "Debug/plDebug.h"

/* plLinkToAgeMsg */
plLinkToAgeMsg::plLinkToAgeMsg() : fStreamVersion(0), fEoaUnknown(0) { }

void plLinkToAgeMsg::read(hsStream* S, plResManager* mgr) {
    plMessage::read(S, mgr);

    if (S->getVer() < pvEoa)
        fStreamVersion = S->readByte();
    else
        fStreamVersion = 0;
    if (fStreamVersion != 0)
        plDebug::Debug("Got plLinkToAgeMsg StreamVersion %u", fStreamVersion);
    fAgeLink.read(S, mgr);
    fLinkEffects.read(S);
    if (S->getVer() >= pvEoa)
        fEoaUnknown = S->readByte();
}

void plLinkToAgeMsg::write(hsStream* S, plResManager* mgr) {
    plMessage::write(S, mgr);

    if (S->getVer() < pvEoa)
        S->writeByte(fStreamVersion);
    fAgeLink.write(S, mgr);
    fLinkEffects.write(S);
    if (S->getVer() >= pvEoa)
        S->writeByte(fEoaUnknown);
}

void plLinkToAgeMsg::IPrcWrite(pfPrcHelper* prc) {
    plMessage::IPrcWrite(prc);

    fAgeLink.prcWrite(prc);
    fLinkEffects.prcWrite(prc);

    prc->startTag("EoaUnknown");
    prc->writeParamHex("value", (unsigned char)fEoaUnknown);
    prc->endTag(true);
}

void plLinkToAgeMsg::IPrcParse(const pfPrcTag* tag, plResManager* mgr) {
    if (tag->getName() == "plAgeLinkStruct") {
        fAgeLink.prcParse(tag, mgr);
    } else if (tag->getName() == "plAgeLinkEffects") {
        fLinkEffects.prcParse(tag);
    } else if (tag->getName() == "EoaUnknown") {
        fEoaUnknown = tag->getParam("value", "0").toUint();
    } else {
        plMessage::IPrcParse(tag, mgr);
    }
}
