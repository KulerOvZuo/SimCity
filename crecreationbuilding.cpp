#include "crecreationbuilding.h"

CRecreationBuilding::CRecreationBuilding() : CWorking()
{
    baseRecreation = CRecreation(0);
    actualRecreation = CRecreation(0);
}
CRecreationBuilding::CRecreationBuilding(const CRecreationBuilding& _R) : CWorking(_R)
{
    baseRecreation = _R.getBaseRecreation();
    actualRecreation = _R.getActualRecreation();
}
CRecreationBuilding::~CRecreationBuilding()
{}

double CRecreationBuilding::countBuildingEfficiency()
{
    double ratio = 0.5;
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
    actualRecreation =  CRecreation(((baseRecreation.getRecreation1())*countBuildingEfficiency())/2+actualRecreation.getRecreation1()/2);
}

CRecreation CRecreationBuilding::getBaseRecreation() const
{ return baseRecreation;}
CRecreation CRecreationBuilding::getActualRecreation() const
{ return actualRecreation;}

void CRecreationBuilding::setBaseRecreation(CRecreation _base)
{   baseRecreation =_base;}
void CRecreationBuilding::setActualRecreation(CRecreation _actual)
{   actualRecreation = _actual;}


///CCinema
CCinema::CCinema() : CRecreationBuilding()
{   sizeOnGameMap = CCoordinates(3,2);}
CCinema::CCinema(const CCinema& _C): CRecreationBuilding(_C)
{   sizeOnGameMap = _C.getSizeOnGameMap();}
CCinema::~CCinema()
{}
