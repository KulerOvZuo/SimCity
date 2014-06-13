#ifndef CPRODUCTIONBUILDING_H
#define CPRODUCTIONBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"

/**
 * @brief Klasa CProductionBuilding (budynki produkcyjne)
 *
 *Klasa nadrzędna dla wszystkich budynków mogących produkować przedmioty.
 *Produkty te mogą sie zbierać.
 */
class CProductionBuilding : public CWorking
{
protected:
    ///Aktualna ilość składowanych produktów.
    CProducts stackedProducts;
    ///Maksymalna ilość składowanych produktów.
    CProducts maxStackedProducts;
    ///Aktualna produkcja produktów na turę.
    CProducts actualProductionPerTick;
    ///Maksymalna produkcja produktów na turę.
    CProducts maxProductionPerTick;
    ///Dochód.
    double income;
public:
    CProductionBuilding();
    CProductionBuilding(const CProductionBuilding& _P);

    virtual QList<QString> infoToDisplay();

    /**
     * @brief Zapłać pracownikom
     *
     *Metoda powoduje zapłacenie pracownikom należnych pieniędzy.
     *Pomniejsza wartość dochodu.
     */
    void payWorkers();
    double giveTaxes(double _tax);
    /**
     * @brief Wyślij informacje o produkcji na rynek
     *
     *Na podstawie tych informacji rynek określa ile jest dostępnych produktów.
     * @return Zwraca true jeśli zostały wysłane poprawnie.
     */
    bool sendProductionInfoToMarket();
    ///Sprzedaje produkty na rynek i zwiększa wartosć dochodów.
    virtual void sellProducts(CProducts _prod);
    double countBuildingEfficiency();
    ///Oblicz i ustaw aktualną produkcję
    void countSetActualProductionPerTick();
    void clearTemporary();
    virtual bool setRandomName(int size);

    ///Ustaw wszystkie wartości.
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
