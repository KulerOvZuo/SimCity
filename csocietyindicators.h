#ifndef CSOCIETYINDICATORS_H
#define CSOCIETYINDICATORS_H

#include "clearningpeople.h"
#include "cpeopleearnings.h"

class CSocietyIndicators
{
protected:
    CPeopleEarnings peopleEarnings;
    CPeople allPeople;
    CPeople allLivingWorkingPeople;
    CPeople allLivingNotWorkingPeople;
    CPeople allLearningPeople;
    CPeople allWorkForPeople; //from cworking
    CPeople allProfessionsToEducate; //how many people educate
    int children;
    double birthIndicator;
public:
    CSocietyIndicators();
    CSocietyIndicators(const CSocietyIndicators& _I);
    virtual ~CSocietyIndicators();

    void addPeopleEarnings(CPeopleEarnings _earn);
    void addAllPeople(CPeople _people);
    void addAllWorkForPeople(CPeople _people);
    void addAllLearningPeople(CPeople _people);
    void addAllProfessionsNeed(CPeople _people);
    void addBirthIndicator(double _birth);

    CPeopleEarnings getPeopleEarnings() const;
    CPeople getAllPeople() const;
    CPeople getAllWorkForPeople() const;
    CPeople getAllLearningPeople() const;
    CPeople getAllProfessionsNeed() const;
    double getBirthIndicator() const;

    void setPeopleEarnings(CPeopleEarnings _earn);
    void setAllPeople(CPeople _people);
    void setAllWorkForPeople(CPeople _people);
    void setAllLearningPeople(CPeople _people);
    void setAllProfessionsNeed(CPeople _people);
    void setBirthIndicator(double _birth);
};

#endif // CSOCIETYINDICATORS_H
