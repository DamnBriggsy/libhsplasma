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

#ifndef _PLGEOMETRYSPAN_H
#define _PLGEOMETRYSPAN_H

#include "Util/hsTArray.hpp"
#include "PRP/Surface/hsGMaterial.h"
#include "Math/hsMatrix44.h"
#include "PRP/Misc/plFogEnvironment.h"
#include "PRP/Region/hsBounds.h"
#include "Sys/hsColor.h"
#include "Math/hsGeometry3.h"

DllClass plGeometrySpan {
public:
    enum {
        kMaxNumUVChannels = 8
    };

    enum Formats {
        kUVCountMask = 0xF,
        kSkinNoWeights = 0x0,
        kSkin1Weight = 0x10,
        kSkin2Weights = 0x20,
        kSkin3Weights = 0x30,
        kSkinWeightMask = 0x30,
        kSkinIndices = 0x40
    };

    enum Properties {
        kLiteMaterial = 0x0,
        kPropRunTimeLight = 0x1,
        kPropNoPreShade = 0x2,
        kLiteVtxPreshaded = 0x4,
        kLiteVtxNonPreshaded = 0x8,
        kLiteMask = 0xC,
        kRequiresBlending = 0x10,
        kInstanced = 0x20,
        kUserOwned = 0x40,
        kPropNoShadow = 0x80,
        kPropForceShadow = 0x100,
        kDiffuseFoldedIn = 0x200,
        kPropReverseSort = 0x400,
        kWaterHeight = 0x800,
        kFirstInstance = 0x1000,
        kPartialSort = 0x2000,
        kVisLOS = 0x4000,
        kPropNoShadowCast = 0x8000
    };

    enum {
        kNoGroupID = 0
    };

    DllStruct TempVertex {
        hsVector3 fPosition, fNormal;
        unsigned int fColor, fSpecularColor;
        hsColorRGBA fMultColor, fAddColor;
        hsVector3 fUVs[8];
        float fWeights[3];
        unsigned int fIndices;
    };

protected:
    plKey fMaterial, fFogEnviron;
    hsMatrix44 fLocalToWorld, fWorldToLocal;
    hsBounds3Ext fLocalBounds, fWorldBounds;
    unsigned int fFormat, fNumMatrices;
    unsigned int fBaseMatrix;
    unsigned short fLocalUVWChans, fMaxBoneIdx;
    unsigned int fPenBoneIdx;
    float fMinDist, fMaxDist;
    float fWaterHeight;
    unsigned int fProps;
    unsigned int fNumVerts, fNumIndices;
    unsigned char* fVertexData;
    unsigned short* fIndexData;
    unsigned int fDecalLevel;
    hsColorRGBA* fMultColor;
    hsColorRGBA* fAddColor;
    unsigned int* fDiffuseRGBA;
    unsigned int* fSpecularRGBA;
    unsigned int fInstanceGroup;
    hsMatrix44 fLocalToOBB, fOBBToLocal;

    unsigned int numInstanceRefs;

public:
    plGeometrySpan();
    ~plGeometrySpan();

    static unsigned int CalcVertexSize(unsigned char format);

    void read(hsStream* S);
    void write(hsStream* S);
    void prcWrite(pfPrcHelper* prc);
    void prcParse(const pfPrcTag* tag);

    void setMaterial(plKey mat) { fMaterial = mat; }
    void setFogEnvironment(plKey fog) { fFogEnviron = fog; }

    hsTArray<TempVertex> getVertices() const;
    void setVertices(const hsTArray<TempVertex>& verts);
    hsTArray<unsigned short> getIndices() const;
    void setIndices(const hsTArray<unsigned short>& indices);
};

#endif
