#ifndef CSOCIETYINDICATORS_H
#define CSOCIETYINDICATORS_H

#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "idisplayinginterface.h"
#include <qglobal.h>
#include <QTime>
#include <cmath>

/**
 * @brief Klasa CSocietyIndicators (społeczne wskaźniki)
 *
 *Klasa pozwala m.in. na przechowywanie informacji o ludziach w mieście,
 *analizowaniu i podawaniu informacji jakie zawody są najbardziej potrzebne
 *oraz ustalaniu płac pracowników.
 */
class CSocietyIndicators : public IDisplayingInterface
{
protected:
    ///Aktualne zarobki ludzi.
    CPeopleEarnings peopleEarnings;
    ///Bazowe zarobki ludzi.
    CPeopleEarnings basePeopleEarnings;
    ///Ilość wszystkich ludzi z wyjątkiem dzieci
    CPeople allPeople;
    ///Wszyscy pracujący ludzie.
    CPeople allLivingWorkingPeople;
    ///Wszyscy niepracujący ludzie.
    CPeople allLivingNotWorkingPeople;
    ///Wszyscy uczący się ludzie.
    CPeople allLearningPeople;
    ///Całe dostepne zatrudnienie dla ludzi.
    CPeople allWorkForPeople; //from cworking
    ///Wyznaczona liczba danych profesji do wyedukowania.
    CPeople allProfessionsToEducate; //how many people educate
    ///Ilość dzieci w mieście.
    int children;
    ///Wskaźnik urodzeń.
    double birthIndicator;
public:
    CSocietyIndicators();
    ///Konstruktor kopiujący.
    CSocietyIndicators(const CSocietyIndicators& _I);
    virtual ~CSocietyIndicators();
    ///Usuń zmienne pomocnicze.
    void clearTemporary();

    /**
     * @brief Oblicz wartość zarobków ludzi.
     *
     *Zwraca oraz ustawia wyliczoną wartość zarobków ludzi.
     *Wartość zależna m.in. od bazowych zarobków i zapotrzebowania na pracę.
     */
    CPeopleEarnings countSetPeopleEarnings();
    /**
     * @brief Oblicz profesje do edukacji.
     *
     *Zwraca i ustawia wyznaczoną ilość profesji do edukacji.
     *Wartość zależna m.in. od ilości dzieci i ilości miejsc pracy.
     */
    CPeople countSetProffesionsToEducate();

    ///Dodaj dzieci.
    void addChildren(int _children);
    ///Dodaj współczynnik urodzeń
    void addBirthIndicator(double _birth);
    /**
     * @brief Wyznacz potrzebne profesje
     *
     *Wyznacza potrzebne w mieście profesje w danej chwili szukając wolnych miejsc pracy.
     * @return Ilość wolnych miejsc pracy.
     */
    CPeople countProffesionsNeed();

    ///Pobierz zarobki ludzi
    CPeopleEarnings getPeopleEarnings() const;
    ///Pobierz bazowe zarobki ludzi
    CPeopleEarnings getBasePeopleEarnings() const;
    ///Pobierz ilość ludzi
    CPeople getAllPeople() const;
    ///Pobierz ilość wszystkich pracujących ludzi
    CPeople getallLivingWorkingPeople() const;
    ///Pobierz ilość wszystkich niepracujących ludzi
    CPeople getallLivingNotWorkingPeople() const;
    ///Pobierz ilość wszystkich uczących się ludzi
    CPeople getAllLearningPeople() const;
    ///Pobierz ilość wszyskich miejsc pracy dla ludzi
    CPeople getAllWorkForPeople() const;
    ///Pobierz ilość profecji do edukacji
    CPeople getAllProfessionsToEducate() const;
    ///Pobierz ilość dzieci
    int getChildren() const;
    ///Pobierz wskaźnik urodzeń
    double getBirthIndicator() const;

    ///Ustaw zarobki ludzi
    void setPeopleEarnings(CPeopleEarnings _earn);
    ///Ustaw bazowe zarobki ludzi
    void setBasePeopleEarnings(CPeopleEarnings _earn);
    ///Ustaw bazowe zarobki Lead
    void setBasePeopleEarningsLead(double _earn);
    ///Ustaw bazowe zarobki Service
    void setBasePeopleEarningsService(double _earn);
    ///Ustaw bazowe zarobki Light
    void setBasePeopleEarningsHeavy(double _earn);
    ///Ustaw bazowe zarobki Heavy
    void setBasePeopleEarningsLight(double _earn);
    ///Ustaw bazowe zarobki Low
    void setBasePeopleEarningsLow(double _earn);
    ///Ustaw ilość ludzi
    void setAllPeople(CPeople _people);
    ///Ustaw ilość wszystkich pracujących ludzi
    void setAllLivingWorkingPeople(CPeople _people);
    ///Ustaw ilość wszystkich niepracujących ludzi
    void setAllLivingNotWorkingPeople(CPeople _people);
    ///Ustaw ilość wszystkich uczących się ludzi
    void setAllLearningPeople(CPeople _people);
    ///Ustaw ilość wszyskich miejsc pracy dla ludzi
    void setAllWorkForPeople(CPeople _people);
    ///Ustaw ilość profecji do edukacji
    void setAllProfessionsToEducate(CPeople _people);
    ///Ustaw ilość dzieci
    void setChildren(int _children);
    ///Ustaw wskaźnik urodzeń
    void setBirthIndicator(double _birth);
};

#endif // CSOCIETYINDICATORS_H
