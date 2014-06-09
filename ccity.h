#ifndef CCITY_H
#define CCITY_H

#include "cutilitiesglobal.h"
#include "cmarket.h"
#include "ctaxes.h"
#include "csocietyindicators.h"
#include "cmapofstructures.h"
#include "enumerators.h"
#include "ctrafficengine.h"

class CCity
{
protected:
    CUtilitiesGlobal utilitiesGlobalProduction;
    CUtilitiesGlobal utilitiesGlobalNeed;
    CMarket* market;
    CTaxes* taxes;
    CSocietyIndicators* societyIndicators;
    CMapOfStructures* mapOfStructures;
    CTrafficEngine* trafficEngine;
    double money;
    double income;
public:
    CCity();
    CCity(const CCity& _C);
    virtual ~CCity();

    ///main function
    void makeTick();
    void initializeCity(QSize mapSize);

    double publicBuildingsKeepCost();
    double takeTaxes();
    bool addStructureProperly(CStructure* _S);
    bool removeStructureProperly(CStructure* _S);

    QList<CStructure*> updateView;
    bool checkIfCanBeBuild();
    bool build();
    bool destroy();

    void addUtilitiesGlobalNeed(CUtilitiesGlobal _U);
    void addMoney(double _money);

    ///getters, not const
    CUtilitiesGlobal getUtilitiesGlobalProduction();
    CUtilitiesGlobal getUtilitiesGlobalNeed();
    CMarket* getMarket();
    CTaxes* getTaxes();
    CSocietyIndicators* getSocietyIndicators();
    CMapOfStructures* getMapOfStructures();
    CTrafficEngine* getTrafficEngine();
    double getMoney();
    double getIncome();

    ///setters
    void setUtilitiesGlobalProduction(CUtilitiesGlobal _U);
    void setUtilitiesGlobalNeed(CUtilitiesGlobal _U);
    void setMarket(CMarket* _M);
    void setTaxes(CTaxes* _T);
    void setSocietyIndicators(CSocietyIndicators* _S);
    void setMapOfStructures(CMapOfStructures* _M);
    void setTrafficEngine(CTrafficEngine* _engine);
    void setMoney(double _money);

};

#endif // CCITY_H
