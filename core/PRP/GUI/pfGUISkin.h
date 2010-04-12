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

#ifndef _PFGUISKIN_H
#define _PFGUISKIN_H

#include "PRP/KeyedObject/hsKeyedObject.h"

DllClass pfGUISkin : public hsKeyedObject {
    CREATABLE(pfGUISkin, kGUISkin, hsKeyedObject)

public:
    enum Elements {
        kUpLeftCorner, kTopSpan, kUpRightCorner, kRightSpan, kLowerRightCorner,
        kBottomSpan, kLowerLeftCorner, kLeftSpan, kMiddleFill, kSelectedFill,
        kSubMenuArrow, kSelectedSubMenuArrow, kTreeButtonClosed,
        kTreeButtonOpen, kNumElements
    };

    DllStruct pfSRect {
        unsigned short fX, fY, fWidth, fHeight;

        pfSRect();
        void read(hsStream* S);
        void write(hsStream* S);
        void prcWrite(pfPrcHelper* prc);
        void prcParse(const pfPrcTag* tag);
        void clear();
    };

protected:
    plKey fTexture;
    pfSRect fElements[kNumElements];
    unsigned short fItemMargin, fBorderMargin;

public:
    pfGUISkin();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    const pfSRect& getElement(size_t which) const { return fElements[which]; }
    pfSRect& getElement(size_t which) { return fElements[which]; }

    plKey getTexture() const { return fTexture; }
    unsigned short getItemMargin() const { return fItemMargin; }
    unsigned short getBorderMargin() const { return fBorderMargin; }

    void setTexture(plKey tex) { fTexture = tex; }
    void setItemMargin(unsigned short margin) { fItemMargin = margin; }
    void setBorderMargin(unsigned short margin) { fBorderMargin = margin; }
};

#endif
