#ifndef CSHOP_H
#define CSHOP_H

#include "cworking.h"
#include "cpeopleneeds.h"
#include "cliving.h"

class CShop : public CWorking
{
protected:
    QList<CProductsBuildingPointer*> listOfLivingNeeds;
    CProducts productsNeedFromPeople;
    CProducts productsGotFromMarket;
    CProducts productsSellPrice;
    double income;
public:
    CShop();
    CShop(const  CShop& _S);
    virtual ~CShop();
    virtual QList<QString> infoToDisplay();
    virtual bool setRandomName(int size);

    bool sendProductsNeedToMarket();
    CProducts countSetProductsSellPrice();
    void payWorkers();
    bool sendProductsToLivings();

    bool buyProductsGotFromMarket(CProducts _prod);  
    double giveTaxes(double _tax);
    void clearListOfLivingNeeds();
    bool addLivingToProductsNeeds(CProductsBuildingPointer* _living);
    void clearTemporary();

    bool setProductsNeedFromPeople(CProducts _prod);
    bool setProductsGotFromMarket(CProducts _prod);
    bool setProductsSellPrice(CProducts _prod);
    void setIncome(double _inc);

    QList<CProductsBuildingPointer*> getListOfLivingNeeds();
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
