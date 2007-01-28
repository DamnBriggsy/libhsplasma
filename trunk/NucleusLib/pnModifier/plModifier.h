#ifndef _PLMODIFIER_H
#define _PLMODIFIER_H

#include "../pnNetCommon/plSynchedObject.h"
#include "../pnSceneObject/plSceneObject.h"
#include "../../CoreLib/hsBitVector.h"

class plModifier : public plSynchedObject {
public:
    plModifier(PlasmaVer pv = pvUnknown);

    virtual short ClassIndex();
};


class plMultiModifier : public plModifier {
protected:
    hsTArray<plSceneObject*> targets;
    hsBitVector flags;

public:
    plMultiModifier(PlasmaVer pv = pvUnknown);

    virtual short ClassIndex();

    virtual void read(hsStream* S);
    virtual void write(hsStream* S);
};

#endif
