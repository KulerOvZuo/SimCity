#include "ctaxes.h"

CTaxes::CTaxes()
{
    fromProductionInd=0;
    fromPeopleInd=0;
    fromOthersInd=0;
}

CTaxes::CTaxes(const CTaxes& _T)
{
    fromProductionInd = _T.getFromProductionInd();
    fromPeopleInd =_T.getFromPeopleInd();
    fromOthersInd =_T.getFromOthersInd();
}
double CTaxes::getFromProductionInd() const
{   return fromProductionInd;}
double CTaxes::getFromPeopleInd() const
{   return fromPeopleInd;}
double CTaxes::getFromOthersInd() const
{   return fromOthersInd;}
void CTaxes::setFromProductionInd(double _num)
{   fromProductionInd=_num;}
void CTaxes::setFromPeopleInd(double _num)
{   fromPeopleInd=_num;}
void CTaxes::setFromOthersInd(double _num)
{   fromOthersInd=_num;}
