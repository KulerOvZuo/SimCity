#include "cworking.h"

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
double CWorking::countPeopleEfficiency() ///linear efficiency
{
    double _L = leadWorkerEff*actualNumberOfWorkers.getLeadWorker()+serviceWorkerEff*actualNumberOfWorkers.getServiceWorker()+
            lightWorkerEff*actualNumberOfWorkers.getLightWorker()+heavyWorkerEff*actualNumberOfWorkers.getHeavyWorker()+
            lowWorkerEff*actualNumberOfWorkers.getLowWorker();
    double _M = leadWorkerEff*neededNumberOfWorkers.getLeadWorker()+serviceWorkerEff*neededNumberOfWorkers.getServiceWorker()+
            lightWorkerEff*neededNumberOfWorkers.getLightWorker()+heavyWorkerEff*neededNumberOfWorkers.getHeavyWorker()+
            lowWorkerEff*neededNumberOfWorkers.getLowWorker();
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
