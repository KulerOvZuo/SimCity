#ifndef CRECREATIONBUILDING_H
#define CRECREATIONBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"
class CRecreationBuilding : public CWorking
{
protected:
    CRecreation baseRecreation;
    CRecreation actualRecreation;
public:
    CRecreationBuilding();
    CRecreationBuilding(const CRecreationBuilding& _R);
    virtual ~CRecreationBuilding();

    double countBuildingEfficiency();
    void countSetRecreationQuality();

    CRecreation getBaseRecreation() const;
    CRecreation getActualRecreation() const;

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
