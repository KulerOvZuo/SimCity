#ifndef CGREENTERRAIN_H
#define CGREENTERRAIN_H

#include "cstructureforpeople.h"

class CGreenTerrain : public CStructureForPeople
{
protected:
    double disturbance;
public:
    CGreenTerrain();

    bool setDisturbance(double _dist);
    double getDisturbance() const;
};

class CPark : public CGreenTerrain
{
public:
    CPark();

};

class CLawn : public CGreenTerrain
{
public:
    CLawn();
};
#endif // CGREENTERRAIN_H
