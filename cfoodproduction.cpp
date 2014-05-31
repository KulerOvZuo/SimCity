#include "cfoodproduction.h"
#include "ccity.h"

CFoodProduction::CFoodProduction() : CProductionBuilding()
{
}
CFoodProduction::CFoodProduction(const CFoodProduction& _F) : CProductionBuilding(_F)
{}
void CFoodProduction::sellProducts(CProducts _prod)
{   _prod.restoreIfNotPossitiveNONeeds();
    income += (_prod.getFood())*(city->getMarket()->getActualProductsCost().getFood());
    //add/subtract to stacked products difference
    stackedProducts += actualProductionPerTick - _prod;
    if(stackedProducts.getFood() > maxStackedProducts.getFood())
        stackedProducts.setFood(maxStackedProducts.getFood());
}

CFarm::CFarm() : CFoodProduction()
{}
CFarm::CFarm(const CFarm& _F) : CFoodProduction(_F)
{}
