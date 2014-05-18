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
public:
    CProductionBuilding();
    CProductionBuilding(const CProductionBuilding& _P);

    ///implement more

    void setAll(CProducts _stacked,CProducts _maxStacked,CProducts _prod,CProducts _maxProd);
    void setStackedProducts(CProducts _P);
    void setMaxStackedProducts(CProducts _P);
    void setMaxProductionPerTick(CProducts _P);
    void setActualProductionPerTick(CProducts _P);

    CProducts getStackedProducts() const;
    CProducts getMaxStackedProducts() const;
    CProducts getMaxProductionPerTick() const;
    CProducts getActualProductionPerTick() const;
};

#endif // CPRODUCTIONBUILDING_H
