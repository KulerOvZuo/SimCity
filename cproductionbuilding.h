#ifndef CPRODUCTIONBUILDING_H
#define CPRODUCTIONBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"

class CProductionBuilding : public CWorking
{
protected:
    CProducts stackedProducts;
    CProducts maxStackedProducts;
    CProducts actualProductionPerTick;
    CProducts maxProductionPerTick;
    double income;
public:
    CProductionBuilding();
    CProductionBuilding(const CProductionBuilding& _P);

    ///implement more
    void payWorkers();
    double giveTaxes(double _tax);
    bool sendProductionInfoToMarket();
    virtual void sellProducts(CProducts _prod);
    double countBuildingEfficiency();
    void countSetActualProductionPerTick();
    void clearTemporary();

    void setAll(CProducts _stacked,CProducts _maxStacked,CProducts _prod,CProducts _maxProd, double _income);
    void setStackedProducts(CProducts _P);
    void setMaxStackedProducts(CProducts _P);
    void setMaxProductionPerTick(CProducts _P);
    void setActualProductionPerTick(CProducts _P);
    void setIncome(double _income);

    CProducts getStackedProducts() const;
    CProducts getMaxStackedProducts() const;
    CProducts getMaxProductionPerTick() const;
    CProducts getActualProductionPerTick() const;
    double getIncome() const;
};

#endif // CPRODUCTIONBUILDING_H
