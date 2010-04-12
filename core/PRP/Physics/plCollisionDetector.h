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

#ifndef _PLCOLLISIONDETECTOR_H
#define _PLCOLLISIONDETECTOR_H

#include "plDetectorModifier.h"

DllClass plCollisionDetector : public plDetectorModifier {
    CREATABLE(plCollisionDetector, kCollisionDetector, plDetectorModifier)

public:
    enum {
        kTypeEnter = 0x1,
        kTypeExit = 0x2,
        kTypeAny = 0x4,
        kTypeUnEnter = 0x8,
        kTypeUnExit = 0x10,
        kTypeBump = 0x20
    };

protected:
    unsigned char fType;

public:
    plCollisionDetector();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    unsigned char getType() const { return fType; }
    void setType(unsigned char type) { fType = type; }
};


DllClass plSubworldRegionDetector : public plCollisionDetector {
    CREATABLE(plSubworldRegionDetector, kSubworldRegionDetector,
              plCollisionDetector)

protected:
    plKey fSub;
    bool fOnExit;

public:
    plSubworldRegionDetector();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    plKey getSubworld() const { return fSub; }
    bool getOnExit() const { return fOnExit; }

    void setSubworld(plKey subworld) { fSub = subworld; }
    void setOnExit(bool onExit) { fOnExit = onExit; }
};


DllClass plPanicLinkRegion : public plCollisionDetector {
    CREATABLE(plPanicLinkRegion, kPanicLinkRegion, plCollisionDetector)

protected:
    bool fPlayLinkOutAnim;

public:
    plPanicLinkRegion();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    bool getPlayLinkOutAnim() const { return fPlayLinkOutAnim; }
    void setPlayLinkOutAnim(bool play) { fPlayLinkOutAnim = play; }
};

#endif
