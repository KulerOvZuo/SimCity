#ifndef CSHOP_H
#define CSHOP_H

#include "cworking.h"
#include "cpeopleneeds.h"
#include "cliving.h"

/**
 * @brief Klasa CShop (sklep)
 *
 *Klasa nadrzędna w stosunku do wszystkich budynków mogących sprzedawać produkty.
 *Komunikuje sie z ludźmi i rynkiem obrotu dóbr.
 */
class CShop : public CWorking
{
protected:
    ///Lista potrzebnych produktów od danych budynków
    QList<CProductsBuildingPointer*> listOfLivingNeeds;
    CProducts productsNeedFromPeople;
    CProducts productsGotFromMarket;
    ///Aktualna cena sprzedaży produktów ludziom.
    CProducts productsSellPrice;
    ///Dochody.
    double income;
public:
    CShop();
    CShop(const  CShop& _S);
    virtual ~CShop();
    virtual QList<QString> infoToDisplay();
    virtual bool setRandomName(int size);

    /**
     * @brief Wyślij potrzeby produktów do rynku
     *
     *Wysyłą potrzeby.
     * @return Jeśli nie można wysłać, zwraca false.
     */
    bool sendProductsNeedToMarket();
    ///Oblicza i ustawia aktualna cenę produktów sklepu.
    CProducts countSetProductsSellPrice();
    /**
     * @brief Zapłać pracownikom
     *
     *Metoda powoduje zapłacenie pracownikom należnych pieniędzy.
     *Pomniejsza wartość dochodu.
     */
    void payWorkers();
    /**
     * @brief Wyślij produkty do ludzi
     *
     *Metoda powoduje wysłanie otrzymanych produktów od mrynku, do ludzi.
     *Przychód powieksza się o wartość zarobioną.
     * @return Zwraca false jeśli nie może wykonać sprzedaży.
     */
    bool sendProductsToLivings();

    /**
     * @brief Kup produkty od rynku
     *
     *Powoduje wykunienie produktów z rynku.
     * @param _prod - ilość produktów do kupienia.
     * @return zwraca false, jeśli nie udało się kupić.
     */
    bool buyProductsGotFromMarket(CProducts _prod);
    double giveTaxes(double _tax);
    ///Wyczyść listę potrzeb ludzi.
    void clearListOfLivingNeeds();
    ///Dodaj potrzebne produkty ludzi do listy potrzebnych produktów.
    bool addLivingToProductsNeeds(CProductsBuildingPointer* _living);
    ///Wyczyść zmienne czasowe.
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

/**
 * @brief Klasa CSmallShop (mały sklep)
 */
class CSmallShop : public CShop
{
protected:
public:
    CSmallShop();
    CSmallShop(const CSmallShop& _S);
    virtual ~CSmallShop();
};

#endif // CSHOP_H
