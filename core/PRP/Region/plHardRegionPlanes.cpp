#include "plHardRegionPlanes.h"

/* plHardRegionPlanes::HardPlane */
plHardRegionPlanes::HardPlane::HardPlane() { }
plHardRegionPlanes::HardPlane::~HardPlane() { }

void plHardRegionPlanes::HardPlane::read(hsStream* S) {
    fNorm.read(S);
    fPos.read(S);
    fWorldNorm.read(S);
    fWorldPos.read(S);
}

void plHardRegionPlanes::HardPlane::write(hsStream* S) {
    fNorm.write(S);
    fPos.write(S);
    fWorldNorm.write(S);
    fWorldPos.write(S);
}

void plHardRegionPlanes::HardPlane::prcWrite(pfPrcHelper* prc) {
    prc->writeSimpleTag("HardPlane");

    prc->writeSimpleTag("Normal");
    fNorm.prcWrite(prc);
    prc->closeTag();
    prc->writeSimpleTag("Position");
    fPos.prcWrite(prc);
    prc->closeTag();
    prc->writeSimpleTag("WorldNormal");
    fWorldNorm.prcWrite(prc);
    prc->closeTag();
    prc->writeSimpleTag("WorldPosition");
    fWorldPos.prcWrite(prc);
    prc->closeTag();

    prc->closeTag();
}

void plHardRegionPlanes::HardPlane::prcParse(const pfPrcTag* tag) {
    if (tag->getName() != "HardPlane")
        throw pfPrcTagException(__FILE__, __LINE__, tag->getName());

    const pfPrcTag* child = tag->getFirstChild();
    while (child != NULL) {
        if (child->getName() == "Normal") {
            if (child->hasChildren())
                fNorm.prcParse(child->getFirstChild());
        } else if (child->getName() == "Position") {
            if (child->hasChildren())
                fPos.prcParse(child->getFirstChild());
        } else if (child->getName() == "WorldNormal") {
            if (child->hasChildren())
                fWorldNorm.prcParse(child->getFirstChild());
        } else if (child->getName() == "WorldPosition") {
            if (child->hasChildren())
                fWorldPos.prcParse(child->getFirstChild());
        } else {
            throw pfPrcTagException(__FILE__, __LINE__, child->getName());
        }
        child = child->getNextSibling();
    }
}

float plHardRegionPlanes::HardPlane::getWorldDist() const {
    return (fWorldPos.X * fWorldNorm.X) +
           (fWorldPos.Y * fWorldNorm.Y) +
           (fWorldPos.Z * fWorldNorm.Z);
}


/* plHardRegionPlanes */
plHardRegionPlanes::plHardRegionPlanes() { }
plHardRegionPlanes::~plHardRegionPlanes() { }

IMPLEMENT_CREATABLE(plHardRegionPlanes, kHardRegionPlanes, plHardRegion)

void plHardRegionPlanes::read(hsStream* S, plResManager* mgr) {
    plHardRegion::read(S, mgr);

    fPlanes.setSize(S->readInt());
    for (size_t i=0; i<fPlanes.getSize(); i++)
        fPlanes[i].read(S);
}

void plHardRegionPlanes::write(hsStream* S, plResManager* mgr) {
    plHardRegion::write(S, mgr);

    S->writeInt(fPlanes.getSize());
    for (size_t i=0; i<fPlanes.getSize(); i++)
        fPlanes[i].write(S);
}

void plHardRegionPlanes::IPrcWrite(pfPrcHelper* prc) {
    plHardRegion::IPrcWrite(prc);

    prc->writeSimpleTag("Planes");
    for (size_t i=0; i<fPlanes.getSize(); i++)
        fPlanes[i].prcWrite(prc);
    prc->closeTag();
}

void plHardRegionPlanes::IPrcParse(const pfPrcTag* tag, plResManager* mgr) {
    if (tag->getName() == "Planes") {
        fPlanes.setSize(tag->countChildren());
        const pfPrcTag* child = tag->getFirstChild();
        for (size_t i=0; i<fPlanes.getSize(); i++) {
            fPlanes[i].prcParse(child);
            child = child->getNextSibling();
        }
    } else {
        plHardRegion::IPrcParse(tag, mgr);
    }
}
