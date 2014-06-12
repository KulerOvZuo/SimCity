#ifndef CSOCIETYINDICATORS_H
#define CSOCIETYINDICATORS_H

#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "idisplayinginterface.h"
#include <qglobal.h>
#include <QTime>
#include <cmath>

class CSocietyIndicators : public IDisplayingInterface
{
protected:
    CPeopleEarnings peopleEarnings;
    CPeopleEarnings basePeopleEarnings;
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
    void clearTemporary();

    ///implement more
    CPeopleEarnings countSetPeopleEarnings();
    CPeople countSetProffesionsToEducate();

    void addChildren(int _children);
    void addBirthIndicator(double _birth);
    CPeople countProffesionsNeed();

    CPeopleEarnings getPeopleEarnings() const;
    CPeopleEarnings getBasePeopleEarnings() const;
    CPeople getAllPeople() const;
    CPeople getallLivingWorkingPeople() const;
    CPeople getallLivingNotWorkingPeople() const;
    CPeople getAllLearningPeople() const;
    CPeople getAllWorkForPeople() const;
    CPeople getAllProfessionsToEducate() const;
    int getChildren() const;
    double getBirthIndicator() const;

    void setPeopleEarnings(CPeopleEarnings _earn);
    void setBasePeopleEarnings(CPeopleEarnings _earn);
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
