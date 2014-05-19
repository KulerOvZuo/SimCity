#ifndef CSERVICEBUILDING_H
#define CSERVICEBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"

class CServiceBuilding  : public CWorking
{
protected:
    int maxNOCustomers;
    int actualNOCustomers;
    CService baseService;
    CService actualService;

public:
    CServiceBuilding();
    CServiceBuilding(const CServiceBuilding& _S);
    virtual ~CServiceBuilding();

    double countBuildingEfficiency();
    void countSetServiceQuality();
    bool addCustomers(int _number);

    int getMaxNOCustomers() const;
    int getActualNOCustomers() const;
    CService getBaseService() const;
    CService getActualService() const;

    void setMaxNOCustomers(int _max);
    void setActualNOCustomers(int _actual);
    void setBaseService(CService _base);
    void setActualService(CService _actual);
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
