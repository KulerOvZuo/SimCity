#ifndef CGREENTERRAIN_H
#define CGREENTERRAIN_H

#include "cstructureforpeople.h"

class CGreenTerrain : public CStructureForPeople
{
protected:
    double disturbance;
public:
    CGreenTerrain();
    CGreenTerrain(const CGreenTerrain& _G);
    virtual QList<QString> infoToDisplay();

    bool setDisturbance(double _dist);
    double getDisturbance() const;
};

class CPark : public CGreenTerrain
{
public:
    CPark();
    CPark(const CPark& _P);
    virtual bool setRandomName(int size);
};

class CLawn : public CGreenTerrain
{
public:
    CLawn();
    CLawn(const CLawn& _L);
    virtual bool setRandomName(int size);
};
#endif // CGREENTERRAIN_H
