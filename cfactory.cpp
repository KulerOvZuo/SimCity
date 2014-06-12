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
{   sizeOnGameMap = CCoordinates(4,3);

}
CLightFactory::CLightFactory(const CLightFactory& _F) : CFactory(_F)
{   sizeOnGameMap = _F.getSizeOnGameMap();}
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
QList<QString> CLightFactory::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CProductionBuilding::infoToDisplay());
    info.append(QString("Base light production: %1\nActual light production: %2").
                arg(maxProductionPerTick.getLight(),1).
                arg(actualProductionPerTick.getLight(),1));
    info.append(QString("Max light products stacked: %1\nActual light products stacked: %2").
                arg(maxStackedProducts.getLight(),1).
                arg(stackedProducts.getLight(),1));
    return info;
}

CHeavyFactory::CHeavyFactory(): CFactory()
{   sizeOnGameMap = CCoordinates(5,4);}
CHeavyFactory::CHeavyFactory(const CHeavyFactory& _F) : CFactory(_F)
{   sizeOnGameMap = _F.getSizeOnGameMap();}
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
QList<QString> CHeavyFactory::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CProductionBuilding::infoToDisplay());
    info.append(QString("Base heavy production: %1\nActual heavy production: %2").
                arg(maxProductionPerTick.getHeavy(),1).
                arg(actualProductionPerTick.getHeavy(),1));
    info.append(QString("Max heavy products stacked: %1\nActual heavy products stacked: %2").
                arg(maxStackedProducts.getHeavy(),1).
                arg(stackedProducts.getHeavy(),1));
    return info;
}
