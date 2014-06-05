#include "cfactory.h"
#include "ccity.h"

CFactory::CFactory() : CProductionBuilding()
{
}
CFactory::CFactory(const CFactory& _F) : CProductionBuilding(_F)
{}
void CFactory::sellProducts(CProducts _prod)
{ Q_UNUSED(_prod);
}
CLightFactory::CLightFactory() : CFactory()
{}
CLightFactory::CLightFactory(const CLightFactory& _F) : CFactory(_F)
{}
void CLightFactory::sellProducts(CProducts _prod)
{   _prod.restoreIfNotPossitiveNONeeds();
    income += (_prod.getLight())*(city->getMarket()->getActualProductsCost().getLight());
    //add/subtract to stacked products difference
    stackedProducts += actualProductionPerTick - _prod;
    if(stackedProducts.getLight() > maxStackedProducts.getLight())
        stackedProducts.setLight(maxStackedProducts.getLight());
    if(stackedProducts.getLight() <0)
        stackedProducts.setLight(0);
}

CHeavyFactory::CHeavyFactory(): CFactory()
{}
CHeavyFactory::CHeavyFactory(const CHeavyFactory& _F) : CFactory(_F)
{}
void CHeavyFactory::sellProducts(CProducts _prod)
{   _prod.restoreIfNotPossitiveNONeeds();
    income += (_prod.getHeavy())*city->getMarket()->getActualProductsCost().getHeavy();
    //add/subtract to stacked products difference
    stackedProducts += actualProductionPerTick - _prod;
    if(stackedProducts.getHeavy() > maxStackedProducts.getHeavy())
        stackedProducts.setHeavy(maxStackedProducts.getHeavy());
    if(stackedProducts.getHeavy()<0)
        stackedProducts.setHeavy(0);
}
