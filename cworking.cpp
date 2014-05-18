#include "cworking.h"

CWorking::CWorking() : CBuilding()
{
}
CWorking::CWorking(const CWorking& _W) : CBuilding(_W)
{
    neededNumberOfWorkers = _W.getNeededNumberOfWorkers();
    actualNumberOfWorkers =_W.getActualNumberOfWorkers();
}
CWorking::CWorking(const CWorking& _W, CPeople _need, CPeople _actual) : CBuilding(_W)
{
    neededNumberOfWorkers = _need;
    actualNumberOfWorkers = _actual;
}

bool CWorking::addWorkers(CPeople _P)
{
    actualNumberOfWorkers += _P;
    //if after add, number is too high
    if(actualNumberOfWorkers.getLeadWorker() > neededNumberOfWorkers.getLeadWorker())
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getServiceWorker() > neededNumberOfWorkers.getServiceWorker())
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getLightWorker() > neededNumberOfWorkers.getLightWorker())
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getHeavyWorker() > neededNumberOfWorkers.getHeavyWorker())
    {
        actualNumberOfWorkers -= _P;
        return false;}
    if(actualNumberOfWorkers.getLowWorker() > neededNumberOfWorkers.getLowWorker())
    {
        actualNumberOfWorkers -= _P;
        return false;}

    return true;
}
double CWorking::countEfficiency() ///linear efficiency
{
    double _L = leadWorkerEff*actualNumberOfWorkers.getLeadWorker()+serviceWorkerEff*actualNumberOfWorkers.getServiceWorker()+
            lightWorkerEff*actualNumberOfWorkers.getLightWorker()+heavyWorkerEff*actualNumberOfWorkers.getHeavyWorker()+
            lowWorkerEff*actualNumberOfWorkers.getLowWorker();
    double _M = leadWorkerEff*neededNumberOfWorkers.getLeadWorker()+serviceWorkerEff*neededNumberOfWorkers.getServiceWorker()+
            lightWorkerEff*neededNumberOfWorkers.getLightWorker()+heavyWorkerEff*neededNumberOfWorkers.getHeavyWorker()+
            lowWorkerEff*neededNumberOfWorkers.getLowWorker();
    return _L/_M;
}

CPeople CWorking::getNeededNumberOfWorkers() const
{   return neededNumberOfWorkers;}
CPeople CWorking::getActualNumberOfWorkers() const
{   return actualNumberOfWorkers;}
void CWorking::setActualNumberOfWorkers(CPeople _P)
{   actualNumberOfWorkers =_P;}
void CWorking::setNeededNumberOfWorkers(CPeople _P)
{   neededNumberOfWorkers = _P;}
