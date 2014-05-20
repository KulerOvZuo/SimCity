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
    birthRate = _birth;
    return _birth;
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
{   livingNotWorkingPeople = _P;}
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
