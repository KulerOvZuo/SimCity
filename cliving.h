#ifndef CLIVING_H
#define CLIVING_H

#include "cbuilding.h"
#include "cpeopleneeds.h"
#include "cpeople.h"
#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "cschool.h"
#include <QVector>

class CLiving : public CBuilding
{
protected:
    int maxLivingPeople;
    CPeople livingWorkingPeople;
    CPeople livingNotWorkingPeople;
    QList<CLearningPeople> learningPeopleList;
    int children;
    double birthRate;
    double income;
    double lifeSatisfaction;
    CSchool* schoolConnected;
    CPeopleNeeds peopleNeeds;
public:
    CLiving();
    CLiving(const CLiving& _L);
    ~CLiving();

    ///implement more metods
    //list
    void addNewLearningPeople(CPeople _professions);
    void clearListOfLearningPeople();
    void optimizeListOfLearningPeople();
    void educatePeople(double _educationIndicator);
    CPeople extractEducatedPeople();
    CPeople getNumberOfLearningPeople();

    void setMaxLivingPeople(int _max);
    void setLivingWorkingPeople(CPeople _P);
    void setLivingNotWorkingPeople(CPeople _P);
    void setChildren(int _children);
    void setIncome(int _income);
    void setLifeSatisfaction( double _lifeSat);
    bool setSchool(CSchool* _school);
    void setPeopleNeeds(CPeopleNeeds _P);

    int getMaxLivingPeople()const;
    CPeople getLivingWorkingPeople()const;
    CPeople getLivingNotWorkingPeople()const;
    QList<CLearningPeople> getListOfLearningPeople() const;
    int getChildren()const;
    double getBirthRate() const;
    double getIncome()const;
    double getLifeSatisfaction()const;
    CSchool* getSchool()const;
    CPeopleNeeds getPeopleNeeds()const;
};


class CBlocks : public CLiving
{
protected:
public:
    CBlocks();
    CBlocks(const CBlocks& _B);
};

class CHouse : public CLiving
{
protected:
public:
    CHouse();
    CHouse(const CHouse& _H);
};
#endif // CLIVING_H
