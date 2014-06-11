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
    if(stackedProducts.getFood() <0)
        stackedProducts.setFood(0);
}

CFarm::CFarm() : CFoodProduction()
{   sizeOnGameMap = CCoordinates(4,3);}
CFarm::CFarm(const CFarm& _F) : CFoodProduction(_F)
{   sizeOnGameMap = _F.getSizeOnGameMap();}
