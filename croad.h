#ifndef CROAD_H
#define CROAD_H

#include "croadsandbridges.h"

class CRoad : public CRoadsAndBridges
{
protected:
public:
    CRoad();
};

class CRoadTurning : public CRoad
{
protected:
public:
    CRoadTurning();
};

class CRoadStraight : public CRoad
{
protected:
public:
    CRoadStraight();
};

class CRoadThreeWay : public CRoad
{
protected:
public:
    CRoadThreeWay();
};
class CRoadCross : public CRoad
{
protected:
public:
    CRoadCross();
};
#endif // CROAD_H
