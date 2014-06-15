#ifndef CLIVING_H
#define CLIVING_H

#include "cbuilding.h"
#include "cpeopleneeds.h"
#include "cpeople.h"
#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "cschool.h"
#include "cshop.h"
#include "cservicebuilding.h"
#include <QVector>
#include <QList>

/**
 * @brief Klasa CLiving (budynek mieszkalny)
 *
 *Klasa nadrzędna dla wszystkich budynków mieszkalnych.
 *Udostępnia ona metody zmiązane z życiem ludzi takie jak: rodzenie się i umieranie, edukowanie, poszukiwanie pracy,
 *zmienianie miejsca zamieszkania czy wysyłanie potrzeb do odpowiednich budynków.
 */
class CLiving : public CBuilding
{
protected:
    /**
    * @brief Maksymalna ilość ludzi w budynku.
    *
    *Określa maksymalną ilość ludzi żyjących w budynku dla którego poziom życia jest jeszczy znośny.
    *Wartość ta nie jest wartością powyżej, której nie może być liczba ludzi mieszkających.
    */
    int maxLivingPeople;
    ///Pracujący ludzie.
    CPeople livingWorkingPeople;
    ///Niepracujący ludzie.
    CPeople livingNotWorkingPeople;
    ///Lista ludzi uczących się na dane profesje.
    QList<CLearningPeople*> learningPeopleList;
    /**
     * @brief Ilość dzieci
     *
     *Ilość dzieci, czyli osób które nie zaczęły jeszcze edukacji.
     */
    int children;
    ///Wskaźnik urodzeń.
    double birthRate;
    ///PrzychóD domu.
    double income;
    ///Aktualny współczynnik zadowolenia z życia.
    double lifeSatisfaction;
    /**
     * @brief Połaczona szkoła
     *
     *Aktualna szkoła w której ludzie pobierają edukację.
     */
    CSchool* schoolConnected;
    /**
     * @brief Potrzeby ludzi.
     *
     *Zmienna odpowiedzialna za przechowywanie informacji o aktualnych potrzebach na daną turę
     *oraz o potrzebach uzyskanych.
     */
    CPeopleNeeds peopleNeeds;
public:
    CLiving();
    CLiving(const CLiving& _L);
    virtual ~CLiving();
    virtual QList<QString> infoToDisplay();
    virtual bool setRandomName(int size);

    /**
     * @brief Szukaj w poszukiwaniu lepszej szkoły
     *
     *Metoda powoduje ze ludzie uczący się szukają lepszej szkoły.
     *Następuje przeniesienie uczniów.
     * @return Zwraca true, jeśli zmieniono szkołę.
     */
    bool searchSetForBetterSchool();
    /**
     * @brief Szukaj w poszukiwaniu sklepów
     *
     *Przeszukuje listę sklepów i rozdziela zapytania o potrzebne produkty korzystając z różnych wpółczynników.
     * @return Zwraca true, jeśli wykonano poprawnie.
     */
    bool searchAndSendNeedsToShops();
    /**
     * @brief Szukaj w poszukiwaniu usług
     *
     *Przeszukuje listę budynków usług i wysyła zapytania usług korzystając z różnych wpółczynników.
     * @return Zwraca true, jeśli wykonano poprawnie.
     */
    bool searchForService();
    ///Wysyła informacje o ludziach do miasta.
    void sendPeopleInfoToCity();
    ///Wysyła informacje o dzieciach do miasta.
    void sendChildrenInfoToCity();\
    /**
     * @brief Urodź i zabij
     *
     *Metoda polegająca na wytworzeniu cyklu życia i śmierci.
     *Powoduje uśmiercenie pewnej liczby osób oraz narodzenie nowych.
     *
     *@return Zwraca ilość martwych pracujących ludzi.
     */
    CPeople makeDeadsAndBorns();
    /**
     * @brief Zmień miejsce zamieszkania.
     *
     *Metoda odopwiedzialna za poszukiwanie innego miejsca zamieszkania.
     *Co turę część ludzi próbuję się przenieść w inne,lepsze miejsce korzystając z różnych współczynnik.
     * @return Zwraca true, jeśli zmieniono miejsce.
     */
    bool changeLivingPlace();
    ///Oblicza wskaźnik urodzeń
    double countSetBirthRate();
    ///Wysyła informacje o wskaźniku urodzeń do miasta.
    void sendBirthRateToCity();
    /**
     * @brief Oblicz i ustaw satysfakcję z życia oraz potrzebne produkty.
     *
     *Metoda oblicza i ustawia satysfakcję z życia, korzystając z informacji od zaspokojonych potrzebach,
     *a następnie wylicza nowe potrzeby i je ustawia.
     */
    void countSetLifeSatAndPeopleNeeds();
    /**
     * @brief Oblicz wpływ od innych.
     *
     *Metoda powoduje obliczenie wpływów sąsiednich struktur na nią.
     * @return
     */
    bool countSetInfluanceFromOthers();
    ///Pobierz i ustaw informację o korkach w swoim obszarze.
    double getSetTrafficInformation();
    /**
     * @brief Szukaj i idź do pracy
     *
     *Metoda powoduje wyszukiwanie przez osoby bezrobotne miejsc do pracy.
     *Metoda jest szęściowo losowa.
     */
    void searchAndGoToWork();
    ///Wyczyść zmienne pomocnicze.
    void clearTemporary();

    /**
     * @brief Kup produkty od sklepów
     *
     *Metoda powoduuje zakup produktów od sklepu po określonej cenie.
     *Ilość produktów kupionych nie jest większa niż potrzeb.
     * @param _prod - produkty do kupienia
     * @param _price - cena produktów
     * @return Zwraca true, jeśli zakupiono poprawnie.
     */
    bool buyProductsFromShop(CProducts _prod, CProducts _price);
    /**
     * @brief Pobierz usługi od budynków.
     *
     *Metoda pobranie usług od budynku usługowego po określonej cenie.
     * @param _serv - usługi do zaoferowania
     * @param _cost - cena usług
     * @return Zwraca true, jeśli zakupiono poprawnie.
     */
    bool takeServiceFromSB(CService _serv, CService _cost);
    /**
     * @brief Oblicz przychód.
     *
     *Metoda oblicza i ustawia przychód jaki został osiągnięty dzięki pracy ludzi.
     */
    void countSetIncome();

    ///Liczy satysfakcję z życia, korzystając z informacji o zaspokojonych potrzebach.
    double countLifeSatisfaction();
    double giveTaxes(double _tax);
    ///Wylicza nowe potrzeby i je ustawia, korzystajac z aktualnej satysfakcji.
    CPeopleNeeds countPeopleNeeds();

    //list
    ///Wybiera i dodaje profesję dzieciom
    void chooseChildrenProfessionsAndAdd();
    ///Dodaje do listy uczących się nową ilość osób
    void addNewLearningPeople(CPeople _professions);
    ///Dodaje do listy uczących się nową ilość osób uczących się
    void addLearningPeople(CLearningPeople* _learning);
    ///CZyści listę uczących się
    void clearListOfLearningPeople();
    /**
     * @brief Optymalizuj listę uczących się
     *
     *Metoda zapobiega pozostawianiu pustych obiektów na liście uczących się
     */
    void optimizeListOfLearningPeople();
    ///Podowuje wyedukowanie ludzi o współczynnik edukacji pochodzący z przyłączonej szkoły
    void educatePeople();
    /**
     * @brief Ekstraktuje ilość osób wyuczonych z listy uczących się
     *
     *Metoda usuwa osoby z listy uczących się i dodaje je do grupy osób niepracujących.
     */
    CPeople extractEducatedPeople();
    ///Zwraca liczbę wszystkich osób uczących się z domu
    CPeople getNumberOfLearningPeople();

    void setMaxLivingPeople(int _max);
    void setLivingWorkingPeople(CPeople _P);
    void setLivingNotWorkingPeople(CPeople _P);
    void setChildren(int _children);
    void setIncome(int _income);
    void setLifeSatisfaction( double _lifeSat);
    bool setSchool(CSchool* _school);
    void setPeopleNeeds(CPeopleNeeds _P);
    void setProductsNeed(CProducts _prod);
    void setServiceNeed(CService _serv);
    void setRecreationNeed(CRecreation _rec);
    void setTraffic(double _traf);
    void setDistrurbance(double _dist);

    ///Zwraca łączną ilość osób mieszkających z wyłączeniem dzieci
    int getAllPeopleLiving() const;
    int getMaxLivingPeople()const;
    CPeople getLivingWorkingPeople()const;
    CPeople getLivingNotWorkingPeople()const;
    QList<CLearningPeople*> getListOfLearningPeople() const;
    int getChildren()const;
    double getBirthRate() const;
    double getIncome()const;
    double getLifeSatisfaction()const;
    CSchool* getSchool()const;
    CPeopleNeeds getPeopleNeeds() const;
};

/**
 * @brief Klasa CBlocks (blok mieszkalny)
 */
class CBlocks : public CLiving
{
protected:
public:
    CBlocks();
    CBlocks(const CBlocks& _B);
};
/**
 * @brief Klasa CHouse (dom)
 */
class CHouse : public CLiving
{
protected:
public:
    CHouse();
    CHouse(const CHouse& _H);
};
#endif // CLIVING_H
