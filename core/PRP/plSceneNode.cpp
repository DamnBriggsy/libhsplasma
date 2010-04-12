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

#include "plSceneNode.h"

void plSceneNode::read(hsStream* S, plResManager* mgr) {
    hsKeyedObject::read(S, mgr);

    fSceneObjects.setSize(S->readInt());
    for (size_t i=0; i<fSceneObjects.getSize(); i++)
        fSceneObjects[i] = mgr->readKey(S);
    fPoolObjects.setSize(S->readInt());
    for (size_t i=0; i<fPoolObjects.getSize(); i++)
        fPoolObjects[i] = mgr->readKey(S);
}

void plSceneNode::write(hsStream* S, plResManager* mgr) {
    hsKeyedObject::write(S, mgr);

    S->writeInt(fSceneObjects.getSize());
    for (size_t i=0; i<fSceneObjects.getSize(); i++)
        mgr->writeKey(S, fSceneObjects[i]);
    S->writeInt(fPoolObjects.getSize());
    for (size_t i=0; i<fPoolObjects.getSize(); i++)
        mgr->writeKey(S, fPoolObjects[i]);
}

void plSceneNode::IPrcWrite(pfPrcHelper* prc) {
    hsKeyedObject::IPrcWrite(prc);

    prc->writeSimpleTag("SceneObjects");
    for (size_t i=0; i<fSceneObjects.getSize(); i++)
        fSceneObjects[i]->prcWrite(prc);
    prc->closeTag();
    prc->writeSimpleTag("PoolObjects");
    for (size_t i=0; i<fPoolObjects.getSize(); i++)
        fPoolObjects[i]->prcWrite(prc);
    prc->closeTag();
}

void plSceneNode::IPrcParse(const pfPrcTag* tag, plResManager* mgr) {
    if (tag->getName() == "SceneObjects") {
        fSceneObjects.setSize(tag->countChildren());
        const pfPrcTag* child = tag->getFirstChild();
        for (size_t i=0; i<fSceneObjects.getSize(); i++) {
            fSceneObjects[i] = mgr->prcParseKey(child);
            child = child->getNextSibling();
        }
    } else if (tag->getName() == "PoolObjects") {
        fPoolObjects.setSize(tag->countChildren());
        const pfPrcTag* child = tag->getFirstChild();
        for (size_t i=0; i<fPoolObjects.getSize(); i++) {
            fPoolObjects[i] = mgr->prcParseKey(child);
            child = child->getNextSibling();
        }
    } else {
        hsKeyedObject::IPrcParse(tag, mgr);
    }
}
