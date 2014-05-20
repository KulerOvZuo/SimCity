#include "cshop.h"

CShop::CShop() : CWorking()
{
    //productsNeedFromPeople = CProducts();
   // productsGotFromMarket = CProducts();
   // productsSellPrice = CProducts();
}

CShop::CShop(const  CShop& _S) : CWorking(_S)
{
    productsNeedFromPeople =_S.getProductsNeedFromPeople();
    productsGotFromMarket =_S.getProductsGotFromMarket();
    productsSellPrice = _S.getProductsSellPrice();
}
CShop:: ~ CShop()
{}
CProducts CShop::countProductsSellPrice()
{

    return CProducts();
}
void CShop::sendProductsNeedToMarket()
{}
bool CShop::addProductsNeedFromPeople(CProducts _prod)
{
    CProducts _temp(productsNeedFromPeople);
    productsNeedFromPeople += _prod;
    bool _good = productsNeedFromPeople.restoreIfNotPossitiveNONeeds();
    if(_good == false)//restore to past
        productsNeedFromPeople = _temp;
    return _good;
}
bool CShop::addProductsGotFromMarket(CProducts _prod)
{
    CProducts _temp(productsGotFromMarket);
    productsGotFromMarket += _prod;
    bool _good = productsGotFromMarket.restoreIfNotPossitiveNONeeds();
    if(_good == false) //restore to past
        productsGotFromMarket = _temp;
    return _good;
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

CProducts CShop::getProductsNeedFromPeople() const
{   return productsNeedFromPeople;}
CProducts CShop::getProductsGotFromMarket() const
{   return productsGotFromMarket;}
CProducts CShop::getProductsSellPrice() const
{   return productsSellPrice;}

///CSmallShop
CSmallShop::CSmallShop() : CShop()
{}
CSmallShop::CSmallShop(const CSmallShop& _S): CShop(_S)
{}
CSmallShop::~CSmallShop()
{}
