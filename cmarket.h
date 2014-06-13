#ifndef CMARKET_H
#define CMARKET_H

#include "cshop.h"
#include "cproductionbuilding.h"
#include "cpeopleneeds.h"
class CCity;
/**
 * @brief Klasa CMarket (rynek obrotu zasobami)
 *
 *Klasa zarządzająca przepływem towarów pomiędzy sklepami a budynkami produkcyjnymi.
 *Kupuje towary od producentów i rozdziela je pomiędzy sklepy. Ustala także ceny towarów.
 */
class CMarket
{
protected:
    /**
     * @brief Lista potrzeb sklepów.
     *
     *Lista składająca się z komórek określających potrzeby danego sklepu, które zostały przesłane do rynku.
     */
    QVector<CProductsBuildingPointer*> shopsNeedsList;
    /**
     * @brief Lista produktów produkowanych ciągle.
     *
     *Lista składająca się z komórek określających produkcję danego producenta, które zostały przesłane do rynku.
     */
    QVector<CProductsBuildingPointer*> productsPerTickAvailableList;
    /**
     * @brief Lista produktów składowanych.
     *
     *Lista składająca się z komórek określających produkty zeskładowane danego producenta, które zostały przesłane do rynku.
     */
    QVector<CProductsBuildingPointer*> stackedProductsAvailableList;
    ///Suma produktów potrzebnych.
    CProducts productsGotFromProduction;
    ///Bazowa cena produktów.
    CProducts baseProductsCost;
    ///Aktualna cena produktów.
    CProducts actualProductsCost;
public:
    CMarket();
    CMarket(const CMarket& _M);
    virtual ~CMarket();

    ///Oblicz aktualna cenę produktów.
    void countSetActualProductsCost();
    /**
     * @brief Kup produkty od producentów.
     *
     *Metoda kupuje wybraną ilość produktów od producentów z listy. Producenti zyskują pieniądze, a rynek produkty.
     */
    void takeAndPayPBForProducts();
    /**
     * @brief Podziel i wyślij produkty do sklepów
     *
     *Metoda dzieli i sprzedaje produkty do sklepów z listy w zależności od ich potrzeb. Sklepy tracą gotówkę, lecz zyskują produkty.
     */
    void splitAndSendProductsToShops();
    ///CZyści zmienne tymczasowe.
    void clearTemporary();

    //lists
    ///Czyści listę potrzeb sklepów
    void clearShopsNeedsList();
    ///Czyści listę produkcji
    void clearProductsPerTickAvailableList();
    ///Czyści listę zeskładowanych produktów.
    void clearStackedProductsAvailableList();
    /**
     * @brief Dodaj sklep do listy potrzeb
     *
     * @param _shop - wskaźnik do kontenera
     * @return Zwraca true jeśli się powiodło.
     */
    bool addShopToShopsNeedList(CProductsBuildingPointer* _shop);/**
     * @brief Dodaj producenta do listy producentów
     *
     * @param _productionB - wskaźnik do kontenera
     * @return Zwraca true jeśli się powiodło.
     */
    bool addPBToProductsPerTickList(CProductsBuildingPointer* _productionB);
    /**
     * @brief Dodaj producenta do listy producentów
     *
     * @param _productionB - wskaźnik do kontenera
     * @return Zwraca true jeśli się powiodło.
     */
    bool addPBToStackedProductsAvailableList(CProductsBuildingPointer* _productionB);

    QVector<CProductsBuildingPointer*> getShopsNeedsList();
    QVector<CProductsBuildingPointer*> getProductsPerTickAvailableList();
    QVector<CProductsBuildingPointer*> getStackedProductsAvailableList();
    CProducts getBaseProductsCost();
    CProducts getActualProductsCost();

    void setBaseProductsCost(CProducts _cost);
    void setBaseProductsCostFood(double _cost);
    void setBaseProductsCostLight(double _cost);
    void setBaseProductsCostHeavy(double _cost);
    void setActualProductsCost(CProducts _cost);
};

#endif // CMARKET_H
