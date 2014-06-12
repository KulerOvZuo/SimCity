#include "cutilitiesglobal.h"

CUtilitiesGlobal::CUtilitiesGlobal()
{
    electricity=0;
    water=0;
    dump=0;
}
CUtilitiesGlobal::CUtilitiesGlobal(const CUtilitiesGlobal& _U)
{
    electricity=_U.getElectricity();
    water=_U.getWater();
    dump=_U.getDump();
}
CUtilitiesGlobal::CUtilitiesGlobal(double _electricity,double _water,double _dump) : electricity(_electricity),water(_water),dump(_dump)
{}
CUtilitiesGlobal CUtilitiesGlobal::operator+ (CUtilitiesGlobal _U)
{
    return CUtilitiesGlobal(electricity+_U.getElectricity(),water+_U.getWater(),dump+_U.getWater());
}
CUtilitiesGlobal& CUtilitiesGlobal::operator+= (CUtilitiesGlobal const &_U)
{
    this->electricity += _U.getElectricity();
    this->water += _U.getWater();
    this->dump += _U.getDump();
    return *this;
}
CUtilitiesGlobal& CUtilitiesGlobal::operator-= (CUtilitiesGlobal const &_U)
{
    this->electricity -= _U.getElectricity();
    this->water -= _U.getWater();
    this->dump -= _U.getDump();
    return *this;
}
void CUtilitiesGlobal::setElectricity(double _electr)
{ electricity=_electr;
}
void CUtilitiesGlobal::setWater(double _water)
{ water=_water;
}
void CUtilitiesGlobal::setDump(double _dump)
{ dump=_dump;
}

double CUtilitiesGlobal::getElectricity() const
{ return electricity;}
double CUtilitiesGlobal::getWater() const
{ return water;}
double CUtilitiesGlobal::getDump() const
{ return dump;}
