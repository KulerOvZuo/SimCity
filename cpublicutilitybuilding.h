#ifndef CPUBLICUTILITYBUILDING_H
#define CPUBLICUTILITYBUILDING_H

#include "cworking.h"

class CPublicUtilityBuilding : public CWorking
{
protected:
public:
    CPublicUtilityBuilding();
    CPublicUtilityBuilding(const CPublicUtilityBuilding& _U);
    virtual ~CPublicUtilityBuilding();

    bool sendUtilitiesToCity();
    virtual void setProperUtility(double _utility);
};

class CPowerStation : public CPublicUtilityBuilding
{
protected:
public:
    CPowerStation();
    CPowerStation(const CPowerStation& _P);

    void setProperUtility(double _utility);
};

class CWaterStation : public CPublicUtilityBuilding
{
protected:
public:
    CWaterStation();
    CWaterStation(const CWaterStation& _W);

    void setProperUtility(double _utility);
};

class CDumpStation : public CPublicUtilityBuilding
{
protected:
public:
    CDumpStation();
    CDumpStation(const CDumpStation& _D);

    void setProperUtility(double _utility);
};

class CPublicUtilityBuildingAllInOne : public CPublicUtilityBuilding
{
protected:
public:
    CPublicUtilityBuildingAllInOne();
    CPublicUtilityBuildingAllInOne(const CPublicUtilityBuildingAllInOne& _P);

    void setProperUtility(double _utility);
};

#endif // CPUBLICUTILITYBUILDING_H
