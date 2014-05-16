#include "cstructure.h"

CStructure::CStructure() :
    age(0), name("none"), buildCost(0), destroyCost(0), costPerTick(0), sizeOnGameMap(), coordinatesOfCentre(),
    turnedDirection(CDirections()), graphic(), city(NULL)
{
   /* qDebug()<<age<<name<<buildCost<<destroyCost<<costPerTick<<sizeOnGameMap.getX()<<coordinatesOfCentre.getY()
           <<static_cast<direction>(turnedDirection)<<city;*/

}
CStructure::CStructure(int age, QString name, double buildCost,double destroyCost,
           double costPerTick, CCoordinates sizeOnGameMap, CCoordinates coordinatesOfCentre,
           CDirections turnedDirection) :
             age(age), name(name), buildCost(buildCost), destroyCost(destroyCost), costPerTick(costPerTick), sizeOnGameMap(sizeOnGameMap), coordinatesOfCentre(coordinatesOfCentre),
             turnedDirection(turnedDirection)

{}
CStructure::~CStructure()
{}

bool CStructure::rotate(Erotation rotateAngle)
{
    turnedDirection.rotate(rotateAngle);
    return true;
}

///setters
bool CStructure::setAge(int _age)
{   age = _age;
    return true;
}
bool CStructure::setName(QString _name)
{   name=_name;
    return true;
}
bool CStructure::setBuildCost(double _cost)
{   buildCost=_cost;
            return true;
}
bool CStructure::setDestroyCost(double _cost)
{   destroyCost=_cost;
    return true;
}
bool CStructure::setCostPerTick(double _cost)
{   costPerTick=_cost;
    return true;
}
bool CStructure::setSizeOnGameMap(const CCoordinates& _C)
{
    sizeOnGameMap = _C;
    return true;
}
bool CStructure::setCoordinatesOfCentre(const CCoordinates& _C)
{   coordinatesOfCentre = _C;
    return true;
}
bool CStructure::setTurnedDirection(CDirections _dir)
{   turnedDirection = _dir;
    return true;
}
bool CStructure::setGraphic(CGraphic _graphic)
{   graphic = _graphic;
    return true;}
bool CStructure::setCity(CCity* _city)
{   if(_city!=NULL)
    {   city = _city;
        return true;}
    else
        return false;
}

///getters
int CStructure::getAge() const
{ return age;}
QString CStructure::getName() const
{return name;}
double CStructure::getBuildCost() const
{return buildCost;}
double CStructure::getDestroyCost() const
{return destroyCost;}
double CStructure::getCostPerTick() const
{return costPerTick;}
CCoordinates CStructure::getSizeOnGameMap() const
{return sizeOnGameMap;}
CCoordinates CStructure::getCoordinatesOfCentre() const
{return coordinatesOfCentre;}
CDirections CStructure::getTurnedDirection() const
{return turnedDirection;}
CGraphic CStructure::getGraphic() const
{return graphic;}
