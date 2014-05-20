#include "csocietyindicators.h"

CSocietyIndicators::CSocietyIndicators()
{
    birthIndicator=0;
    children=0;
}
CSocietyIndicators::CSocietyIndicators(const CSocietyIndicators& _I)
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

CPeopleEarnings CSocietyIndicators::getPeopleEarnings() const
{   return peopleEarnings;}
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
