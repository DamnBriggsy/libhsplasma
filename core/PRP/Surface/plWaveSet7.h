#ifndef _PLWAVESET7_H
#define _PLWAVESET7_H

#include "plWaveSetBase.h"
#include "plFixedWaterState7.h"

DllClass plWaveSet7 : public plWaveSetBase {
public:
    enum { kHasRefObject = 0x10 };

protected:
    plFixedWaterState7 fState;
    float fMaxLen;
    hsTArray<plKey> fShores, fDecals;
    plKey fEnvMap, fRefObj;

public:
    plWaveSet7();
    virtual ~plWaveSet7();

    DECLARE_CREATABLE(plWaveSet7)

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};

#endif
