#include "cshop.h"
#include "ccity.h"
CShop::CShop() : CWorking()
{
    income =0;
    setRandomName(2);
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
QList<QString> CShop::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CWorking::infoToDisplay());
    info.append(QString("Income: %1$").arg(income,1,'f',2));
    info.append(QString("Products sell price:\nFood price: %1$\nLight price: %2$\nHeavy price: %3$").
                arg(productsSellPrice.getFood(),1,'f',2).
                arg(productsSellPrice.getLight(),1,'f',2).
                arg(productsSellPrice.getHeavy(),1,'f',2));
    return info;
}
bool CShop::setRandomName(int size)
{  Q_UNUSED(size);
    CStructure::setRandomName(2);
return true;}

CProducts CShop::countSetProductsSellPrice()
{
    double indicator = 1.3;
    //CProducts marketPrice = city->getMarket()->getActualProductsCost();
    CProducts allShopsNeed;
    for(int i=0; i< city->getMarket()->getShopsNeedsList().count();i++)
    {   allShopsNeed += city->getMarket()->getShopsNeedsList().at(i)->getProducts();}

    double _lightCost=productsSellPrice.getLight();
    if(allShopsNeed.getLight()!=0)
        _lightCost=(indicator+0.4*productsGotFromMarket.getLight()/allShopsNeed.getLight())*city->getMarket()->getActualProductsCost().getLight();
    double _heavyCost=productsSellPrice.getHeavy();
    if(allShopsNeed.getHeavy()!=0)
        _heavyCost= (indicator+0.4*productsGotFromMarket.getHeavy()/allShopsNeed.getHeavy())*city->getMarket()->getActualProductsCost().getHeavy();
    double _foodCost = productsSellPrice.getFood();
    if(allShopsNeed.getFood()!=0)
        _foodCost= (indicator+0.4*productsGotFromMarket.getFood()/allShopsNeed.getFood())*city->getMarket()->getActualProductsCost().getFood();

    CProducts P = CProducts(_lightCost,_heavyCost,_foodCost);

    productsSellPrice = CProducts((productsSellPrice.getLight()+P.getLight())/2,
                                  (productsSellPrice.getHeavy()+P.getHeavy())/2,
                                  (productsSellPrice.getFood()+P.getFood())/2);
    return productsSellPrice;
}
void CShop::payWorkers()
{
    CPeopleEarnings _peopleEarn;
    _peopleEarn = city->getSocietyIndicators()->getPeopleEarnings();
    income -= (actualNumberOfWorkers.getLeadWorker()*_peopleEarn.getLeadWorkerEarn()+
            actualNumberOfWorkers.getLightWorker()*_peopleEarn.getLightWorkerEarn()+
            actualNumberOfWorkers.getServiceWorker()*_peopleEarn.getServiceWorkerEarn()+
            actualNumberOfWorkers.getHeavyWorker()*_peopleEarn.getHeavyWorkerEarn()+
            actualNumberOfWorkers.getLowWorker()*_peopleEarn.getLowWorkerEarn())/2;

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
    //it will not take more products from market than all living need anyway
    //distribute all
    double lightIndicator=0;
    if(allLivingNeeds.getLight()!=0)
        lightIndicator= productsGotFromMarket.getLight()/allLivingNeeds.getLight();
    if(lightIndicator>1)
        lightIndicator=1;

    double heavyIndicator=0;
    if(allLivingNeeds.getHeavy()!=0)
        heavyIndicator= productsGotFromMarket.getHeavy()/allLivingNeeds.getHeavy();
    if(heavyIndicator>1)
        heavyIndicator=1;

    double foodIndicator=0;
    if(allLivingNeeds.getFood()!=0)
        foodIndicator= productsGotFromMarket.getFood()/allLivingNeeds.getFood();
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
    if(income <0)
        return 0;
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
void CShop::clearTemporary()
{   clearListOfLivingNeeds();
    productsNeedFromPeople = CProducts(0,0,0);
    productsGotFromMarket = CProducts(0,0,0);
   // productsSellPrice = CProducts(0,0,0);
    money += income;
    income =0;

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


//CSmallShop
CSmallShop::CSmallShop() : CShop()
{   sizeOnGameMap = CCoordinates(3,2);
    buildCost=200;
    destroyCost=buildCost/2;
    money=5000;
    utilities=CUtilitiesGlobal(5,5,5);
    neededNumberOfWorkers=CPeople(2,2,2,5,15);
}
CSmallShop::CSmallShop(const CSmallShop& _S): CShop(_S)
{   sizeOnGameMap = _S.getSizeOnGameMap();}
CSmallShop::~CSmallShop()
{}
