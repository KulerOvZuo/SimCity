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
CTaxes::~CTaxes()
{}
int CTaxes::getFromProductionInd() const
{   return fromProductionInd;}
int CTaxes::getFromPeopleInd() const
{   return fromPeopleInd;}
int CTaxes::getFromOthersInd() const
{   return fromOthersInd;}
void CTaxes::setFromProductionInd(int _num)
{   fromProductionInd=_num;}
void CTaxes::setFromPeopleInd(int _num)
{   fromPeopleInd=_num;}
void CTaxes::setFromOthersInd(int _num)
{   fromOthersInd=_num;}
