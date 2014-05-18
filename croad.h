#ifndef CROAD_H
#define CROAD_H

#include "croadsandbridges.h"

class CRoad : public CRoadsAndBridges
{
protected:
public:
    CRoad();
    CRoad(const CRoad& _R);
};

class CRoadTurning : public CRoad
{
protected:
public:
    CRoadTurning();
    CRoadTurning(const CRoadTurning& _R);
};

class CRoadStraight : public CRoad
{
protected:
public:
    CRoadStraight();
    CRoadStraight(const CRoadStraight& _R);
};

class CRoadThreeWay : public CRoad
{
protected:
public:
    CRoadThreeWay();
    CRoadThreeWay(const CRoadThreeWay& _R);
};
class CRoadCross : public CRoad
{
protected:
public:
    CRoadCross();
    CRoadCross(const CRoadCross& _R);
};
#endif // CROAD_H
