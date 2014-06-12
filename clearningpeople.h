#ifndef CLEARNINGPEOPLE_H
#define CLEARNINGPEOPLE_H

#include "cpeople.h"
#include "enumerators.h"

/**
 * @brief Klasa CLearningPeople (ludzie uczący się)
 *
 *Klasa jest kontenerem pozwalającym na przechowywanie informacji o ludziach uczących się na dane profesje.
 *Pozwala określić ilość ludzi oraz stopień zawansowania edukacji.
 */
class CLearningPeople : public CPeople
{
protected:
    ///Wartość wyedukowania ludzi na stanowisko Lead
    double leadWorkerEdu;
    ///Wartość wyedukowania ludzi na stanowisko Service
    double serviceWorkerEdu;
    ///Wartość wyedukowania ludzi na stanowisko Light
    double lightWorkerEdu;
    ///Wartość wyedukowania ludzi na stanowisko Heavy
    double heavyWorkerEdu;
    ///Wartość wyedukowania ludzi na stanowisko Low
    double lowWorkerEdu;
public:
    CLearningPeople();
    /**
     * @brief CLearningPeople - konstruktor
     *
     *Konstruktor z parametrami.
     *Inicjalizuje atrybuty obiektu wartościami parametrów.
     *Ustawia zerową ilość osób.
     */
    CLearningPeople(double _lead, double _serv, double _light,double _heavy, double _low);
    /**
     * @brief CLearningPeople - konstruktor
     *
     *Konstruktor z parametrami.
     *Inicjalizuje atrybuty obiektu wartościami parametrów.
     *Ustawia parametryczną ilość osób.
     */
    CLearningPeople(CPeople _P,double _lead, double _serv, double _light,double _heavy, double _low);
    ///Konstruktor kopiujący.
    CLearningPeople(const CLearningPeople& _P);
    ///Operator dodawania.
    CLearningPeople operator+ (CLearningPeople _P);
    ///Operator dodawania z przypisaniem.
    CLearningPeople& operator+= (CLearningPeople const &_P);
    ///Operator odejmowania z przypisaniem.
    CLearningPeople& operator-= (CLearningPeople const &_P);
    ///Operator przypisania.
    CLearningPeople& operator= (CLearningPeople const &_P);

    /**
     * @brief Sprawdź kto jest wyedukowany.
     *
     *Metoda sprawdza jakie osoby w obiekcie są juz wyedukowane i mogą przestać się uczyć.
     * @return Ilość ludzi wyedukowanych.
     * @warning Pobiera tylko ich ilość, lecz nie usuwa z obiektu.
     */
    CPeople getWhoIsEducated();
    /**
     * @brief Ekstraktuj kto jest wyedukowany.
     *
     *Metoda sprawdza jakie osoby w obiekcie są juz wyedukowane i mogą przestać się uczyć.
     * @return Ilość ludzi wyedukowanych.
     *@warning Usuwa wyedukowanych ludzi.
     */
    CPeople extractWhoIsEducated();

    /**
     * @brief Wyedukuj ludzi.
     *
     *Powoduje dodanie ludziom edukacji.
     * @param _edu - wartość dodanej edukacji.
     */
    void addAllEducation(double _edu);
    ///Dodaj edukację dla Lead
    void addLeadWorkerEdu(double _number);
    ///Dodaj edukację dla Service
    void addServiceWorkerEdu(double _number);
    ///Dodaj edukację dla Light
    void addLightWorkerEdu(double _number);
    ///Dodaj edukację dla Heavy
    void addHeavyWorkerEdu(double _number);
    ///Dodaj edukację dla Low
    void addLowWorkerEdu(double _number);

    ///Pobierz poziom wyedukowania Lead
    double getLeadWorkerEdu() const;
    ///Pobierz poziom wyedukowania Service
    double getServiceWorkerEdu() const;
    ///Pobierz poziom wyedukowania Light
    double getLightWorkerEdu() const;
    ///Pobierz poziom wyedukowania Heavy
    double getHeavyWorkerEdu() const;
    ///Pobierz poziom wyedukowania Low
    double getLowWorkerEdu() const;

    ///Ustaw aktualny poziom wyedukowania Lead
    void setLeadWorkerEdu(double _number);
    ///Ustaw aktualny poziom wyedukowania Service
    void setServiceWorkerEdu(double _number);
    ///Ustaw aktualny poziom wyedukowania Light
    void setLightWorkerEdu(double _number);
    ///Ustaw aktualny poziom wyedukowania Heavy
    void setHeavyWorkerEdu(double _number);
    ///Ustaw aktualny poziom wyedukowania Low
    void setLowWorkerEdu(double _number);
};

#endif // CLEARNINGPEOPLE_H
