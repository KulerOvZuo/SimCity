#include "cbuilding.h"

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
