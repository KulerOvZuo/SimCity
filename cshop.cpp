#include "cshop.h"
#include "ccity.h"
CShop::CShop() : CWorking()
{
    income =0;
    //productsNeedFromPeople = CProducts();
   // productsGotFromMarket = CProducts();
   // productsSellPrice = CProducts();
}

CShop::CShop(const  CShop& _S) : CWorking(_S)
{
    productsNeedFromPeople =_S.getProductsNeedFromPeople();
    productsGotFromMarket =_S.getProductsGotFromMarket();
    productsSellPrice = _S.getProductsSellPrice();
    income = _S.getIncome();
}
CShop:: ~ CShop()
{}
CProducts CShop::countSetProductsSellPrice()
{
    double indicator = 1.3;
    CProducts marketPrice = city->getMarket()->getActualProductsCost();
    productsSellPrice = CProducts(indicator*marketPrice.getLight(),indicator*marketPrice.getHeavy(),indicator*marketPrice.getFood());
    return productsSellPrice;
}
bool CShop::sendProductsNeedToMarket()
{
    CProductsBuildingPointer* _P = new CProductsBuildingPointer;
    _P->setBuilding(this);
    _P->setProducts(productsNeedFromPeople);
   return city->getMarket()->addShopToShopsNeedList(_P);
}
bool CShop::buyProductsGotFromMarket(CProducts _prod)
{
    CProducts marketPrice = city->getMarket()->getActualProductsCost();
    bool _good =_prod.restoreIfNotPossitiveNONeeds();
    productsGotFromMarket = _prod;
    income -= (_prod.getLight()*marketPrice.getLight()+_prod.getHeavy()*marketPrice.getHeavy()+_prod.getFood()*marketPrice.getFood());
    return _good;
}
bool CShop::sendProductsToLivings()
{   CProducts allLivingNeeds;
    for(int i=0; i<listOfLivingNeeds.count();i++)
    {   allLivingNeeds += listOfLivingNeeds.at(i)->getProducts();}
    ///it will not take more products from market than all living need anyway
    //distribute all
    double lightIndicator = productsGotFromMarket.getLight()/allLivingNeeds.getLight();
    if(lightIndicator>1)
        lightIndicator=1;
    double heavyIndicator = productsGotFromMarket.getHeavy()/allLivingNeeds.getHeavy();
    if(heavyIndicator>1)
        heavyIndicator=1;
    double foodIndicator = productsGotFromMarket.getFood()/allLivingNeeds.getFood();
    if(foodIndicator>1)
        foodIndicator=1;
    for(int i=0; i<listOfLivingNeeds.count();i++)
    {   CProducts _P(listOfLivingNeeds.at(i)->getProducts().getLight()*lightIndicator,
                     listOfLivingNeeds.at(i)->getProducts().getHeavy()*heavyIndicator,
                     listOfLivingNeeds.at(i)->getProducts().getFood()*foodIndicator);
        dynamic_cast<CLiving*>(listOfLivingNeeds.at(i)->getBuilding())->buyProductsFromShop(_P,productsSellPrice);
    income += (_P.getLight()*productsSellPrice.getLight()+_P.getHeavy()*productsSellPrice.getHeavy()+_P.getFood()*productsSellPrice.getFood());
    }
    return true;
}
double CShop::giveTaxes(double _tax)
{
    double tax = income * _tax/100;
    income -= tax;
    return tax;
}
void CShop::clearListOfLivingNeeds()
{   for(int i=0; i<listOfLivingNeeds.count();i++)
    {   delete listOfLivingNeeds.at(i);}
    listOfLivingNeeds.clear();
}
bool CShop::addLivingToProductsNeeds(CProductsBuildingPointer* _living)
{   bool free = true;
    if(dynamic_cast<CLiving*>(_living->getBuilding()) == NULL)
        return false;
    for(int i=0; i<listOfLivingNeeds.count();i++ )
    {   if((listOfLivingNeeds.at(i)->getBuilding()) == _living->getBuilding())
        {   free = false;
            return false;}
    }
    if(free)
    {   listOfLivingNeeds.append(_living);
        productsNeedFromPeople += _living->getProducts();
    }
    return free;
}
bool CShop::setProductsNeedFromPeople(CProducts _prod)
{
    CProducts _temp(productsNeedFromPeople);
    productsNeedFromPeople = _prod;
    bool _good = productsNeedFromPeople.restoreIfNotPossitiveNONeeds();
    if(_good == false)//restore to past
        productsNeedFromPeople = _temp;
    return _good;
}
bool CShop::setProductsGotFromMarket(CProducts _prod)
{
    CProducts _temp(productsGotFromMarket);
    productsGotFromMarket = _prod;
    bool _good = productsGotFromMarket.restoreIfNotPossitiveNONeeds();
    if(_good == false) //restore to past
        productsGotFromMarket = _temp;
    return _good;
}
bool CShop::setProductsSellPrice(CProducts _prod)
{
    CProducts _temp(productsSellPrice);
    productsSellPrice = _prod;
    bool _good = productsSellPrice.restoreIfNotPossitiveNONeeds();
    if(_good == false) //restore to past
        productsSellPrice = _temp;
    return _good;
}
void CShop::setIncome(double _inc)
{   income =_inc;}

QList<CProductsBuildingPointer*> CShop::getListOfLivingNeeds()
{   return listOfLivingNeeds;}
CProducts CShop::getProductsNeedFromPeople() const
{   return productsNeedFromPeople;}
CProducts CShop::getProductsGotFromMarket() const
{   return productsGotFromMarket;}
CProducts CShop::getProductsSellPrice() const
{   return productsSellPrice;}
double CShop::getIncome() const
{   return income;}


///CSmallShop
CSmallShop::CSmallShop() : CShop()
{}
CSmallShop::CSmallShop(const CSmallShop& _S): CShop(_S)
{}
CSmallShop::~CSmallShop()
{}
