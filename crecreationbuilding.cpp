#include "crecreationbuilding.h"

CRecreationBuilding::CRecreationBuilding() : CWorking()
{
    maxNOCustomers =0;
    actualNOCustomers=0;
    baseRecreation = CRecreation(0);
    actualRecreation = CRecreation(0);
}
CRecreationBuilding::CRecreationBuilding(const CRecreationBuilding& _R) : CWorking(_R)
{
    maxNOCustomers = _R.getMaxNOCustomers();
    actualNOCustomers=_R.getActualNOCustomers();
    baseRecreation = _R.getBaseRecreation();
    actualRecreation = _R.getActualRecreation();
}
CRecreationBuilding::~CRecreationBuilding()
{}

double CRecreationBuilding::countBuildingEfficiency()
{
    double ratio = actualNOCustomers/maxNOCustomers;
    double multiply;
    if(ratio < 0.8) ///0-0.8 ratio
    {   multiply=1;}
    else
    {   if(ratio < 1.5)
            multiply = 1-(ratio-0.8);
        else
            multiply = 0.3;}

    return multiply*countPeopleEfficiency();
}
void CRecreationBuilding::countSetRecreationQuality()
{
    actualRecreation = CRecreation((baseRecreation.getRecreation1())*countBuildingEfficiency());
}
bool CRecreationBuilding::addCustomers(int _number)
{   actualNOCustomers += _number;
    if(actualNOCustomers<0)
    {   actualNOCustomers=0;
        return false;}
    return true;
}

int CRecreationBuilding::getMaxNOCustomers() const
{ return maxNOCustomers;}
int CRecreationBuilding::getActualNOCustomers() const
{ return actualNOCustomers;}
CRecreation CRecreationBuilding::getBaseRecreation() const
{ return baseRecreation;}
CRecreation CRecreationBuilding::getActualRecreation() const
{ return actualRecreation;}

void CRecreationBuilding::setMaxNOCustomers(int _max)
{   maxNOCustomers = _max;}
void CRecreationBuilding::setActualNOCustomers(int _actual)
{   actualNOCustomers = _actual;}
void CRecreationBuilding::setBaseRecreation(CRecreation _base)
{   baseRecreation =_base;}
void CRecreationBuilding::setActualRecreation(CRecreation _actual)
{   actualRecreation = _actual;}


///CCinema
CCinema::CCinema() : CRecreationBuilding()
{}
CCinema::CCinema(const CCinema& _C): CRecreationBuilding(_C)
{}
CCinema::~CCinema()
{}
