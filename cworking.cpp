#include "cworking.h"
#include "ccity.h"

CWorking::CWorking() : CBuilding()
{
}
CWorking::CWorking(const CWorking& _W) : CBuilding(_W)
{
    neededNumberOfWorkers = _W.getNeededNumberOfWorkers();
    actualNumberOfWorkers =_W.getActualNumberOfWorkers();

    neededNumberOfWorkers.restoreIfNotPossitiveNOPeople();
    actualNumberOfWorkers.restoreIfNotPossitiveNOPeople();
}
CWorking::CWorking(const CWorking& _W, CPeople _need, CPeople _actual) : CBuilding(_W)
{
    neededNumberOfWorkers = _need;
    actualNumberOfWorkers = _actual;

    neededNumberOfWorkers.restoreIfNotPossitiveNOPeople();
    actualNumberOfWorkers.restoreIfNotPossitiveNOPeople();
}
CWorking::~CWorking()
{
}
bool CWorking::destroy()
{   CPeople people = actualNumberOfWorkers;
    int max = city->getMapOfStructures()->getAllLivings().count();
    int all = people.getAllPeople();
    int counter =5*all;
    while(counter>0 && all>0)
    {   int number = people.randBetween(0,max-1);
        CPeople extract;
        extract = people.randomExtract(1);
        if(extract.getAllPeople()!=0)
        {   CPeople working = city->getMapOfStructures()->getAllLivings().at(number)->getLivingNotWorkingPeople();
            working +=extract;
            CPeople notWorking = city->getMapOfStructures()->getAllLivings().at(number)->getLivingWorkingPeople();
            notWorking -= extract;
            city->getMapOfStructures()->getAllLivings().at(number)->setLivingNotWorkingPeople(working);
            city->getMapOfStructures()->getAllLivings().at(number)->setLivingWorkingPeople(notWorking);
            all--;}
        counter--;
    }
    CStructure::destroy();
    return true;
}

void CWorking::sendWorkInfoToCity()
{
    CPeople A = city->getSocietyIndicators()->getAllWorkForPeople();
    A += neededNumberOfWorkers;
    city->getSocietyIndicators()->setAllWorkForPeople(A);
}
QList<QString> CWorking::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CBuilding::infoToDisplay());
    info.append(QString("Needed number of workers:\nLead workers: %1\nService workers: %2\nLight workers: %3\nHeavy workers: %4\nLow workers: %5").
                arg(neededNumberOfWorkers.getLeadWorker(),1).
                arg(neededNumberOfWorkers.getServiceWorker(),1).
                arg(neededNumberOfWorkers.getLightWorker(),1).
                arg(neededNumberOfWorkers.getHeavyWorker(),1).
                arg(neededNumberOfWorkers.getLowWorker(),1));
    info.append(QString("Actual number of workers:\nLead workers: %1\nService workers: %2\nLight workers: %3\nHeavy workers: %4\nLow workers: %5").
                arg(actualNumberOfWorkers.getLeadWorker(),1).
                arg(actualNumberOfWorkers.getServiceWorker(),1).
                arg(actualNumberOfWorkers.getLightWorker(),1).
                arg(actualNumberOfWorkers.getHeavyWorker(),1).
                arg(actualNumberOfWorkers.getLowWorker(),1));
    return info;
}

bool CWorking::addWorkers(CPeople _P)
{
    actualNumberOfWorkers += _P;
    //if after add, number is too high
    if(actualNumberOfWorkers.getLeadWorker() > neededNumberOfWorkers.getLeadWorker() || actualNumberOfWorkers.getLeadWorker() <0)
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getServiceWorker() > neededNumberOfWorkers.getServiceWorker() || actualNumberOfWorkers.getServiceWorker() <0)
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getLightWorker() > neededNumberOfWorkers.getLightWorker() || actualNumberOfWorkers.getLightWorker() <0)
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getHeavyWorker() > neededNumberOfWorkers.getHeavyWorker() || actualNumberOfWorkers.getHeavyWorker() <0)
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getLowWorker() > neededNumberOfWorkers.getLowWorker() || actualNumberOfWorkers.getLowWorker() <0)
    {
        actualNumberOfWorkers -= _P;
        return false;}

    return actualNumberOfWorkers.restoreIfNotPossitiveNOPeople();
}
double CWorking::countPeopleEfficiency() //linear efficiency
{
    double _L = leadWorkerEff*actualNumberOfWorkers.getLeadWorker()+serviceWorkerEff*actualNumberOfWorkers.getServiceWorker()+
            lightWorkerEff*actualNumberOfWorkers.getLightWorker()+heavyWorkerEff*actualNumberOfWorkers.getHeavyWorker()+
            lowWorkerEff*actualNumberOfWorkers.getLowWorker();
    double _M = leadWorkerEff*neededNumberOfWorkers.getLeadWorker()+serviceWorkerEff*neededNumberOfWorkers.getServiceWorker()+
            lightWorkerEff*neededNumberOfWorkers.getLightWorker()+heavyWorkerEff*neededNumberOfWorkers.getHeavyWorker()+
            lowWorkerEff*neededNumberOfWorkers.getLowWorker();
    if(_L==0 || _M == 0)
        return 0;
    return _L/_M;
}
double CWorking::countBuildingEfficiency()
{   return -1;}
CPeople CWorking::getNeededNumberOfWorkers() const
{   return neededNumberOfWorkers;}
CPeople CWorking::getActualNumberOfWorkers() const
{   return actualNumberOfWorkers;}
bool CWorking::setActualNumberOfWorkers(CPeople _P)
{   CPeople _temp = actualNumberOfWorkers;
    actualNumberOfWorkers = CPeople();
    bool _good = addWorkers(_P);
    if(_good == false) //if setting was not proper
        actualNumberOfWorkers = _temp; // back to old
    return _good;}
bool CWorking::setNeededNumberOfWorkers(CPeople _P)
{   neededNumberOfWorkers = _P;
    return neededNumberOfWorkers.restoreIfNotPossitiveNOPeople();}
