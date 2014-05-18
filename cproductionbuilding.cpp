#include "cproductionbuilding.h"

CProductionBuilding::CProductionBuilding() : CWorking()
{
}
CProductionBuilding::CProductionBuilding(const CProductionBuilding& _P) : CWorking(_P)
{
    stackedProducts =_P.getStackedProducts();
    maxStackedProducts = _P.getMaxStackedProducts();
    actualProductionPerTick = _P.getActualProductionPerTick();
    maxProductionPerTick = _P.getMaxProductionPerTick();
}

void CProductionBuilding::setAll(CProducts _stacked,CProducts _maxStacked,CProducts _prod,CProducts _maxProd)
{
     stackedProducts = _stacked;
     maxStackedProducts = _maxStacked;
     actualProductionPerTick = _prod;
     maxProductionPerTick = _maxProd;
}
void CProductionBuilding::setStackedProducts(CProducts _P)
{   stackedProducts = _P;}
void CProductionBuilding::setMaxStackedProducts(CProducts _P)
{   maxStackedProducts= _P;}
void CProductionBuilding::setMaxProductionPerTick(CProducts _P)
{   maxProductionPerTick= _P;}
void CProductionBuilding::setActualProductionPerTick(CProducts _P)
{   actualProductionPerTick= _P;}

CProducts CProductionBuilding::getStackedProducts() const
{   return stackedProducts;}
CProducts CProductionBuilding::getMaxStackedProducts() const
{   return  maxStackedProducts;}
CProducts CProductionBuilding::getMaxProductionPerTick() const
{   return maxProductionPerTick;}
CProducts CProductionBuilding::getActualProductionPerTick() const
{   return actualProductionPerTick;}
