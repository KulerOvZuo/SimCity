#include "cproductionbuilding.h"
#include "cmarket.h"

CProductionBuilding::CProductionBuilding() : CWorking()
{
}
CProductionBuilding::CProductionBuilding(const CProductionBuilding& _P) : CWorking(_P)
{
    stackedProducts =_P.getStackedProducts();
    maxStackedProducts = _P.getMaxStackedProducts();
    actualProductionPerTick = _P.getActualProductionPerTick();
    maxProductionPerTick = _P.getMaxProductionPerTick();
    income = _P.getIncome();
}

void CProductionBuilding::countSetIncome()
{ /*
    income=0;
    income += productsBought.getFood()*
    income += productsBought.getHeavy()
    income += productsBought.getLight()*/
}
double CProductionBuilding::giveTaxes(double _tax)
{
    double tax = income * _tax/100;
    income -= tax;
    return tax;
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
void CProductionBuilding::setProductsBought(CProducts _P)
{   productsBought = _P;}
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
CProducts CProductionBuilding::getProductsBought() const
{   return productsBought;}
double CProductionBuilding::getIncome() const
{   return income;}
