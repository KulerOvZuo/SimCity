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
    sizeOnGameMap = CCoordinates(1,1);
}
CRoadTurning::CRoadTurning(const CRoadTurning& _R) : CRoad(_R)
{
    directions = _R.getDirections();
    sizeOnGameMap = _R.getSizeOnGameMap();
}

CRoadStraight::CRoadStraight(): CRoad()
{
    sizeOnGameMap = CCoordinates(1,1);
}
CRoadStraight::CRoadStraight(const CRoadStraight &_R) : CRoad(_R)
{
    sizeOnGameMap = _R.getSizeOnGameMap();
}

CRoadThreeWay::CRoadThreeWay() : CRoad()
{
    this->setDirections(CDirections(true,true,false,true));
    sizeOnGameMap = CCoordinates(1,1);
}
CRoadThreeWay::CRoadThreeWay(const CRoadThreeWay& _R): CRoad(_R)
{
    directions = _R.getDirections();
    sizeOnGameMap = _R.getSizeOnGameMap();
}

CRoadCross::CRoadCross() : CRoad()
{
    this->setDirections(CDirections(true,true,true,true));
    sizeOnGameMap = CCoordinates(1,1);
}
CRoadCross::CRoadCross(const CRoadCross& _R) : CRoad(_R)
{
    directions = _R.getDirections();
    sizeOnGameMap = _R.getSizeOnGameMap();
}
