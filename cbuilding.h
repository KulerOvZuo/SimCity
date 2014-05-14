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
    CBuilding(double _money, CUtilitiesGlobal _U);

    ///implement
    bool sendUtilitiesToCity();
    double countIncome();
    bool sendTaxes();

    bool addMoney(double _money);

    bool setMoney(double _money);
    bool setUtilities(CUtilitiesGlobal _U);
    double getMoney() const;
    CUtilitiesGlobal getUtilities() const;

};

#endif // CBUILDING_H
