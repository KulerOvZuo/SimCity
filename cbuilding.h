#ifndef CBUILDING_H
#define CBUILDING_H

#include "cstructureforpeople.h"
#include "cutilitiesglobal.h"
#include "cpeopleneeds.h"

/**
 * @brief Klasa CBuilding (budynek)
 *
 *Klasa nadrzędna wobec wszystkich budynków.
 *Dodaje aktualne posiadane pieniadze dla budynku oraz potrzeby komunalne.
 */
class CBuilding : public CStructureForPeople
{
protected:
    ///Pieniądze.
    double money;
    ///Potrzeby komunalne
    CUtilitiesGlobal utilities;

public:
    CBuilding();
    CBuilding(const CBuilding& _B);
    /**
     * @brief CBuilding - konstruktor
     *
     *Konstruktor inicjalizuje atrybuty wartościami parametrów.
     */
    CBuilding(double _money, CUtilitiesGlobal _U);
    virtual ~CBuilding();
    virtual QList<QString> infoToDisplay();

    /**
     * @brief Wyślij informację o potrzebach komunalnych do miasta.
     */
    virtual bool sendUtilitiesToCity();
    ///Oblicz przychód.
    virtual double countIncome();
    ///Wyślij podatki do miasta.
    virtual bool sendTaxes();
    ///Wyczyść zmienne pomocnicze.
    virtual void clearTemporary();

    bool addMoney(double _money);

    bool setMoney(double _money);
    bool setUtilities(CUtilitiesGlobal _U);
    double getMoney() const;
    CUtilitiesGlobal getUtilities() const;

};

/**
 * @brief Klasa CProductsBuildingPointer (kontener produktów ze wskaźnikiem do budynku)
 *
 *Klasa będąca kontenerem pośredniczącym w przekazywaniu informacji pomiędzy budynkami.
 *Zawiera produkty oraz wskaźnik do budynku z nimi powiązanego.
 */
class CProductsBuildingPointer
{
protected:
    ///Produkty.
    CProducts products;
    ///Wskaźnik do budynku powiązanego.
    CBuilding* building;
public:
    CProductsBuildingPointer();
    CProductsBuildingPointer(const CProductsBuildingPointer& _PB);
    virtual ~CProductsBuildingPointer();

    CProducts getProducts() const;
    CBuilding* getBuilding() const;

    void setProducts(CProducts _prod);
    void setBuilding(CBuilding* _building);
};
/**
 * @brief Klasa CPeopleNeedsBuildingPointer (kontener potrzeb ludzi ze wskaźnikiem do budynku)
 *
 *Klasa będąca kontenerem pośredniczącym w przekazywaniu informacji pomiędzy budynkami.
 *Zawiera potrzeby ludzi oraz wskaźnik do budynku z nimi powiązanego.
 */
class CPeopleNeedsBuildingPointer
{
protected:
    ///Potrzeby ludzi.
    CPeopleNeeds peopleNeeds;
    ///Wskaźnik do budynku powiązanego.
    CBuilding* building;
public:
    CPeopleNeedsBuildingPointer();
    CPeopleNeedsBuildingPointer(const CPeopleNeedsBuildingPointer& _PB);
    virtual ~CPeopleNeedsBuildingPointer();

    CPeopleNeeds getPeopleNeeds() const;
    CBuilding* getBuilding() const;

    void setPeopleNeeds(CPeopleNeeds _peopleNeeds);
    void setBuilding(CBuilding* _building);
};
#endif // CBUILDING_H
