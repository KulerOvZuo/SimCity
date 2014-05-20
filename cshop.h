#ifndef CSHOP_H
#define CSHOP_H

#include "cworking.h"
#include "cpeopleneeds.h"

class CShop : public CWorking
{
protected:
    CProducts productsNeedFromPeople;
    CProducts productsGotFromMarket;
    CProducts productsSellPrice;
public:
    CShop();
    CShop(const  CShop& _S);
    virtual ~ CShop();

    ///implement
    CProducts countProductsSellPrice();
    void sendProductsNeedToMarket();
    bool addProductsNeedFromPeople(CProducts _prod);
    bool addProductsGotFromMarket(CProducts _prod);

    bool setProductsNeedFromPeople(CProducts _prod);
    bool setProductsGotFromMarket(CProducts _prod);
    bool setProductsSellPrice(CProducts _prod);

    CProducts getProductsNeedFromPeople() const;
    CProducts getProductsGotFromMarket() const;
    CProducts getProductsSellPrice() const;
};

class CSmallShop : public CShop
{
protected:
public:
    CSmallShop();
    CSmallShop(const CSmallShop& _S);
    virtual ~CSmallShop();
};

#endif // CSHOP_H
