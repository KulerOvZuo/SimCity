#include "croadsandbridges.h"
#include "ccity.h"

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
bool CRoadsAndBridges::checkIfCanBeBuiled()
{
    if(CStructure::checkIfCanBeBuiled() == true) //place if free
    {   ///check if can be connected to nearly roads
        int x;
        int y;
        qDebug()<<"road building checking";
        for(int i=0; i<((city->getMapOfStructures())->getAllRoadsAndBridges()).count(); i++) //find roads next to this place
        {   x=(((city->getMapOfStructures())->getAllRoadsAndBridges()).at(i))->getCoordinatesOfActualLUCorner().getX();
            y=(((city->getMapOfStructures())->getAllRoadsAndBridges()).at(i))->getCoordinatesOfActualLUCorner().getY();
            if(coordinatesOfActualLUCorner.getX() == x && coordinatesOfActualLUCorner.getY()-1 ==y) //searched on the UP
            {   ///if this road and other nearly road cant be connected, return false
                if(directions.getDirUp() != (((city->getMapOfStructures())->getAllRoadsAndBridges()).at(i))->getDirections().getDirDown())
                    return false;
            }
            if(coordinatesOfActualLUCorner.getX()+1 == x && coordinatesOfActualLUCorner.getY() ==y) //searched on the RIGHT
            {   if(directions.getDirRight() != (((city->getMapOfStructures())->getAllRoadsAndBridges()).at(i))->getDirections().getDirLeft())
                    return false;
            }
            if(coordinatesOfActualLUCorner.getX() == x && coordinatesOfActualLUCorner.getY()+1 ==y) //searched on the DOWN
            {   if(directions.getDirDown() != (((city->getMapOfStructures())->getAllRoadsAndBridges()).at(i))->getDirections().getDirUp())
                    return false;
            }
            if(coordinatesOfActualLUCorner.getX()-1 == x && coordinatesOfActualLUCorner.getY() ==y) //searched on the LEFT
            {   if(directions.getDirLeft() != (((city->getMapOfStructures())->getAllRoadsAndBridges()).at(i))->getDirections().getDirRight())
                    return false;
            }
        }
        return true;
    }
    return false;
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
