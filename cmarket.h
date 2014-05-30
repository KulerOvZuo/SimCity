#ifndef CMARKET_H
#define CMARKET_H

#include "cshop.h"
#include "cproductionbuilding.h"
#include "cpeopleneeds.h"
class CCity;
class CMarket
{
protected:
    QVector<CProductsBuildingPointer*> shopsNeedsList;
    QVector<CProductsBuildingPointer*> productsPerTickAvailableList;
    QVector<CProductsBuildingPointer*> stackedProductsAvailableList;
    CProducts productsGotFromProduction;
    CProducts baseProductsCost;
    CProducts actualProductsCost;
    CCity* city;
public:
    CMarket();
    CMarket(const CMarket& _M);
    virtual ~CMarket();

    void countSetActualProductsCost();
    void takeAndPayPBForProducts();
    void splitAndSendProductsToShops();

    //lists
    void clearShopsNeedsList();
    void clearProductsPerTickAvailableList();
    void clearStackedProductsAvailableList();
    bool addShopToShopsNeedList(CProductsBuildingPointer* _shop);
    bool addPBToProductsPerTickList(CProductsBuildingPointer* _productionB);
    bool addPBToStackedProductsAvailableList(CProductsBuildingPointer* _productionB);

    QVector<CProductsBuildingPointer*> getShopsNeedsList();
    QVector<CProductsBuildingPointer*> getProductsPerTickAvailableList();
    QVector<CProductsBuildingPointer*> getStackedProductsAvailableList();
    CProducts getBaseProductsCost();
    CProducts getActualProductsCost();

    void setBaseProductsCost(CProducts _cost);
    void setActualProductsCost(CProducts _cost);
    void setCity(CCity* city);
};

#endif // CMARKET_H
