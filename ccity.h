#ifndef CCITY_H
#define CCITY_H

#include <QObject>
#include <QSize>
#include "cutilitiesglobal.h"
#include "cmarket.h"
#include "ctaxes.h"
#include "csocietyindicators.h"
#include "cmapofstructures.h"
#include "enumerators.h"
#include "ctrafficengine.h"

/** @file Deklaracja klasy CCity (bierzące miasto).
 */
/**
 * @brief Klasa CCity (miasto). Główna klasa implementująca model miasta.
 *
 *Odpowiada za przechowywanie złożonych zmiennych oraz matematyczną symulację życia miasta.
 */
class CCity
{
protected:
    ///Obiekt przechowujący dostępną ilość usług komunalnych.
    CUtilitiesGlobal utilitiesGlobalProduction;
    ///Obiekt przechowujący potrzebną ilość usług komunalnych.
    CUtilitiesGlobal utilitiesGlobalNeed;
    ///Obiekt będący rynkiem obrotu zasobami miasta.
    CMarket* market;
    ///Obiekt przechuwujący aktualne ustawienia podatków w mieście.
    CTaxes* taxes;
    ///Obiekt odpowiedzialny za społeczne wskaźniki.
    CSocietyIndicators* societyIndicators;
    ///Mapa struktur w mieście.
    CMapOfStructures* mapOfStructures;
    ///Silnik korków.
    CTrafficEngine* trafficEngine;
    ///Aktualna ilość pieniędzy w budżecie miasta.
    double money;
    ///Aktualne przychody miasta na turę.
    double income;
public:
    CCity();
    virtual ~CCity();

    /**
     * @brief Wykonaj turę życia miasta.
     *
     *Główna metoda odpowiadająca za symulację życia miasta.
     *Wykonuje jeden cykl czasowy życia. Powoduje wywoływanie odpowiednich złożonych metod obiektów znajdujących się w mieście, przekazywanie po między nimi informacji.
     *M.in. przepływ produktów i usług pomiędzy budynkami, rozwój mieszkańców, obliczanie aktualnych cen produktów i płac pracowników, pobieranie podatków, obliczanie aktualnych korków
     */
    void makeTick();
    /**
     * @brief Inicjalizacja miasta.
     *
     *Metoda powodująca poprawne zainicjalizowanie wszystkich obiektów w mieście.
     * @param mapSize - rozmiar miasta(x,y) w żetonach gry
     */
    void initializeCity(QSize mapSize);
    /**
     * @brief Koszt utrzymania struktur publicznych.
     *
     *Metoda obliczająca i zwracająca koszt utrzymania wszystkich struktur publicznych.
     */
    double publicBuildingsKeepCost();
    /**
     * @brief Pobierz podatki.
     *
     *Metoda pobiera podatki od budynków w zależności od ustawionych wartości podatków w mieście oraz od aktualnego dochodu danego budynku.
     *
     * @return Łączna kwota podatków zebranych.
     * @warning Przychód miasta jest automatycznie powiększany o tę kwotę.
     */
    double takeTaxes();
    /**
     * @brief Dodaj strukturę.
     *
     * Dodaje strukturę do modelu miasta.
     * @param _S - struktura, którą należy dodać.
     * @return Czy dodano.
     * @warning Metoda nie jest odpowiedzialna za "zbudowanie".
     */
    bool addStructureProperly(CStructure* _S);
    /**
     * @brief removeStructureProperly
     *
     * Usuwa daną strukturę z modelu.
     * @param _S - strkuktura, którą należy usunąć.
     * @return Czy usunięto.
     * @warning Metoda nie jest odpowiedzialna za "rozebranie" budynku.
     */
    bool removeStructureProperly(CStructure* _S);

    /**
     * @brief Dodaj komunalne potrzeby.
     *
     *Dodaje do miasta komunalne potrzeby.
     * @param _U - potrzeby komunalne
     */
    void addUtilitiesGlobalNeed(CUtilitiesGlobal _U);
    /**
     * @brief Dodaj pieniądze.
     *
     *Dodaje określoną funkcję pieniędzy do budżetu miasta.
     * @param _money - ilość pieniędzy do dodania.
     */
    void addMoney(double _money);

    //getters, not const
    ///Pobiera wartość dostępnych usług komunalnych.
    CUtilitiesGlobal getUtilitiesGlobalProduction();
    ///Pobiera wartość potrzebnych usług komunalnych.
    CUtilitiesGlobal getUtilitiesGlobalNeed();
    ///Pobiera wskaźnik to rynku miasta.
    CMarket* getMarket();
    ///Pobiera wskaźnik do podatków.
    CTaxes* getTaxes();
    ///Pobiera wskaźnik do społecznych wskaźników.
    CSocietyIndicators* getSocietyIndicators();
    ///Pobiera wskaźnik do mapy struktur.
    CMapOfStructures* getMapOfStructures();
    ///Pobiera wskaźnik do silnika korków.
    CTrafficEngine* getTrafficEngine();
    ///Pobiera aktualną wartość pieniędzy w budżecie miasta.
    double getMoney();
    ///Pobiera aktualną wartość przychodu na turę miasta.
    double getIncome();

    //setters
    ///Ustawia wartość dostępnych usług komunalnych.
    void setUtilitiesGlobalProduction(CUtilitiesGlobal _U);
    ///Ustawia wartość potrzebnych usług komunalnych.
    void setUtilitiesGlobalNeed(CUtilitiesGlobal _U);
    ///Ustawia wskaźnik to rynku miasta.
    void setMarket(CMarket* _M);
    ///Ustawia wskaźnik do podatków.
    void setTaxes(CTaxes* _T);
    ///Pobiera wskaźnik do społecznych wskaźników.
    void setSocietyIndicators(CSocietyIndicators* _S);
    ///Ustawia wskaźnik do mapy struktur.
    void setMapOfStructures(CMapOfStructures* _M);
    ///Ustawia wskaźnik do silnika korków.
    void setTrafficEngine(CTrafficEngine* _engine);
    ///Ustawia aktualną wartość pieniędzy w budżecie miasta.
    void setMoney(double _money);

};

#endif // CCITY_H
