#include "cservicebuilding.h"
#include "ccity.h"

CServiceBuilding::CServiceBuilding() : CWorking()
{
    listOfLivingNeeds.clear();
    baseService = CService(0);
    actualService = CService(0);
    income=0;
}
CServiceBuilding::CServiceBuilding(const CServiceBuilding& _S) : CWorking(_S)
{
    baseService = _S.getBaseService();
    actualService = _S.getActualService();
    baseServiceCost = _S.getBaseServiceCost();
    actualServiceCost = _S.getActualServiceCost();
    income = _S.getIncome();
    listOfLivingNeeds.clear();
}
CServiceBuilding::~CServiceBuilding()
{}

bool CServiceBuilding::addLivingTolist(CPeopleNeedsBuildingPointer* _living)
{   bool free = true;
    if(dynamic_cast<CLiving*>(_living->getBuilding()) == NULL)
        return false;
    for(int i=0; i<listOfLivingNeeds.count();i++ )
    {   if((listOfLivingNeeds.at(i)->getBuilding()) == _living->getBuilding())
        {   free = false;
            return false;}
    }
    if(free)
    {   listOfLivingNeeds.append(_living);
        serviceNeedFromPeople += _living->getPeopleNeeds().getServiceNeed();
    }
    return free;

}
void CServiceBuilding::clearListOfLivingNeeds()
{   for(int i=0; i<listOfLivingNeeds.count();i++)
    {   delete listOfLivingNeeds.at(i);}
    listOfLivingNeeds.clear();
}
void CServiceBuilding::clearTemporary()
{   this->clearListOfLivingNeeds();
    serviceNeedFromPeople = CService(0);
    money += income;
    income =0;
}
double CServiceBuilding::countBuildingEfficiency()
{
    double ratio = 2;
    if(baseService.getService1()>0)
    {   ratio = serviceNeedFromPeople.getService1()/baseService.getService1();}
    double multiply;
    if(ratio < 0.8) ///0-0.8 ratio
    {   multiply=1;}
    else
    {   if(ratio < 1.5)
            multiply = 1-(ratio-0.8);//*2/7;
        else
            multiply = 0.8;}

    return multiply*countPeopleEfficiency();
}
void CServiceBuilding::countSetServiceQuality()
{
    actualService = CService((baseService.getService1())*countBuildingEfficiency());
}
bool CServiceBuilding::giveServiceToLivings()
{   double service1Indicator = actualService.getService1()/serviceNeedFromPeople.getService1();
    for(int i=0; i<listOfLivingNeeds.count(); i++)
    {   CService _S;
        if(service1Indicator <= 1)
            _S = CService((listOfLivingNeeds.at(i)->getPeopleNeeds().getServiceNeed().getService1())*service1Indicator);
        else    //if some of service is not used
            _S = CService(listOfLivingNeeds.at(i)->getPeopleNeeds().getServiceNeed().getService1());
        dynamic_cast<CLiving*>(listOfLivingNeeds.at(i)->getBuilding())->takeServiceFromSB(_S,actualServiceCost);
        income += (_S.getService1()*actualServiceCost.getService1());
    }
    return true;
}
double CServiceBuilding::giveTaxes(double _tax)
{
    double tax = income * _tax/100;
    income -= tax;
    return tax;
}
void CServiceBuilding::countSetIncome()
{
    CPeopleEarnings _peopleEarn;
    _peopleEarn = city->getSocietyIndicators()->getPeopleEarnings();
    income -= (actualNumberOfWorkers.getLeadWorker()*_peopleEarn.getLeadWorkerEarn()+
        actualNumberOfWorkers.getLightWorker()*_peopleEarn.getLightWorkerEarn()+
        actualNumberOfWorkers.getServiceWorker()*_peopleEarn.getServiceWorkerEarn()+
        actualNumberOfWorkers.getHeavyWorker()*_peopleEarn.getHeavyWorkerEarn()+
        actualNumberOfWorkers.getLowWorker()*_peopleEarn.getLowWorkerEarn());
}
void CServiceBuilding::countSetActualServiceCost()
{   actualServiceCost=baseServiceCost;
}

CService CServiceBuilding::getBaseService() const
{ return baseService;}
CService CServiceBuilding::getActualService() const
{ return actualService;}
CService CServiceBuilding::getBaseServiceCost() const
{   return baseServiceCost;}
CService CServiceBuilding::getActualServiceCost() const
{   return actualServiceCost;}
double CServiceBuilding::getIncome() const
{   return income;}

void CServiceBuilding::setBaseService(CService _base)
{   baseService =_base;}
void CServiceBuilding::setActualService(CService _actual)
{   actualService = _actual;}
void CServiceBuilding::setBaseServiceCost(CService _base)
{   baseServiceCost = _base;}
void CServiceBuilding::setActualServiceCost(CService _actual)
{   actualServiceCost = _actual;}
void CServiceBuilding::setIncome(double _inc)
{   income =  _inc;}

///COffice
COffice::COffice() : CServiceBuilding()
{}
COffice::COffice(const COffice& _O): CServiceBuilding(_O)
{}
COffice::~COffice()
{}
