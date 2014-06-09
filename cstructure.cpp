#include "cstructure.h"
#include "ccity.h"

CStructure::CStructure() :
    age(0), name("none"), buildCost(0), destroyCost(0), costPerTick(0), sizeOnGameMap(), coordinatesOfActualLUCorner(),
    turnedDirection(CDirections()), graphic(NULL), city(NULL)
{
   /* qDebug()<<age<<name<<buildCost<<destroyCost<<costPerTick<<sizeOnGameMap.getX()<<coordinatesOfLUCorner.getY()
           <<static_cast<direction>(turnedDirection)<<city;*/

}
CStructure::CStructure(int age, QString name, double buildCost,double destroyCost,
           double costPerTick, CCoordinates sizeOnGameMap, CCoordinates coordinatesOfLUCorner,
           CDirections turnedDirection) :
             age(age), name(name), buildCost(buildCost), destroyCost(destroyCost), costPerTick(costPerTick), sizeOnGameMap(sizeOnGameMap), coordinatesOfActualLUCorner(coordinatesOfLUCorner),
             turnedDirection(turnedDirection)

{}
CStructure::CStructure(const CStructure &_S)
{
    age =_S.getAge();
    name = _S.getName();
    buildCost = _S.getBuildCost();
    destroyCost = _S.getDestroyCost();
    costPerTick = _S.getCostPerTick();
    sizeOnGameMap = _S.getSizeOnGameMap();
    coordinatesOfActualLUCorner =_S.getCoordinatesOfActualLUCorner();
    turnedDirection = _S.getTurnedDirection();
    graphic = _S.getGraphic();
    city=_S.getCity();
}
CStructure::~CStructure()
{}

bool CStructure::build()
{
    bool** _map = city->getMapOfStructures()->getMapOfTakenPlaces();
    ///starts in coordinates, going y--, x++
    for(int y=coordinatesOfActualLUCorner.getY(); y>coordinatesOfActualLUCorner.getY()+sizeOnGameMap.getY();y--)
    {   for(int x=coordinatesOfActualLUCorner.getX(); x<coordinatesOfActualLUCorner.getX()+sizeOnGameMap.getX();x++)
        {   _map[x][y] = true; //take place
        }
    }
    return true;}
bool CStructure::checkIfCanBeBuiled() const
{
    bool** _map = city->getMapOfStructures()->getMapOfTakenPlaces();
    if(_map==NULL)
        return false;
    CCoordinates _size = city->getMapOfStructures()->getMapSize();
    ///starts in coordinates, going y++, x++
    for(int y=coordinatesOfActualLUCorner.getY(); y<coordinatesOfActualLUCorner.getY()+sizeOnGameMap.getY();y++)
    {   ///map sizes
        if(y>=_size.getY())
            return false;
        if(y<0)
            return false;
        for(int x=coordinatesOfActualLUCorner.getX(); x<coordinatesOfActualLUCorner.getX()+sizeOnGameMap.getX();x++)
        {   ///map sizes
            if(x >=_size.getX())
                return false;
            if(x<0)
                return false;
            if(_map[x][y] == true) //taken place
                return false; //cant be builed
        }
    }
///if ended here, structure can be placed
    return true;
}
double CStructure::distanceToOther(CStructure* other) const
{
    double x = this->countCoordinatesOfCentre().getX() - other->countCoordinatesOfCentre().getX();
    double y = this->countCoordinatesOfCentre().getY() - other->countCoordinatesOfCentre().getY();
    return sqrt(x*x+y*y);
}
bool CStructure::rotate(Erotation rotateAngle)
{
    turnedDirection.rotate(rotateAngle);
    if(0)//turnedDirection.getDirUp()==true) //basic or reverse
    {   ///do nothing
        return true;}
    else
    {   sizeOnGameMap.setCoordinates(sizeOnGameMap.getY(),sizeOnGameMap.getX()); //changes x->-y; y->-x
        return true;
    }
   return false;
}
CCoordinates CStructure::countCoordinatesOfCentre() const
{
    CCoordinates _temp(coordinatesOfActualLUCorner);
    _temp += CCoordinates(sizeOnGameMap.getX()/2,sizeOnGameMap.getY()/2);
    return _temp;
}

void CStructure::addAge(int _age)
{   age += _age;}
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
    sizeOnGameMap.setX(abs(_C.getX())); //always x>0;
    sizeOnGameMap.setY(abs(_C.getY())); //always y<0
    return true;
}
bool CStructure::setCoordinatesOfActualLUCorner(const CCoordinates& _C)
{   coordinatesOfActualLUCorner = _C;
    return true;
}
bool CStructure::setTurnedDirection(CDirections _dir)
{   turnedDirection = _dir;
    return true;
}
bool CStructure::setGraphic(CGraphic *_graphic)
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
CCoordinates CStructure::getCoordinatesOfActualLUCorner() const
{return coordinatesOfActualLUCorner;}
CDirections CStructure::getTurnedDirection() const
{return turnedDirection;}
CGraphic* CStructure::getGraphic() const
{return graphic;}
CCity* CStructure::getCity() const
{   return city;}
