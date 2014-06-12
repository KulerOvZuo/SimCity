#ifndef CSERVICEBUILDING_H
#define CSERVICEBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"
#include "cpeopleearnings.h"

class CServiceBuilding  : public CWorking
{
protected:
    QVector<CPeopleNeedsBuildingPointer*> listOfLivingNeeds;
    CService serviceNeedFromPeople;
    CService baseService;
    CService actualService;
    CService baseServiceCost;
    CService actualServiceCost;
    double income;

public:
    CServiceBuilding();
    CServiceBuilding(const CServiceBuilding& _S);
    virtual ~CServiceBuilding();
    virtual QList<QString> infoToDisplay();

    void payWorkers();
    void countSetActualServiceCost();
    void countSetServiceQuality();
    bool giveServiceToLivings();

    //list
    bool addLivingTolist(CPeopleNeedsBuildingPointer* _living);
    void clearListOfLivingNeeds();
    void clearTemporary();

    double countBuildingEfficiency();    
    double giveTaxes(double _tax);    

    CService getBaseService() const;
    CService getActualService() const;
    CService getBaseServiceCost() const;
    CService getActualServiceCost() const;
    double getIncome() const;

    void setBaseService(CService _base);
    void setActualService(CService _actual);
    void setBaseServiceCost(CService _base);
    void setActualServiceCost(CService _actual);
    void setIncome(double _inc);
};

class COffice : public CServiceBuilding
{
protected:
public:
    COffice();
    COffice(const COffice& _O);
    virtual ~COffice();
};
#endif // CSERVICEBUILDING_H
