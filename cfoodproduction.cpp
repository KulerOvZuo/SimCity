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
QList<QString> CFoodProduction::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CProductionBuilding::infoToDisplay());
    info.append(QString("Base food production: %1\nActual food production: %2").
                arg(maxProductionPerTick.getFood(),1).
                arg(actualProductionPerTick.getFood(),1));
    info.append(QString("Max food stacked: %1\nActual food stacked: %2").
                arg(maxStackedProducts.getFood(),1).
                arg(stackedProducts.getFood(),1));
    return info;
}

CFarm::CFarm() : CFoodProduction()
{   sizeOnGameMap = CCoordinates(4,3);}
CFarm::CFarm(const CFarm& _F) : CFoodProduction(_F)
{   sizeOnGameMap = _F.getSizeOnGameMap();}
