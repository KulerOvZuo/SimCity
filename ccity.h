#ifndef CCITY_H
#define CCITY_H

#include "cutilitiesglobal.h"
#include "cmarket.h"
#include "ctaxes.h"
#include "csocietyindicators.h"
#include "cmapofstructures.h"

class CCity
{
protected:
    CUtilitiesGlobal utilitiesGlobalProduction;
    CUtilitiesGlobal utilitiesGlobalNeed;
    CMarket market;
    CTaxes taxes;
    CSocietyIndicators societyIndicators;
    CMapOfStructures mapOfStructures;
public:
    CCity();
    CCity(const CCity& _C);
    virtual ~CCity();
};

#endif // CCITY_H
