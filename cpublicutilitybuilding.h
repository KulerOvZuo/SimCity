#ifndef CPUBLICUTILITYBUILDING_H
#define CPUBLICUTILITYBUILDING_H

#include "cworking.h"

/**
 * @brief Klasa CPublicUtilityBuilding (budynki komunalne)
 *
 *Klasa nadrzędna dla wszystkich budynków komunalnych w mieście.
 *Te budynki "produkują" usługi komunalne.
 */
class CPublicUtilityBuilding : public CWorking
{
protected:
public:
    CPublicUtilityBuilding();
    CPublicUtilityBuilding(const CPublicUtilityBuilding& _U);
    virtual ~CPublicUtilityBuilding();

    bool sendUtilitiesToCity();
    ///Ustawia wartość usługi komunalnej w zależności od rodzaju.
    virtual void setProperUtility(double _utility);
    virtual bool setRandomName(int size);
};
/**
 * @brief Klasa CPowerStation (elektrownia)
 */
class CPowerStation : public CPublicUtilityBuilding
{
protected:
public:
    CPowerStation();
    CPowerStation(const CPowerStation& _P);

    void setProperUtility(double _utility);
};

/**
 * @brief Klasa CWaterStation (uzdatnianie wody)
 */
class CWaterStation : public CPublicUtilityBuilding
{
protected:
public:
    CWaterStation();
    CWaterStation(const CWaterStation& _W);

    void setProperUtility(double _utility);
};

/**
 * @brief Klasa CDumpStation (wysypisko)
 */
class CDumpStation : public CPublicUtilityBuilding
{
protected:
public:
    CDumpStation();
    CDumpStation(const CDumpStation& _D);

    void setProperUtility(double _utility);
};

/**
 * @brief Klasa CPublicUtilityBuildingAllInOne (obiekt komunalny wszystko w jednym)
 */
class CPublicUtilityBuildingAllInOne : public CPublicUtilityBuilding
{
protected:
public:
    CPublicUtilityBuildingAllInOne();
    CPublicUtilityBuildingAllInOne(const CPublicUtilityBuildingAllInOne& _P);

    void setProperUtility(double _utility);
};

#endif // CPUBLICUTILITYBUILDING_H
