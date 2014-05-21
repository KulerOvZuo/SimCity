#include "cliving.h"

CLiving::CLiving() : CBuilding(),schoolConnected(NULL)
{
    maxLivingPeople=0;
    children=0;
    birthRate=0;
    income=0;
    lifeSatisfaction=0;
    learningPeopleList.clear();
}
CLiving::CLiving(const CLiving& _L) : CBuilding(_L)
{
    maxLivingPeople=_L.getMaxLivingPeople();
    livingWorkingPeople = _L.getLivingWorkingPeople();
    livingNotWorkingPeople = _L.getLivingNotWorkingPeople();
    learningPeopleList = _L.getListOfLearningPeople();
    children=_L.getChildren();
    birthRate=_L.getBirthRate();
    income=_L.getIncome();
    lifeSatisfaction=_L.getLifeSatisfaction();
    schoolConnected = _L.getSchool();
    peopleNeeds =_L.getPeopleNeeds();
}
CLiving::~CLiving()
{
    learningPeopleList.clear();
}

double CLiving::countSetBirthRate()
{   double _birth= -0.5 + lifeSatisfaction*1;
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople();
    birthRate = _birth*_allPeople;
    return _birth;
}
CPeopleNeeds CLiving::countPeopleNeeds()
{
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople()+children;
    for(int i=0; i<learningPeopleList.count(); i++)
    {
        _allPeople += (learningPeopleList.at(i)).getAllPeople();
    }
    double _food=1+0.6*lifeSatisfaction;
    _food *= _allPeople;
    double _light=0.5+1*lifeSatisfaction;
    _light*= _allPeople;
    double _heavy=0.5+0.8*lifeSatisfaction;
    _heavy*= _allPeople;
    double _serv1=0.5+1*lifeSatisfaction;
    _serv1*= _allPeople;
    double _rec1=0.5+1*lifeSatisfaction;
    _rec1*= _allPeople;

    double _disturbance=1+0.4*lifeSatisfaction;
    double _traffic=2+0.3*lifeSatisfaction;
    //for all people in building
    return CPeopleNeeds(CProducts(_light,_heavy,_food),CService(_serv1),CRecreation(_rec1),_traffic,_disturbance);
}
double CLiving::countLifeSatisfaction()
{
    double _pastLifeSat = lifeSatisfaction;
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople()+children;
    for(int i=0; i<learningPeopleList.count(); i++)
    {
        _allPeople += (learningPeopleList.at(i)).getAllPeople();
    }
    double lifeSat;
    int aInc=1;
    if(income<0)
        aInc=-1;
    double aDist=1;
    if(peopleNeeds.getDisturbance()<0)
        aDist=-1;
    if(peopleNeeds.getTraffic()<1)
        peopleNeeds.setTraffic(1);
    if(abs(peopleNeeds.getDisturbance())<1)
        peopleNeeds.setDistrurbance(1);
    if(abs(income)<1)
        income=1;
    double _rec1= (peopleNeeds.getRecreationNeed()).getRecreation1()/_allPeople;
    if(_rec1<1)
        _rec1=1;
    double _food=(peopleNeeds.getProductsNeed()).getFood()/_allPeople;
    if(_food<1)
        _food=1;
    double _light= (peopleNeeds.getProductsNeed()).getLight()/_allPeople;
    if(_light<1)
        _light=1;
    double _heavy = (peopleNeeds.getProductsNeed()).getHeavy()/_allPeople;
    if(_heavy<1)
        _heavy=1;
    double _service= (peopleNeeds.getServiceNeed()).getService1()/_allPeople;
    if(_service<1)
        _service=1;

    lifeSat = (1+0.2*(trafficInd*log10(peopleNeeds.getTraffic())+aDist*disturbanceInd*log10(abs(peopleNeeds.getDisturbance()))+
                             recreationInd*log10(_rec1)+foodInd*log10(_food)+
                             lightInd*log10(_light)+heavyInd*log10(_heavy)+
                         serviceInd*log10(_service)+aInc*incomeInd*log10(abs(income/_allPeople))));
    return (3*_pastLifeSat+lifeSat)/4;
}

//list
void CLiving::addNewLearningPeople(CPeople _professions)
{
    learningPeopleList.append(CLearningPeople(_professions,0,0,0,0,0));
}
void CLiving::clearListOfLearningPeople()
{
    learningPeopleList.clear();

}
void CLiving::optimizeListOfLearningPeople()
{
    int _i;
    int _end = learningPeopleList.count();
    for(_i=0; _i < _end; _i++)
    {   if(learningPeopleList[_i].getAllPeople() <=0)
        {   learningPeopleList.removeAt(_i); //remove
            _end = learningPeopleList.count();  //count number of values
            _i += -1; //start searching from same point
        }
    }
}
void CLiving::educatePeople(double _educationIndicator)
{
    for(int i=0; i<learningPeopleList.size(); i++)
    {
        learningPeopleList[i].addAllEducation(_educationIndicator);
    }
}

CPeople CLiving::extractEducatedPeople()
{
    CPeople _P;
    for(int i=0; i<learningPeopleList.size(); i++)
    {   //extract educated people
        _P += learningPeopleList[i].extractWhoIsEducated();
    }
    return _P;
}
CPeople CLiving::getNumberOfLearningPeople()
{
    CPeople _P;
    for(int i=0; i<learningPeopleList.size(); i++)
    {   //add all learning people
        _P += learningPeopleList[i];
    }
    return _P;
}

void CLiving::setMaxLivingPeople(int _max)
{   maxLivingPeople = _max;}
void CLiving::setLivingWorkingPeople(CPeople _P)
{   livingWorkingPeople = _P;}
void CLiving::setLivingNotWorkingPeople(CPeople _P)
{   livingNotWorkingPeople = _P;}
void CLiving::setChildren(int _children)
{   children = _children;}
void CLiving::setIncome(int _income)
{   income = _income;}
void CLiving::setLifeSatisfaction( double _lifeSat)
{  lifeSatisfaction=_lifeSat; }
bool CLiving::setSchool(CSchool* _school)
{   schoolConnected = _school;
    if(_school == NULL)
        return false;
    return true;
}
void CLiving::setPeopleNeeds(CPeopleNeeds _P)
{   peopleNeeds = _P;}

int CLiving::getMaxLivingPeople()const
{ return maxLivingPeople;}
CPeople CLiving::getLivingWorkingPeople()const
{ return livingWorkingPeople;}
CPeople CLiving::getLivingNotWorkingPeople()const
{   return livingNotWorkingPeople;}
QList<CLearningPeople> CLiving::getListOfLearningPeople() const
{ return learningPeopleList;}
int CLiving::getChildren()const
{ return children;}
double CLiving::getBirthRate() const
{ return birthRate;}
double CLiving::getIncome()const
{   return income;}
double CLiving::getLifeSatisfaction()const
{ return lifeSatisfaction;}
CSchool* CLiving::getSchool()const
{ return schoolConnected;}
CPeopleNeeds CLiving::getPeopleNeeds()const
{ return peopleNeeds;}


///CBLocks
CBlocks::CBlocks() : CLiving()
{}
CBlocks::CBlocks(const CBlocks& _B): CLiving(_B)
{}

///CHouse
CHouse::CHouse(): CLiving()
{}
CHouse::CHouse(const CHouse& _H): CLiving(_H)
{}
