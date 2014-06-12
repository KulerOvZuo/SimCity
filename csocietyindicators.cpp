#include "csocietyindicators.h"

CSocietyIndicators::CSocietyIndicators() : IDisplayingInterface()
{
    birthIndicator=0;
    children=0;
}
CSocietyIndicators::CSocietyIndicators(const CSocietyIndicators& _I) : IDisplayingInterface()
{
    peopleEarnings =_I.getPeopleEarnings();
    allPeople = _I.getAllPeople();
    allLivingWorkingPeople = _I.getallLivingWorkingPeople();
    allLivingNotWorkingPeople = _I.getallLivingNotWorkingPeople();
    allWorkForPeople =_I.getAllWorkForPeople();
    allLearningPeople =_I.getAllLearningPeople();
    allProfessionsToEducate = _I.getAllProfessionsToEducate();
    children = _I.getChildren();
    birthIndicator =_I.getBirthIndicator();
}
CSocietyIndicators::~CSocietyIndicators()
{}

void CSocietyIndicators::clearTemporary()
{
    CPeople A;
    allPeople =A;
    allLivingWorkingPeople =A;
    allLivingNotWorkingPeople =A;
    allLearningPeople  =A;
    allWorkForPeople =A;
    allProfessionsToEducate  =A;
    children=0;
    birthIndicator=0;
}
CPeopleEarnings CSocietyIndicators::countSetPeopleEarnings()
{
    //value*(1 + 0.2*prof/profAre)
    CPeopleEarnings _earn(basePeopleEarnings);
    double ind;
    if(allPeople.getLeadWorker() >0)
    {   ind = (double)allWorkForPeople.getLeadWorker()/allPeople.getLeadWorker();
        if(ind > 2) //1.4
            ind =2;
        _earn.addLeadWorkerEarn((double)basePeopleEarnings.getLeadWorkerEarn()*0.2*ind);
    }
    if(allPeople.getServiceWorker() >0)
    {   ind = (double)allWorkForPeople.getServiceWorker()/allPeople.getServiceWorker();
        if(ind > 2) //1.4
            ind =2;
        _earn.addServiceWorkerEarn((double)basePeopleEarnings.getServiceWorkerEarn()*0.2*ind);
    }
    if(allPeople.getLightWorker() >0)
    {   ind = (double)allWorkForPeople.getLightWorker()/allPeople.getLightWorker();
        if(ind > 2) //1.4
            ind =2;
        _earn.addLightWorkerEarn((double)basePeopleEarnings.getLightWorkerEarn()*0.2*ind);
    }
    if(allPeople.getHeavyWorker() >0)
    {   ind = (double)allWorkForPeople.getHeavyWorker()/allPeople.getHeavyWorker();
        if(ind > 2) //1.4
            ind =2;
        _earn.addHeavyWorkerEarn((double)basePeopleEarnings.getHeavyWorkerEarn()*0.2*ind);
    }
    if(allPeople.getLowWorker() >0)
    {   ind = (double)allWorkForPeople.getLowWorker()/allPeople.getLowWorker();
        if(ind > 2) //1.4
            ind =2;
        _earn.addLowWorkerEarn((double)basePeopleEarnings.getLowWorkerEarn()*0.2*ind);
    }

    _earn.setLeadWorkerEarn(_earn.getLeadWorkerEarn()/2+peopleEarnings.getLeadWorkerEarn()/2);
    _earn.setServiceWorkerEarn(_earn.getServiceWorkerEarn()/2+peopleEarnings.getServiceWorkerEarn()/2);
    _earn.setLightWorkerEarn(_earn.getLightWorkerEarn()/2+peopleEarnings.getLightWorkerEarn()/2);
    _earn.setHeavyWorkerEarn(_earn.getHeavyWorkerEarn()/2+peopleEarnings.getHeavyWorkerEarn()/2);
    _earn.setLowWorkerEarn(_earn.getLowWorkerEarn()/2+peopleEarnings.getLowWorkerEarn()/2);
    peopleEarnings = _earn;
    return _earn;
}
CPeople CSocietyIndicators::countProffesionsNeed()
{
    //workFor - working - notWorking - learning
    int leadWorkerNeed = allWorkForPeople.getLeadWorker() - allLivingNotWorkingPeople.getLeadWorker() - allLivingWorkingPeople.getLeadWorker() - allLearningPeople.getLeadWorker();
    int lightWorkerNeed = allWorkForPeople.getLightWorker() - allLivingNotWorkingPeople.getLightWorker() - allLivingWorkingPeople.getLightWorker() - allLearningPeople.getLightWorker();
    int heavyWorkerNeed = allWorkForPeople.getHeavyWorker() - allLivingNotWorkingPeople.getHeavyWorker() - allLivingWorkingPeople.getHeavyWorker() - allLearningPeople.getHeavyWorker();
    int lowWorkerNeed = allWorkForPeople.getLowWorker() - allLivingNotWorkingPeople.getLowWorker() - allLivingWorkingPeople.getLowWorker() - allLearningPeople.getLowWorker();
    int serviceWorkerNeed = allWorkForPeople.getServiceWorker() - allLivingNotWorkingPeople.getServiceWorker() - allLivingWorkingPeople.getServiceWorker() - allLearningPeople.getServiceWorker();

    return CPeople(leadWorkerNeed,serviceWorkerNeed,lightWorkerNeed,heavyWorkerNeed,lowWorkerNeed);
}
CPeople CSocietyIndicators::countSetProffesionsToEducate()
{
    CPeople _profNeed(countProffesionsNeed());
    _profNeed.restoreIfNotPossitiveNOPeople();  // -need is not needed
    int _allProfNeed = _profNeed.getAllPeople();
    // children vs need
    if(_allProfNeed ==0)
    {
        CPeople A;
        int free = children-_allProfNeed;
        A.randomAdd(free);
        allProfessionsToEducate = A;
        return A;
    }
    double ratio = (double)children/_allProfNeed;

    if(ratio==0)
    {   return CPeople();}
    if(ratio==1)
    {   return CPeople(_profNeed);}
    if(ratio > 1) // all + random free
    {
        CPeople A(_profNeed);
        int free = children-_allProfNeed;
        A.randomAdd(free);
        allProfessionsToEducate = A;
        return A;
    }
    if(ratio < 1)
    {
        CPeople A;
        A.addLeadWorker(floor(ratio*_profNeed.getLeadWorker()));
        A.addServiceWorker(floor(ratio*_profNeed.getServiceWorker()));
        A.addLightWorker(floor(ratio*_profNeed.getLightWorker()));
        A.addHeavyWorker(floor(ratio*_profNeed.getHeavyWorker()));
        A.addLowWorker(floor(ratio*_profNeed.getLowWorker()));
        int free = children - A.getAllPeople(); //see whats left
        A.randomAdd(free);
        allProfessionsToEducate = A;
        return A;
    }
    allProfessionsToEducate = CPeople();
    return CPeople();
}

void CSocietyIndicators::addChildren(int _children)
{   children += _children;}
void CSocietyIndicators::addBirthIndicator(double _birth)
{   birthIndicator += _birth;}


CPeopleEarnings CSocietyIndicators::getPeopleEarnings() const
{   return peopleEarnings;}
CPeopleEarnings CSocietyIndicators::getBasePeopleEarnings() const
{   return basePeopleEarnings; }
CPeople CSocietyIndicators::getAllPeople() const
{   return allPeople;}
CPeople CSocietyIndicators::getallLivingWorkingPeople() const
{   return allLivingWorkingPeople;}
CPeople CSocietyIndicators::getallLivingNotWorkingPeople() const
{   return allLivingNotWorkingPeople;}
CPeople CSocietyIndicators::getAllWorkForPeople() const
{   return allWorkForPeople;}
CPeople CSocietyIndicators::getAllLearningPeople() const
{   return allLearningPeople;}
CPeople CSocietyIndicators::getAllProfessionsToEducate() const
{   return allProfessionsToEducate;}
int CSocietyIndicators::getChildren() const
{   return children;}
double CSocietyIndicators::getBirthIndicator() const
{   return birthIndicator;}

void CSocietyIndicators::setPeopleEarnings(CPeopleEarnings _earn)
{   peopleEarnings = _earn; }
void CSocietyIndicators::setBasePeopleEarnings(CPeopleEarnings _earn)
{   basePeopleEarnings = _earn;}
void CSocietyIndicators::setAllPeople(CPeople _people)
{   allPeople = _people;}
void CSocietyIndicators::setAllLivingWorkingPeople(CPeople _people)
{   allLivingWorkingPeople = _people;}
void CSocietyIndicators::setAllLivingNotWorkingPeople(CPeople _people)
{   allLivingNotWorkingPeople = _people;}
void CSocietyIndicators::setAllWorkForPeople(CPeople _people)
{   allWorkForPeople = _people;}
void CSocietyIndicators::setAllLearningPeople(CPeople _people)
{   allLearningPeople = _people;}
void CSocietyIndicators::setAllProfessionsToEducate(CPeople _people)
{   allProfessionsToEducate = _people;}
void CSocietyIndicators::setChildren(int _children)
{   children = _children;}
void CSocietyIndicators::setBirthIndicator(double _birth)
{   birthIndicator = _birth;}
