#include "cmarket.h"
#include "ccity.h"
#include "cproductionbuilding.h"

CMarket::CMarket()
{
    clearShopsNeedsList();
    clearProductsPerTickAvailableList();
    clearStackedProductsAvailableList();
}
CMarket::CMarket(const CMarket& _M)
{   Q_UNUSED(_M);
}
CMarket::~CMarket()
{}

void CMarket::countSetActualProductsCost()
{
    CProducts _shopsProd;
    CProducts _tickProd;
    CProducts _stackedProd;
    for(int i=0; i <shopsNeedsList.count(); i++)
    {   _shopsProd += shopsNeedsList.at(i)->getProducts();
    }
    for(int i=0; i <productsPerTickAvailableList.count(); i++)
    {   _tickProd += productsPerTickAvailableList.at(i)->getProducts();
    }
    for(int i=0; i <stackedProductsAvailableList.count(); i++)
    {   _stackedProd += stackedProductsAvailableList.at(i)->getProducts();
    }

    //the bigger final ratio is, the cheaper product will be
    double _foodRatio1 = 4; //how many times supply is bigger than need
    if(_shopsProd.getFood()>0)
        _foodRatio1 = _tickProd.getFood()/_shopsProd.getFood();
    if(_foodRatio1>4)
        _foodRatio1=4;
    double _foodRatio2 = 10;
    if((_shopsProd.getFood() -_tickProd.getFood()) >0) //for how long stacked products will be enough
    {   _foodRatio2 =  _stackedProd.getFood()/(_shopsProd.getFood() -_tickProd.getFood());
        if(_foodRatio2 > 10)
            _foodRatio2=10;
    }
    actualProductsCost.setFood((actualProductsCost.getFood()+(baseProductsCost.getFood()/log(2.2+_foodRatio1/2+_foodRatio2/10)))/2);

    //the bigger final ratio is, the cheaper product will be
    double _lightRatio1 = 4; //how many times suppy is bigger than need
    if(_shopsProd.getLight()>0)
        _lightRatio1 = _tickProd.getLight()/_shopsProd.getLight();
    if(_lightRatio1>4)
        _lightRatio1=4;
    double _lightRatio2 = 10;
    if((_shopsProd.getLight() -_tickProd.getLight()) >0) //for how long stacked products will be enough
    {   _lightRatio2 =  _stackedProd.getLight()/(_shopsProd.getLight() -_tickProd.getLight());
        if(_lightRatio2 > 10)
            _lightRatio2=10;
    }
    actualProductsCost.setLight((actualProductsCost.getLight()+(baseProductsCost.getLight()/log(2.2+_lightRatio1/2+_lightRatio2/10)))/2);

    //the bigger final ratio is, the cheaper product will be
    double _heavyRatio1 = 4; //how many times suppy is bigger than need
    if(_shopsProd.getHeavy()>0)
        _heavyRatio1 = _tickProd.getHeavy()/_shopsProd.getHeavy();
    if(_heavyRatio1>4)
        _heavyRatio1=4;
    double _heavyRatio2 = 10;
    if((_shopsProd.getHeavy() -_tickProd.getHeavy()) >0) //for how long stacked products will be enough
    {   _heavyRatio2 =  _stackedProd.getHeavy()/(_shopsProd.getHeavy() -_tickProd.getHeavy());
        if(_heavyRatio2 > 10)
            _heavyRatio2=10;
    }
    actualProductsCost.setHeavy((actualProductsCost.getHeavy()+(baseProductsCost.getHeavy()/log(2.2+_heavyRatio1/2+_heavyRatio2/10)))/2);
}
void CMarket::takeAndPayPBForProducts()
{
    productsGotFromProduction = CProducts(0,0,0);
    CProducts _shopsProd;
    CProducts _tickProd;
    CProducts _stackedProd;
    for(int i=0; i <shopsNeedsList.count(); i++)
    {   _shopsProd += shopsNeedsList.at(i)->getProducts();
    }
    for(int i=0; i <productsPerTickAvailableList.count(); i++)
    {   _tickProd += productsPerTickAvailableList.at(i)->getProducts();
    }
    for(int i=0; i <stackedProductsAvailableList.count(); i++)
    {   _stackedProd += stackedProductsAvailableList.at(i)->getProducts();
    }

    //food
    double _foodQuantity1=_shopsProd.getFood() - _tickProd.getFood();
    double _foodQuantity2 =0;
    if(_foodQuantity1 > 0) //if production per tick is lower than need, take from stacked prod
    {   if(_stackedProd.getFood() > _foodQuantity1)
            _foodQuantity2 = _foodQuantity1; //take enough food
        else
            _foodQuantity2 = _stackedProd.getFood();   //take all food
    }
    for(int i=0; i<productsPerTickAvailableList.count();i++)
    {   CProducts _P;
        if(dynamic_cast<CFoodProduction*>(productsPerTickAvailableList.at(i)->getBuilding()) == NULL)
            continue;
        _P.setFood(productsPerTickAvailableList.at(i)->getProducts().getFood());
        if(_foodQuantity1>0) //all products per tick + all/some of stacked
        {   if(_stackedProd.getFood()>0)
                _P += CProducts(0,0,(stackedProductsAvailableList.at(i)->getProducts().getFood())*_foodQuantity2/_stackedProd.getFood());
        }
        else    //equal all or only part of prod. per tick
        {  if(_tickProd.getFood()>0)
                _P.setFood(_P.getFood()*_shopsProd.getFood()/_tickProd.getFood());
        }
        dynamic_cast<CFoodProduction*>(productsPerTickAvailableList.at(i)->getBuilding())->sellProducts(_P);
        productsGotFromProduction += _P;
    }

    //light
    double _lightQuantity1=_shopsProd.getLight() - _tickProd.getLight();
    double _lightQuantity2 =0;
    if(_lightQuantity1 > 0) //if production per tick is lower than need, take from stacked prod
    {   if(_stackedProd.getLight() > _lightQuantity1)
            _lightQuantity2 = _lightQuantity1; //take enough light
        else
            _lightQuantity2 = _stackedProd.getLight();   //take all light
    }
    for(int i=0; i<productsPerTickAvailableList.count();i++)
    {   if(dynamic_cast<CLightFactory*>(productsPerTickAvailableList.at(i)->getBuilding()) == NULL)
            continue;
        CProducts _P;
        _P.setLight(productsPerTickAvailableList.at(i)->getProducts().getLight());
        if(_lightQuantity1>0) //all products per tick + all/some of stacked
        {   if(_stackedProd.getLight()>0)
                _P += CProducts((stackedProductsAvailableList.at(i)->getProducts().getLight())*_lightQuantity2/_stackedProd.getLight(),0,0);
        }
        else    //equal all or only part of prod. per tick
        {  if(_tickProd.getLight()>0)
            _P.setLight(_P.getLight()*_shopsProd.getLight()/_tickProd.getLight());
        }
        dynamic_cast<CLightFactory*>(productsPerTickAvailableList.at(i)->getBuilding())->sellProducts(_P);
        productsGotFromProduction += _P;
    }

    //heavy
    double _heavyQuantity1=_shopsProd.getHeavy() - _tickProd.getHeavy();
    double _heavyQuantity2 =0;
    if(_heavyQuantity1 > 0) //if production per tick is lower than need, take from stacked prod
    {   if(_stackedProd.getHeavy() > _heavyQuantity1)
            _heavyQuantity2 = _heavyQuantity1; //take enough heavy
        else
            _heavyQuantity2 = _stackedProd.getHeavy();   //take all heavy
    }
    for(int i=0; i<productsPerTickAvailableList.count();i++)
    {   if(dynamic_cast<CHeavyFactory*>(productsPerTickAvailableList.at(i)->getBuilding()) == NULL)
            continue;
        CProducts _P;
        _P.setHeavy(productsPerTickAvailableList.at(i)->getProducts().getHeavy());
        if(_heavyQuantity1>0) //all products per tick + all/some of stacked
        {   if(_stackedProd.getHeavy()>0)
                _P += CProducts(0,(stackedProductsAvailableList.at(i)->getProducts().getHeavy())*_heavyQuantity2/_stackedProd.getHeavy(),0);
        }
        else    //equal all or only part of prod. per tick
        {  if(_tickProd.getHeavy()>0)
            _P.setHeavy(_P.getHeavy()*_shopsProd.getHeavy()/_tickProd.getHeavy());
        }
        dynamic_cast<CHeavyFactory*>(productsPerTickAvailableList.at(i)->getBuilding())->sellProducts(_P);
        productsGotFromProduction += _P;
    }
}
void CMarket::splitAndSendProductsToShops()
{
    CProducts allShopsNeed;
    for(int i=0; i<shopsNeedsList.count();i++)
    {   allShopsNeed += shopsNeedsList.at(i)->getProducts();}
    //it will not take more products from production buildings than all shops need anyway
    //distribute all
    double lightIndicator;
    if(allShopsNeed.getLight()!=0)
        lightIndicator = productsGotFromProduction.getLight()/allShopsNeed.getLight();
    else
        lightIndicator =0;
    if(lightIndicator>1)
        lightIndicator=1;

    double heavyIndicator;
    if(allShopsNeed.getHeavy()!=0)
        heavyIndicator= productsGotFromProduction.getHeavy()/allShopsNeed.getHeavy();
    else
        heavyIndicator=0;
    if(heavyIndicator>1)
        heavyIndicator=1;

    double foodIndicator;
    if(allShopsNeed.getFood()!=0)
        foodIndicator= productsGotFromProduction.getFood()/allShopsNeed.getFood();
    else
        foodIndicator=0;
    if(foodIndicator>1)
        foodIndicator=1;

    for(int i=0; i<shopsNeedsList.count();i++)
    {   CProducts _P((shopsNeedsList.at(i)->getProducts().getLight())*lightIndicator,
                     (shopsNeedsList.at(i)->getProducts().getHeavy())*heavyIndicator,
                     (shopsNeedsList.at(i)->getProducts().getFood())*foodIndicator);
        dynamic_cast<CShop*>(shopsNeedsList.at(i)->getBuilding())->buyProductsGotFromMarket(_P);
    }
}
void CMarket::clearTemporary()
{   clearShopsNeedsList();
    clearProductsPerTickAvailableList();
    clearStackedProductsAvailableList();
    productsGotFromProduction = CProducts(0,0,0);
}

void CMarket::clearShopsNeedsList()
{  for(int i=0; i<shopsNeedsList.count();i++)
    {   delete shopsNeedsList.at(i);}
    shopsNeedsList.clear();
}
void CMarket::clearProductsPerTickAvailableList()
{   for(int i=0; i<productsPerTickAvailableList.count();i++)
    {   delete productsPerTickAvailableList.at(i);}
    productsPerTickAvailableList.clear();
}
void CMarket::clearStackedProductsAvailableList()
{   for(int i=0; i<stackedProductsAvailableList.count();i++)
    {   delete stackedProductsAvailableList.at(i);}
    stackedProductsAvailableList.clear();
}
bool CMarket::addShopToShopsNeedList(CProductsBuildingPointer* _shop)
{   //check if shop
    if(dynamic_cast<CShop*>(_shop->getBuilding()) == NULL)
        return false;
    //check if not on shop list
    for(int i=0; i<shopsNeedsList.count();i++)
    {   if(_shop->getBuilding() == shopsNeedsList.at(i)->getBuilding())
            return false;}
    shopsNeedsList.append(_shop);
    return true;
}
bool CMarket::addPBToProductsPerTickList(CProductsBuildingPointer* _productionB)
{   if(dynamic_cast<CProductionBuilding*>(_productionB->getBuilding()) == NULL)
        return false;
    for(int i=0; i<productsPerTickAvailableList.count();i++)
    {   if(_productionB->getBuilding() == productsPerTickAvailableList.at(i)->getBuilding())
            return false;
    }
    productsPerTickAvailableList.append(_productionB);
    return true;
}
bool CMarket::addPBToStackedProductsAvailableList(CProductsBuildingPointer* _productionB)
{   if(dynamic_cast<CProductionBuilding*>(_productionB->getBuilding()) == NULL)
        return false;
    for(int i=0; i<stackedProductsAvailableList.count();i++)
    {   if(_productionB->getBuilding() == stackedProductsAvailableList.at(i)->getBuilding())
            return false;
    }
    stackedProductsAvailableList.append(_productionB);
    return true;
}

QVector<CProductsBuildingPointer*> CMarket::getShopsNeedsList()
{   return shopsNeedsList;}
QVector<CProductsBuildingPointer*> CMarket::getProductsPerTickAvailableList()
{   return productsPerTickAvailableList;}
QVector<CProductsBuildingPointer*> CMarket::getStackedProductsAvailableList()
{   return stackedProductsAvailableList;}
CProducts CMarket::getBaseProductsCost()
{   return baseProductsCost;}
CProducts CMarket::getActualProductsCost()
{   return actualProductsCost;}

void CMarket::setBaseProductsCost(CProducts _cost)
{   baseProductsCost = _cost;}
void CMarket::setBaseProductsCostFood(double _cost)
{   baseProductsCost.setFood(_cost);}
void CMarket::setBaseProductsCostLight(double _cost)
{   baseProductsCost.setLight(_cost);}
void CMarket::setBaseProductsCostHeavy(double _cost)
{   baseProductsCost.setHeavy(_cost);}
void CMarket::setActualProductsCost(CProducts _cost)
{   actualProductsCost = _cost;}
void CMarket::setCity(CCity* city)
{  this->city = city; }
