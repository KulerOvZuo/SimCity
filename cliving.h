#ifndef CLIVING_H
#define CLIVING_H

#include "cbuilding.h"
#include "cpeopleneeds.h"
#include "cpeople.h"
#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "cschool.h"
#include "cshop.h"
#include "cservicebuilding.h"
#include <QVector>
#include <QList>

class CLiving : public CBuilding
{
protected:
    int maxLivingPeople;
    CPeople livingWorkingPeople;
    CPeople livingNotWorkingPeople;
    QList<CLearningPeople*> learningPeopleList;
    int children;
    double birthRate;
    double income;
    double lifeSatisfaction;
    CSchool* schoolConnected;
    CPeopleNeeds peopleNeeds;
public:
    CLiving();
    CLiving(const CLiving& _L);
    virtual ~CLiving();
    virtual QList<QString> infoToDisplay();

    bool searchSetForBetterSchool();
    bool searchAndSendNeedsToShops();
    bool searchForService();
    void sendPeopleInfoToCity();
    void sendChildrenInfoToCity();
    void makeDeadsAndBorns();
    bool changeLivingPlace();
    double countSetBirthRate();
    void sendBirthRateToCity();
    void countSetLifeSatAndPeopleNeeds();
    bool countSetInfluanceFromOthers();
    double getSetTrafficInformation();
    void searchAndGoToWork();
    void clearTemporary();

    bool buyProductsFromShop(CProducts _prod, CProducts _price);
    bool takeServiceFromSB(CService _serv, CService _cost);    
    void countSetIncome();

    double countLifeSatisfaction();
    double giveTaxes(double _tax);
    CPeopleNeeds countPeopleNeeds();

    //list
    void chooseChildrenProfessionsAndAdd();
    void addNewLearningPeople(CPeople _professions);
    void addLearningPeople(CLearningPeople* _learning);
    void clearListOfLearningPeople();
    void optimizeListOfLearningPeople();
    void educatePeople();
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
    void setProductsNeed(CProducts _prod);
    void setServiceNeed(CService _serv);
    void setRecreationNeed(CRecreation _rec);
    void setTraffic(double _traf);
    void setDistrurbance(double _dist);

    int getAllPeopleLiving() const;
    int getMaxLivingPeople()const;
    CPeople getLivingWorkingPeople()const;
    CPeople getLivingNotWorkingPeople()const;
    QList<CLearningPeople*> getListOfLearningPeople() const;
    int getChildren()const;
    double getBirthRate() const;
    double getIncome()const;
    double getLifeSatisfaction()const;
    CSchool* getSchool()const;
    CPeopleNeeds getPeopleNeeds() const;
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
