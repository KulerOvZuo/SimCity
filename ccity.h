#ifndef CCITY_H
#define CCITY_H

#include "cutilitiesglobal.h"
#include "cmarket.h"
#include "ctaxes.h"
#include "csocietyindicators.h"
#include "cmapofstructures.h"
#include "enumerators.h"

class CCity
{
protected:
    CUtilitiesGlobal utilitiesGlobalProduction;
    CUtilitiesGlobal utilitiesGlobalNeed;
    CMarket* market;
    CTaxes* taxes;
    CSocietyIndicators* societyIndicators;
    CMapOfStructures* mapOfStructures;
public:
    CCity();
    CCity(const CCity& _C);
    virtual ~CCity();

    ///implement
    void addUtilitiesGlobalNeed(CUtilitiesGlobal _U);
    double publicBuildingsKeepCost();
    double takeTaxes();

    bool addStructureProperly(CStructure* _S);
    bool removeStructureProperly(CStructure* _S);

    ///getters, not const
    CUtilitiesGlobal getUtilitiesGlobalProduction();
    CUtilitiesGlobal getUtilitiesGlobalNeed();
    CMarket* getMarket();
    CTaxes* getTaxes();
    CSocietyIndicators* getSocietyIndicators();
    CMapOfStructures* getMapOfStructures();

    ///setters
    void setUtilitiesGlobalProduction(CUtilitiesGlobal _U);
    void setUtilitiesGlobalNeed(CUtilitiesGlobal _U);
    void setMarket(CMarket* _M);
    void setTaxes(CTaxes* _T);
    void setSocietyIndicators(CSocietyIndicators* _S);
    void setMapOfStructures(CMapOfStructures* _M);


};

#endif // CCITY_H
