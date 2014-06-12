#include "cservicebuilding.h"
#include "ccity.h"

CServiceBuilding::CServiceBuilding() : CWorking()
{
    listOfLivingNeeds.clear();
    baseService = CService(0);
    actualService = CService(0);
    income=0;
    setRandomName(3);
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
QList<QString> CServiceBuilding::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CWorking::infoToDisplay());
    info.append(QString("Income: %1$").arg(income,1,'f',2));
    info.append(QString("Base service: %1$\nActual service: %2$").
                arg(baseService.getService1(),1,'f',2).
                arg(actualService.getService1(),1,'f',2));
    info.append(QString("Base service cost: %1$\nActual service cost: %2$").
                arg(baseServiceCost.getService1(),1,'f',2).
                arg(actualServiceCost.getService1(),1,'f',2));
    return info;
}
bool CServiceBuilding::setRandomName(int size)
{  Q_UNUSED(size);
    CStructure::setRandomName(3);
return true;}

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
    if(ratio < 0.8) //0-0.8 ratio
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
    actualService = CService(((baseService.getService1())*countBuildingEfficiency()+actualService.getService1())/2);
}
bool CServiceBuilding::giveServiceToLivings()
{   double service1Indicator;
    if(serviceNeedFromPeople.getService1()!=0)
        service1Indicator = actualService.getService1()/serviceNeedFromPeople.getService1();
    else
        return false;
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
    if(income <0)
        return 0;
    double tax = income * _tax/100;
    income -= tax;
    return tax;
}
void CServiceBuilding::payWorkers()
{
    CPeopleEarnings _peopleEarn;
    _peopleEarn = city->getSocietyIndicators()->getPeopleEarnings();
    income -= (actualNumberOfWorkers.getLeadWorker()*_peopleEarn.getLeadWorkerEarn()+
        actualNumberOfWorkers.getLightWorker()*_peopleEarn.getLightWorkerEarn()+
        actualNumberOfWorkers.getServiceWorker()*_peopleEarn.getServiceWorkerEarn()+
        actualNumberOfWorkers.getHeavyWorker()*_peopleEarn.getHeavyWorkerEarn()+
        actualNumberOfWorkers.getLowWorker()*_peopleEarn.getLowWorkerEarn())/2;
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

//COffice
COffice::COffice() : CServiceBuilding()
{   sizeOnGameMap = CCoordinates(2,3);}
COffice::COffice(const COffice& _O): CServiceBuilding(_O)
{   sizeOnGameMap = _O.getSizeOnGameMap();}
COffice::~COffice()
{}
