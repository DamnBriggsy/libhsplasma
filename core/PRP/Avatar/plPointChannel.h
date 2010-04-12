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

#ifndef _PLPOINTCHANNEL_H
#define _PLPOINTCHANNEL_H

#include "plAGApplicator.h"
#include "PRP/Animation/plController.h"

/* Point Channels */
DllClass plPointChannel : public plAGChannel {
    CREATABLE(plPointChannel, kPointChannel, plAGChannel)

protected:
    hsVector3 fResult;

public:
    hsVector3 getResult() const { return fResult; }
    void setResult(const hsVector3& result) { fResult = result; }
};


DllClass plPointBlend : public plPointChannel {
    CREATABLE(plPointBlend, kPointBlend, plPointChannel)
};


DllClass plPointConstant : public plPointChannel {
    CREATABLE(plPointConstant, kPointConstant, plPointChannel)

public:
    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);
};


DllClass plPointControllerCacheChannel : public plPointChannel {
    CREATABLE(plPointControllerCacheChannel, kPointControllerCacheChannel,
              plPointChannel)
};


DllClass plPointControllerChannel : public plPointChannel {
    CREATABLE(plPointControllerChannel, kPointControllerChannel, plPointChannel)

protected:
    plController* fController;

public:
    plPointControllerChannel();
    virtual ~plPointControllerChannel();

    virtual void read(hsStream* S, plResManager* mgr);
    virtual void write(hsStream* S, plResManager* mgr);

protected:
    virtual void IPrcWrite(pfPrcHelper* prc);
    virtual void IPrcParse(const pfPrcTag* tag, plResManager* mgr);

public:
    plController* getController() const { return fController; }
    void setController(plController* controller);
};


DllClass plPointTimeScale : public plPointChannel {
    CREATABLE(plPointTimeScale, kPointTimeScale, plPointChannel)
};


/* Point Channel Applicators */
DllClass plPointChannelApplicator : public plAGApplicator {
    CREATABLE(plPointChannelApplicator, kPointChannelApplicator, plAGApplicator)
};

#endif
