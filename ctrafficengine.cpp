#include "ctrafficengine.h"
#include "ccity.h"

CTrafficEngine::CTrafficEngine()
{
    city=NULL;
}
CTrafficEngine::CTrafficEngine(const CTrafficEngine& _T)
{   Q_UNUSED(_T);
}
CTrafficEngine::~CTrafficEngine()
{}
void CTrafficEngine::setCity(CCity* _city)
{   city=_city;}
bool CTrafficEngine::createMapOfTraffic()
{
    CCoordinates _size = city->getMapOfStructures()->getMapSize();
    ///optimal size of squares is trafficSquare
    CCoordinates _C;
    _C.setX((int)_size.getX()/trafficSquare);
    _C.setY((int)_size.getY()/trafficSquare);
    if(_C.getX()<1)
        _C.setX(1);
    if(_C.getY()<1)
        _C.setY(1);
    double **map = new double*[(int)_C.getX()];
    for(int x=0; x<_C.getX(); x++)
    {   map[x] = new double[(int)_C.getY()];}
    for(int x=0; x<_C.getX(); x++)
    {   for(int y=0; y<_C.getY(); y++)
        {   map[x][y] = 0;}
    }
    sizeofSimplifiedMap = _C;
    simplifiedMapOfTraffic = map;
    return true;
}

double CTrafficEngine::giveTrafficInfo(CCoordinates _C) const
{   int x = _C.getX()/trafficSquare;
    int y = _C.getY()/trafficSquare;
    return simplifiedMapOfTraffic[x][y];
}
void CTrafficEngine::countTraffic()
{   clearTemporary();
    CCoordinates _size = city->getMapOfStructures()->getMapSize();
    int x =sizeofSimplifiedMap.getX();
    int y =sizeofSimplifiedMap.getY();
    double _temp[x][y]; //used for count quantity of people
    ///[1]count traffic
    for(int _y=0; _y<y; _y++)
        for(int _x=0; _x<x;_x++)
            _temp[_x][_y] =0;
    int _x;
    int _y;
    //living
    for(int i=0; i<city->getMapOfStructures()->getAllLivings().count();i++)
    {   CCoordinates _C = city->getMapOfStructures()->getAllLivings().at(i)->countCoordinatesOfCentre();
        double _traff = (city->getMapOfStructures()->getAllLivings().at(i)->getAllPeopleLiving());
        ///add to proper square
        _x=_C.getX()/trafficSquare;
        _y=_C.getY()/trafficSquare;
        _temp[_x][_y] += _traff;
    }
    //production
    for(int i=0; i<city->getMapOfStructures()->getAllProductionBuildings().count();i++)
    {  CCoordinates _C = city->getMapOfStructures()->getAllProductionBuildings().at(i)->countCoordinatesOfCentre();
        double _traff = (city->getMapOfStructures()->getAllProductionBuildings().at(i))->getActualNumberOfWorkers().getAllPeople();
        ///add to proper square
        _x=_C.getX()/trafficSquare;
        _y=_C.getY()/trafficSquare;
        _temp[_x][_y] += _traff;
    }
    //shop
    for(int i=0; i<city->getMapOfStructures()->getAllShops().count();i++)
    {  CCoordinates _C = city->getMapOfStructures()->getAllShops().at(i)->countCoordinatesOfCentre();
        double _traff = (city->getMapOfStructures()->getAllShops().at(i))->getActualNumberOfWorkers().getAllPeople();
        ///add to proper square
        _x=_C.getX()/trafficSquare;
        _y=_C.getY()/trafficSquare;
        _temp[_x][_y] += _traff;
    }
    //service
    for(int i=0; i<city->getMapOfStructures()->getAllServiceBuildings().count();i++)
    {  CCoordinates _C = city->getMapOfStructures()->getAllServiceBuildings().at(i)->countCoordinatesOfCentre();
        double _traff = (city->getMapOfStructures()->getAllServiceBuildings().at(i))->getActualNumberOfWorkers().getAllPeople();
        ///add to proper square
        _x=_C.getX()/trafficSquare;
        _y=_C.getY()/trafficSquare;
        _temp[_x][_y] += _traff;
    }
    ///[/1]
    ///[2] count capacity
    for(int i=0; i<city->getMapOfStructures()->getAllRoadsAndBridges().count();i++)
    {  CCoordinates _C = city->getMapOfStructures()->getAllRoadsAndBridges().at(i)->countCoordinatesOfCentre();
        double _capacity = (city->getMapOfStructures()->getAllRoadsAndBridges().at(i))->getCapacity();
        ///add to proper square
        _x=_C.getX()/trafficSquare;
        _y=_C.getY()/trafficSquare;
        simplifiedMapOfTraffic[_x][_y] += _capacity;
    }
    ///[/2]
    ///[3] count actual traffic
    double _traffic;
    for(int y=0; y<sizeofSimplifiedMap.getY();y++)
        for(int x=0; x<sizeofSimplifiedMap.getX();x++)
        {   if(_temp[x][y] <=0) //not used square
                _traffic = 10;
            else
                _traffic = simplifiedMapOfTraffic[x][y]/_temp[x][y];
            simplifiedMapOfTraffic[x][y] = _traffic;}
    ///[/3]
}
void CTrafficEngine::clearTemporary()
{   for(int y=0; y<sizeofSimplifiedMap.getY(); y++)
    {   for(int x=0; x<sizeofSimplifiedMap.getX(); x++)
        {  simplifiedMapOfTraffic[x][y] = 0;}
    }
}
