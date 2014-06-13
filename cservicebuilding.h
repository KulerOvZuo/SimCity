#ifndef CSERVICEBUILDING_H
#define CSERVICEBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"
#include "cpeopleearnings.h"

/**
 * @brief Klasa CServiceBuilding (budynek usługowy)
 *
 *Klasa nadrzędna dla wszystkich budynków usługowych w mieście.
 *Budynki te udostępniają usługi innym budynkom.
 */
class CServiceBuilding  : public CWorking
{
protected:
    ///Lista potrzeb danych budynków.
    QVector<CPeopleNeedsBuildingPointer*> listOfLivingNeeds;
    ///Suma potrzeb potrzebnych ludziom.
    CService serviceNeedFromPeople;
    ///Bazowa wartość współczynnika usługi.
    CService baseService;
    ///Aktualna wartość współczynnika usługi.
    CService actualService;
    ///Bazowa cena usługi.
    CService baseServiceCost;
    ///Aktualna cena usługi.
    CService actualServiceCost;
    ///Dochody.
    double income;

public:
    CServiceBuilding();
    CServiceBuilding(const CServiceBuilding& _S);
    virtual ~CServiceBuilding();
    virtual QList<QString> infoToDisplay();
    virtual bool setRandomName(int size);

    /**
     * @brief Zapłać pracownikom
     *
     *Metoda powoduje zapłacenie pracownikom należnych pieniędzy.
     *Pomniejsza wartość dochodu.
     */
    void payWorkers();
    ///Oblicz i ustaw aktualny koszt usług.
    void countSetActualServiceCost();
    ///Oblicz i ustaw acktualną wartość współczynnika usług.
    void countSetServiceQuality();
    /**
     * @brief Wykonaj usługi ludziom
     *
     *Metoda powoduje wykonanie usług na rzecz ludzi, którzy zlecili wykonanie.
     *Przychód powieksza się o wartość zarobioną.
     * @return Zwraca false jeśli nie może wykonać usług.
     */
    bool giveServiceToLivings();

    //list
    ///Dodaj budynek do listy potrzebnych usług.
    bool addLivingTolist(CPeopleNeedsBuildingPointer* _living);
    ///Wyczyść listę potrzeb ludzi.
    void clearListOfLivingNeeds();
    ///Wyczyść zmienne czasowe.
    void clearTemporary();

    double countBuildingEfficiency();    
    double giveTaxes(double _tax);    

    CService getBaseService() const;
    CService getActualService() const;
    CService getBaseServiceCost() const;
    CService getActualServiceCost() const;
    double getIncome() const;

    void setBaseService(CService _base);
    void setActualService(CService _actual);
    void setBaseServiceCost(CService _base);
    void setActualServiceCost(CService _actual);
    void setIncome(double _inc);
};
/**
 * @brief Klasa COffice (biurowiec)
 */
class COffice : public CServiceBuilding
{
protected:
public:
    COffice();
    COffice(const COffice& _O);
    virtual ~COffice();
};
#endif // CSERVICEBUILDING_H
