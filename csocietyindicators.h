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
    void addAllLivingWorkingPeople(CPeople _people);
    void addAllLivingNotWorkingPeople(CPeople _people);
    void addAllLearningPeople(CPeople _people);
    void addAllProfessionsToEducate(CPeople _people);
    void addChildren(int _children);
    void addBirthIndicator(double _birth);

    CPeopleEarnings getPeopleEarnings() const;
    CPeople getAllPeople() const;
    CPeople getallLivingWorkingPeople() const;
    CPeople getallLivingNotWorkingPeople() const;
    CPeople getAllLearningPeople() const;
    CPeople getAllWorkForPeople() const;
    CPeople getAllProfessionsToEducate() const;
    int getChildren() const;
    double getBirthIndicator() const;

    void setPeopleEarnings(CPeopleEarnings _earn);
    void setAllPeople(CPeople _people);
    void setAllLivingWorkingPeople(CPeople _people);
    void setAllLivingNotWorkingPeople(CPeople _people);
    void setAllLearningPeople(CPeople _people);
    void setAllWorkForPeople(CPeople _people);
    void setAllProfessionsToEducate(CPeople _people);
    void setChildren(int _children);
    void setBirthIndicator(double _birth);
};

#endif // CSOCIETYINDICATORS_H
