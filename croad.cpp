#include "croad.h"

CRoad::CRoad() : CRoadsAndBridges()
{
    onWater = false;
}
CRoad::CRoad(const CRoad& _R) : CRoadsAndBridges(_R)
{   onWater = _R.getOnWater();}

CRoadTurning::CRoadTurning() : CRoad()
{
    this->setDirections(CDirections(true,true,false,false));
}
CRoadTurning::CRoadTurning(const CRoadTurning& _R) : CRoad(_R)
{
    directions = _R.getDirections();
}

CRoadStraight::CRoadStraight(): CRoad()
{}
CRoadStraight::CRoadStraight(const CRoadStraight &_R) : CRoad(_R)
{}

CRoadThreeWay::CRoadThreeWay() : CRoad()
{
    this->setDirections(CDirections(true,true,false,true));
}
CRoadThreeWay::CRoadThreeWay(const CRoadThreeWay& _R): CRoad(_R)
{
    directions = _R.getDirections();
}

CRoadCross::CRoadCross() : CRoad()
{
    this->setDirections(CDirections(true,true,true,true));
}
CRoadCross::CRoadCross(const CRoadCross& _R) : CRoad(_R)
{
    directions = _R.getDirections();
}
