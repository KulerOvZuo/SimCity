#ifndef CCITY_H
#define CCITY_H

#include "cutilitiesglobal.h"
#include "cmarket.h"
#include "cmapofstructures.h"
#include "ctaxes.h"
#include "csocietyindicators.h"

class CCity
{
protected:
    CUtilitiesGlobal utilitiesGlobalProduction;
    CUtilitiesGlobal utilitiesGlobalNeed;
    CMarket market;
    CTaxes taxes;
    CSocietyIndicators societyIndicators;
public:
    CCity();
    CCity(const CCity& _C);
    virtual ~CCity();
};

#endif // CCITY_H
