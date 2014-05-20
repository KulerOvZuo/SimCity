#include "csocietyindicators.h"

CSocietyIndicators::CSocietyIndicators()
{
    birthIndicator=0;
}
CSocietyIndicators::CSocietyIndicators(const CSocietyIndicators& _I)
{
    peopleEarnings =_I.getPeopleEarnings();
    allPeople = _I.getAllPeople();
    allWorkForPeople =_I.getAllWorkForPeople();
    allLearningPeople =_I.getAllLearningPeople();
    allProfessionsNeed =_I.getAllProfessionsNeed();
    birthIndicator =_I.getBirthIndicator();
}
CSocietyIndicators::~CSocietyIndicators()
{}

CPeopleEarnings CSocietyIndicators::getPeopleEarnings() const
{   return peopleEarnings;}
CPeople CSocietyIndicators::getAllPeople() const
{   return allPeople;}
CPeople CSocietyIndicators::getAllWorkForPeople() const
{   return allWorkForPeople;}
CPeople CSocietyIndicators::getAllLearningPeople() const
{   return allLearningPeople;}
CPeople CSocietyIndicators::getAllProfessionsNeed() const
{   return allProfessionsNeed;}
double CSocietyIndicators::getBirthIndicator() const
{   return birthIndicator;}

void CSocietyIndicators::setPeopleEarnings(CPeopleEarnings _earn)
{   peopleEarnings = _earn; }
void CSocietyIndicators::setAllPeople(CPeople _people)
{   allPeople = _people;}
void CSocietyIndicators::setAllWorkForPeople(CPeople _people)
{   allWorkForPeople = _people;}
void CSocietyIndicators::setAllLearningPeople(CPeople _people)
{   allLearningPeople = _people;}
void CSocietyIndicators::setAllProfessionsNeed(CPeople _people)
{   allProfessionsNeed = _people;}
void CSocietyIndicators::setBirthIndicator(double _birth)
{   birthIndicator = _birth;}
