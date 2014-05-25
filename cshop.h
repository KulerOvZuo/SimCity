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
    double income;
public:
    CShop();
    CShop(const  CShop& _S);
    virtual ~ CShop();

    ///implement
    CProducts countProductsSellPrice();
    void sendProductsNeedToMarket();
    bool addProductsNeedFromPeople(CProducts _prod);
    bool addProductsGotFromMarket(CProducts _prod);
    double giveTaxes(double _tax);

    bool setProductsNeedFromPeople(CProducts _prod);
    bool setProductsGotFromMarket(CProducts _prod);
    bool setProductsSellPrice(CProducts _prod);
    void setIncome(double _inc);

    CProducts getProductsNeedFromPeople() const;
    CProducts getProductsGotFromMarket() const;
    CProducts getProductsSellPrice() const;
    double getIncome() const;
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
