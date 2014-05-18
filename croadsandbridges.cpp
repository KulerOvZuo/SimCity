#include "croadsandbridges.h"

CRoadsAndBridges::CRoadsAndBridges() : CStructure(), capacity(0), onWater(false)
{
    directions = CDirections(true,false,true,false);
}
CRoadsAndBridges::CRoadsAndBridges(double _capacity,bool _water,CDirections _dir)
{
    capacity = _capacity;
    onWater = _water;
    directions = _dir;
}
CRoadsAndBridges::CRoadsAndBridges(const CRoadsAndBridges& _R) : CStructure(_R)
{
    capacity=_R.getCapacity();
    onWater=_R.getOnWater();
    directions =_R.getDirections();
}


bool CRoadsAndBridges::rotate(Erotation rotateAngle)
{
    CStructure::rotate(rotateAngle);
    return directions.rotate(rotateAngle);
}

void CRoadsAndBridges::setAllRoadAndBridges(double _capacity,bool _water,CDirections _dir)
{
    capacity = _capacity;
    onWater = _water;
    directions = _dir;
}
bool CRoadsAndBridges::setOnWater(bool _water)
{   onWater = _water;
    return true;
}
bool CRoadsAndBridges::setCapacity(double _capacity)
{   capacity = _capacity;
    return true;
}
bool CRoadsAndBridges::setDirections(CDirections _dir)
{
    directions = _dir;
    return true;
}


double CRoadsAndBridges::getCapacity() const
{ return capacity;}
bool CRoadsAndBridges::getOnWater() const
{ return onWater;}
CDirections CRoadsAndBridges::getDirections() const
{
    return directions;
}
