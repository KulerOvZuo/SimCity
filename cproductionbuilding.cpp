#include "cproductionbuilding.h"
#include "cmarket.h"
#include "ccity.h"

CProductionBuilding::CProductionBuilding() : CWorking()
{
    income=0;
}
CProductionBuilding::CProductionBuilding(const CProductionBuilding& _P) : CWorking(_P)
{
    stackedProducts =_P.getStackedProducts();
    maxStackedProducts = _P.getMaxStackedProducts();
    actualProductionPerTick = _P.getActualProductionPerTick();
    maxProductionPerTick = _P.getMaxProductionPerTick();
    income = _P.getIncome();
}

bool CProductionBuilding::sendUtilitiesToCity()
{
    city->setUtilitiesGlobalProduction(city->getUtilitiesGlobalProduction()+=utilities);
    return true;}
void CProductionBuilding::countSetIncome()
{
}
double CProductionBuilding::giveTaxes(double _tax)
{
    double tax = income * _tax/100;
    income -= tax;
    return tax;
}
bool CProductionBuilding::sendProductionInfoToMarket()
{
    bool _good = false;
    CProductsBuildingPointer* _tick = new CProductsBuildingPointer;
    _tick->setBuilding(this);
    CProductsBuildingPointer* _stack = new CProductsBuildingPointer(*_tick);
    _tick->setProducts(actualProductionPerTick);
    _stack->setProducts(stackedProducts);

    if(city->getMarket()->addPBToProductsPerTickList(_tick))
    {   _good = true;
        _good = city->getMarket()->addPBToStackedProductsAvailableList(_stack);
    }
    else
    {   city->getMarket()->addPBToStackedProductsAvailableList(_stack);
        _good = false;
    }
    return _good;
}
void CProductionBuilding::sellProducts(CProducts _prod)
{   Q_UNUSED(_prod);
}


void CProductionBuilding::setAll(CProducts _stacked,CProducts _maxStacked,CProducts _prod,CProducts _maxProd, double _income)
{
     stackedProducts = _stacked;
     maxStackedProducts = _maxStacked;
     actualProductionPerTick = _prod;
     maxProductionPerTick = _maxProd;
     income=_income;
}
void CProductionBuilding::setStackedProducts(CProducts _P)
{   stackedProducts = _P;}
void CProductionBuilding::setMaxStackedProducts(CProducts _P)
{   maxStackedProducts= _P;}
void CProductionBuilding::setMaxProductionPerTick(CProducts _P)
{   maxProductionPerTick= _P;}
void CProductionBuilding::setActualProductionPerTick(CProducts _P)
{   actualProductionPerTick= _P;}
void CProductionBuilding::setIncome(double _income)
{   income=_income;}

CProducts CProductionBuilding::getStackedProducts() const
{   return stackedProducts;}
CProducts CProductionBuilding::getMaxStackedProducts() const
{   return  maxStackedProducts;}
CProducts CProductionBuilding::getMaxProductionPerTick() const
{   return maxProductionPerTick;}
CProducts CProductionBuilding::getActualProductionPerTick() const
{   return actualProductionPerTick;}
double CProductionBuilding::getIncome() const
{   return income;}
