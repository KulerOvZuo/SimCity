#ifndef CWORKING_H
#define CWORKING_H

#include "cbuilding.h"
#include "cpeople.h"

/**
 * @brief Klasa CWorking (budynki do pracy)
 *
 *Klasa jest klasą nadrzędną dla wszystkich budynków w których można pracować.
 *Udostępnia dane o ludziach pracująćych i potrzebnych do pracy.
 */
class CWorking : public CBuilding
{
protected:
    ///Łącznie potrzebna kadra
    CPeople neededNumberOfWorkers;
    ///Aktualni pracownicy w danych profesjach
    CPeople actualNumberOfWorkers;
public:
    CWorking();
    CWorking(const CWorking& _W);
    CWorking(const CWorking& _W, CPeople _need, CPeople _actual);
    virtual~CWorking();

    ///Wyślij informację o pracy do miasta.
    void sendWorkInfoToCity();
    /**
     * @brief Zniszcz.
     *
     *Reimplementacja metody z\b CStructure\c. Dodatkowo pozbawia ludzi pracy.
     * @return
     */
    virtual bool destroy();
    virtual QList<QString> infoToDisplay();

    ///Dodaj pracowników danych profesji
    bool addWorkers(CPeople _P); //if number of people to add is too high
    /**
     * @brief Oblicz wydajność pracowników
     *
     *Oblicza wydajność pracowników w zależności od aktualnej i potrzebnej kadry.
     * @return Zwraca wartość wydajności.
     */
    double countPeopleEfficiency(); //linear efficiency
    /**
     * @brief Oblicz wydajność budynku.
     *
     *@return Zwraca wartość wydajności budynku.
     */
    virtual double countBuildingEfficiency(); //linear efficiency
    CPeople getNeededNumberOfWorkers() const;
    CPeople getActualNumberOfWorkers() const;
    bool setActualNumberOfWorkers(CPeople _P);
    bool setNeededNumberOfWorkers(CPeople _P);
};

#endif // CWORKING_H
