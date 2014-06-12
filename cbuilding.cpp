#include "cbuilding.h"
#include "ccity.h"

CBuilding::CBuilding() : CStructureForPeople()
{
    money = 0;
}
CBuilding::CBuilding(const CBuilding& _B) : CStructureForPeople(_B)
{
    money = _B.getMoney();
    utilities = _B.getUtilities();
}
CBuilding::CBuilding(double _money, CUtilitiesGlobal _U) : CStructureForPeople()
{
    money = _money;
    utilities = _U;
}
CBuilding::~CBuilding()
{}
QList<QString> CBuilding::infoToDisplay()
{
    QList<QString> info;
    info.clear();
    info.append(CStructure::infoToDisplay());
    info.append(QString("Money: %1$").arg(money,1,'f',2));
    info.append(QString("Utilities:\ndump: %1\nwater: %2\nelectricity: %3").
                arg(utilities.getDump(),1).
                arg(utilities.getWater(),1).
                arg(utilities.getElectricity(),1));
    return info;
}

bool CBuilding::sendUtilitiesToCity()
{
    city->addUtilitiesGlobalNeed(utilities);
    return true;}
double CBuilding::countIncome()
{
    return 0;}
bool CBuilding::sendTaxes()
{ return true;}
void CBuilding::clearTemporary()
{}
bool CBuilding::addMoney(double _money)
{
    money +=_money;
    return true;
}
bool CBuilding::setMoney(double _money)
{   money=_money;
    return true;
}
bool CBuilding::setUtilities(CUtilitiesGlobal _U)
{   utilities = _U;
    return true;
}
double CBuilding::getMoney() const
{ return money;}
CUtilitiesGlobal CBuilding::getUtilities() const
{ return utilities;}


//class
CProductsBuildingPointer::CProductsBuildingPointer()
{
    building = NULL;
}
CProductsBuildingPointer::CProductsBuildingPointer(const CProductsBuildingPointer& _PB)
{
    products = _PB.getProducts();
    building = _PB.getBuilding();
}
CProductsBuildingPointer::~CProductsBuildingPointer()
{}

CProducts CProductsBuildingPointer::getProducts() const
{   return products;}
CBuilding* CProductsBuildingPointer::getBuilding() const
{  return building;}

void CProductsBuildingPointer::setProducts(CProducts _prod)
{   products=_prod;}
void CProductsBuildingPointer::setBuilding(CBuilding* _building)
{   building =_building;}

//class
CPeopleNeedsBuildingPointer::CPeopleNeedsBuildingPointer()
{building = NULL;}
CPeopleNeedsBuildingPointer::CPeopleNeedsBuildingPointer(const CPeopleNeedsBuildingPointer& _PB)
{
    peopleNeeds = _PB.getPeopleNeeds();
    building = _PB.getBuilding();
}
CPeopleNeedsBuildingPointer::~CPeopleNeedsBuildingPointer()
{}

CPeopleNeeds CPeopleNeedsBuildingPointer::getPeopleNeeds() const
{   return peopleNeeds;}
CBuilding* CPeopleNeedsBuildingPointer::getBuilding() const
{   return building;}

void CPeopleNeedsBuildingPointer::setPeopleNeeds(CPeopleNeeds _peopleNeeds)
{   peopleNeeds = _peopleNeeds;}
void CPeopleNeedsBuildingPointer::setBuilding(CBuilding* _building)
{   building = _building;}
