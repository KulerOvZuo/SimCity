#ifndef CBUILDING_H
#define CBUILDING_H

#include "cstructureforpeople.h"
#include "cutilitiesglobal.h"

class CBuilding : public CStructureForPeople
{
protected:
    double money;
    CUtilitiesGlobal utilities;

public:
    CBuilding();
    CBuilding(const CBuilding& _B);
    CBuilding(double _money, CUtilitiesGlobal _U);
    virtual ~CBuilding();

    ///implement
    virtual bool sendUtilitiesToCity();
    virtual double countIncome();
    virtual bool sendTaxes();

    bool addMoney(double _money);

    bool setMoney(double _money);
    bool setUtilities(CUtilitiesGlobal _U);
    double getMoney() const;
    CUtilitiesGlobal getUtilities() const;

};

#endif // CBUILDING_H
