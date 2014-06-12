#include "cstructure.h"
#include "ccity.h"
#include "QFile"
#include <QTextStream>

CStructure::CStructure() :
    age(0), name("none"), buildCost(0), destroyCost(0), costPerTick(0), sizeOnGameMap(), coordinatesOfActualLUCorner(),
    turnedDirection(CDirections()), city(NULL)
{

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
    city=_S.getCity();
}
CStructure::~CStructure()
{}

bool CStructure::build()
{
    city->addMoney(-1*buildCost);
    bool** _map = city->getMapOfStructures()->getMapOfTakenPlaces();
    //starts in coordinates, going y--, x++
    for(int y=coordinatesOfActualLUCorner.getY(); y<coordinatesOfActualLUCorner.getY()+sizeOnGameMap.getY();y++)
    {   for(int x=coordinatesOfActualLUCorner.getX(); x<coordinatesOfActualLUCorner.getX()+sizeOnGameMap.getX();x++)
        {   _map[x][y] = true; //take place
            //qDebug()<<_map[x][y];
        }
    }
    return true;}
bool CStructure::destroy()
{
    city->addMoney(-1*destroyCost);
    bool** _map = city->getMapOfStructures()->getMapOfTakenPlaces();
    //starts in coordinates, going y--, x++
    for(int y=coordinatesOfActualLUCorner.getY(); y<coordinatesOfActualLUCorner.getY()+sizeOnGameMap.getY();y++)
    {   for(int x=coordinatesOfActualLUCorner.getX(); x<coordinatesOfActualLUCorner.getX()+sizeOnGameMap.getX();x++)
        {   _map[x][y] = false; //take place
            //qDebug()<<_map[x][y];
        }
    }
    return true;
}
QList<QString> CStructure::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(QString("Name: %1").arg(name,1));
    info.append(QString("Age: %1").arg(age,1));
    info.append(QString("Destroy cost: %1$").arg(destroyCost,1,'f',2));
    return info;
}
bool CStructure::checkIfCanBeBuiled() const
{
    bool** _map = city->getMapOfStructures()->getMapOfTakenPlaces();
    if(_map==NULL)
        return false;
    CCoordinates _size = city->getMapOfStructures()->getMapSize();
    //starts in coordinates, going y++, x++
    for(int y=coordinatesOfActualLUCorner.getY(); y<coordinatesOfActualLUCorner.getY()+sizeOnGameMap.getY();y++)
    {   //map sizes
        if(y>=_size.getY())
            return false;
        if(y<0)
            return false;
        for(int x=coordinatesOfActualLUCorner.getX(); x<coordinatesOfActualLUCorner.getX()+sizeOnGameMap.getX();x++)
        {   //map sizes
            if(x >=_size.getX())
                return false;
            if(x<0)
                return false;
            if(_map[x][y] == true) //taken place
                return false; //cant be builed
        }
    }
//if ended here, structure can be placed
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
    {   //do nothing
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
//setters
bool CStructure::setAge(int _age)
{   age = _age;
    return true;
}
bool CStructure::setName(QString _name)
{   name=_name;
    return true;
}
bool CStructure::setRandomName(int size)
{   QString _name;
    QFile myFile(namesFilePath);
    //[1]
    if(!myFile.open(QIODevice::ReadOnly))
        return false;
    QTextStream text(&myFile);
    int lines=0;
    while(!text.atEnd())
    {   QString line = text.readLine(20);
        lines++;}
    myFile.close();
    //[2]
    for(int i=0; i<size;i++)
    {   if(!myFile.open(QIODevice::ReadOnly))
            return false;
        QTextStream _text(&myFile);
        CPeople people;
        int number = people.randBetween(1,lines-1);
        QString line;
        for(int num=0; num<number;num++)
        {   line = _text.readLine();}
        _name.append(line);
        _name.append(" ");
        myFile.close();
        if(size>=3 && i%3 ==1)
            _name.append("\n");
    }
    name = _name;
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
bool CStructure::setCity(CCity* _city)
{   if(_city!=NULL)
    {   city = _city;
        return true;}
    else
        return false;
}

//getters
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
CCity* CStructure::getCity() const
{   return city;}
