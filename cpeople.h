#ifndef CPEOPLE_H
#define CPEOPLE_H

#include <qglobal.h>
#include <QTime>
#include "cpeopleearnings.h"

/**
 * @brief Klasa CPeople (ludzie)
 *
 *Klasa pozwala na przechowywanie informacji o ludziach z podziałem na profesje.
 *Udostepnia złożone działania matematyczne na obiektach.
 *Pozwala na kontrolę błędów. Jest możliwość włączenia elementu losowości.
 */
class CPeople
{
protected:
    ///Ilość ludzi Lead
    int leadWorker;
    ///Ilość ludzi Service
    int serviceWorker;
    ///Ilość ludzi Light
    int lightWorker;
    ///Ilość ludzi Heavy
    int heavyWorker;
    ///Ilość ludzi Low
    int lowWorker;

public:
    CPeople();
    /**
     * @brief CPeople  - konstruktor
     *
     *Inicjalizuje atrybuty obiektu wartościami z parametrów.
     */
    CPeople(int _lead, int _serv, int _light,int _heavy, int _low);
    CPeople(const CPeople& _P);
    CPeople operator+ (CPeople _P);
    CPeople& operator+= (CPeople const &_P);
    CPeople& operator-= (CPeople const &_P);
    CPeople& operator= (CPeople const &_P);

    /**
     * @brief Napraw jeśli nie dodatnie.
     *
     *Jeśli ilości ludzi są mniejsze od 0, powoduje ustawienie danego na 0.
     * @return Zwraca false jeśli potrzebna była naprawa.
     */
    bool restoreIfNotPossitiveNOPeople();
    /**
     * @brief Dodaj losowo
     *
     *Dodaje ludzi do losowych profesji.
     * @param _free - ilosć ludzi do dodania
     */
    void randomAdd(int _free);
    /**
     * @brief Odejmij losowo
     *
     *Odejmuje ludzi od losowych profesji.
     * @param _free - ilosć ludzi do odjęcia
     */
    void randomSubb(int _free);
    /**
     * @brief Ekstraktuj losowo ludzi od profesji
     *
     *Odejmuje ludzi od losowych profesji oraz zwraca.
     * @param _free - ilosć ludzi do odjęcia
     * @return Zwraca odjęte profesje.
     */
    CPeople randomExtract(int _free);
    ///Zwraca losową liczbę z zakresu <min,max>
    int randBetween(int min, int max);
    /**
     * @brief Pomnóż indywidualnie
     *
     *Metoda pozwala na pomnożenie ilości ludzi w danej profesji i zarobków danej profesji,
     *i zwraca wartość w postaci zarobków.
     * @param _multiply - zarobki danej profesji
     */
    CPeopleEarnings multiplyIndividualPeopleBy(CPeopleEarnings _multiply);
    /**
     * @brief Zwróć double z indywidualnego mnożenia
     *
     *Metoda pozwala na pomnożenie ilości ludzi w danej profesji i zarobków danej profesji,
     *i zwraca wartość sumy zarobków.
     * @param _multiply - zarobki wszystkich ludzi
     */
    double getDoubleMultiplyIndividualPeopleBy(CPeopleEarnings _multiply);
    ///Dodaje określoną w parametrach ilość ludzi do każdego typu
    void addAll(int _lead, int _serv, int _light,int _heavy, int _low);
    void addLeadWorker(int _number);
    void addServiceWorker(int _number);
    void addLightWorker(int _number);
    void addHeavyWorker(int _number);
    void addLowWorker(int _number);

    int getAllPeople() const;
    int getLeadWorker() const;
    int getServiceWorker() const;
    int getLightWorker() const;
    int getHeavyWorker() const;
    int getLowWorker() const;

    void setAll(int _lead, int _serv, int _light,int _heavy, int _low);
    void setLeadWorker(int _number);
    void setServiceWorker(int _number);
    void setLightWorker(int _number);
    void setHeavyWorker(int _number);
    void setLowWorker(int _number);

};

#endif // CPEOPLE_H
