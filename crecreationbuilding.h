#ifndef CRECREATIONBUILDING_H
#define CRECREATIONBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"
class CRecreationBuilding : public CWorking
{
protected:
    int maxNOCustomers;
    int actualNOCustomers;
    CRecreation baseRecreation;
    CRecreation actualRecreation;
public:
    CRecreationBuilding();
    CRecreationBuilding(const CRecreationBuilding& _R);
    virtual ~CRecreationBuilding();

    double countBuildingEfficiency();
    void countSetRecreationQuality();
    bool addCustomers(int _number);

    int getMaxNOCustomers() const;
    int getActualNOCustomers() const;
    CRecreation getBaseRecreation() const;
    CRecreation getActualRecreation() const;

    void setMaxNOCustomers(int _max);
    void setActualNOCustomers(int _actual);
    void setBaseRecreation(CRecreation _base);
    void setActualRecreation(CRecreation _actual);
};

class CCinema : public CRecreationBuilding
{
protected:
public:
    CCinema();
    CCinema(const CCinema& _C);
    virtual ~CCinema();
};
#endif // CRECREATIONBUILDING_H
