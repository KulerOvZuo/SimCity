#ifndef CFOODPRODUCTION_H
#define CFOODPRODUCTION_H

#include "cproductionbuilding.h"

class CFoodProduction : public CProductionBuilding
{
protected:
public:
    CFoodProduction();
    CFoodProduction(const CFoodProduction& _F);
    void sellProducts(CProducts _prod);
};

class CFarm : public CFoodProduction
{
protected:
public:
    CFarm();
    CFarm(const CFarm& _F);
};

#endif // CFOODPRODUCTION_H
