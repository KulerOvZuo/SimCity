#include "cservicebuilding.h"

CServiceBuilding::CServiceBuilding() : CWorking()
{
    maxNOCustomers =0;
    actualNOCustomers=0;
    baseService = CService(0);
    actualService = CService(0);
}
CServiceBuilding::CServiceBuilding(const CServiceBuilding& _S) : CWorking(_S)
{
    maxNOCustomers = _S.getMaxNOCustomers();
    actualNOCustomers=_S.getActualNOCustomers();
    baseService = _S.getBaseService();
    actualService = _S.getActualService();
}
CServiceBuilding::~CServiceBuilding()
{}

double CServiceBuilding::countBuildingEfficiency()
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
void CServiceBuilding::countSetServiceQuality()
{
    actualService = CService((baseService.getService1())*countBuildingEfficiency());
}
bool CServiceBuilding::addCustomers(int _number)
{   actualNOCustomers += _number;
    if(actualNOCustomers<0)
    {   actualNOCustomers=0;
        return false;}
    return true;
}

int CServiceBuilding::getMaxNOCustomers() const
{ return maxNOCustomers;}
int CServiceBuilding::getActualNOCustomers() const
{ return actualNOCustomers;}
CService CServiceBuilding::getBaseService() const
{ return baseService;}
CService CServiceBuilding::getActualService() const
{ return actualService;}

void CServiceBuilding::setMaxNOCustomers(int _max)
{   maxNOCustomers = _max;}
void CServiceBuilding::setActualNOCustomers(int _actual)
{   actualNOCustomers = _actual;}
void CServiceBuilding::setBaseService(CService _base)
{   baseService =_base;}
void CServiceBuilding::setActualService(CService _actual)
{   actualService = _actual;}


///COffice
COffice::COffice() : CServiceBuilding()
{}
COffice::COffice(const COffice& _O): CServiceBuilding(_O)
{}
COffice::~COffice()
{}
