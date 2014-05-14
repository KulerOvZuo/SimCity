#include "croad.h"

CRoad::CRoad() : CRoadsAndBridges()
{
    onWater = false;
}

CRoadTurning::CRoadTurning() : CRoad()
{
    this->setDirections(CDirections(true,true,false,false));
}

CRoadThreeWay::CRoadThreeWay() : CRoad()
{
    this->setDirections(CDirections(true,true,false,true));
}

CRoadCross::CRoadCross() : CRoad()
{
    this->setDirections(CDirections(true,true,true,true));
}
