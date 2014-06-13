#ifndef CPEOPLEEARNINGS_H
#define CPEOPLEEARNINGS_H

/**
 * @brief Klasa CPeopleEarnings (zarobki ludzi)
 *
 *Klasa kontener pozwalajaća na przechowywanie informacji o zarobkach ludzi.
 *Udostępnia proste działania matematyczne.
 */
class CPeopleEarnings
{
protected:
    double leadWorkerEarn;
    double serviceWorkerEarn;
    double lightWorkerEarn;
    double heavyWorkerEarn;
    double lowWorkerEarn;
public:
    CPeopleEarnings();
    /**
     * @brief CPeopleEarnings  - konstruktor
     *
     *Inicjalizuje atrybuty obiektu wartościami z parametrów
     */
    CPeopleEarnings(double _lead, double _serv, double _light,double _heavy, double _low);
    CPeopleEarnings(const CPeopleEarnings& _P);
    CPeopleEarnings operator+ (CPeopleEarnings _P);
    CPeopleEarnings& operator+= (CPeopleEarnings const &_P);
    CPeopleEarnings& operator= (CPeopleEarnings const &_P);

    ///Dodaj kwotę do zarobków profesji Lead
    void addLeadWorkerEarn(double _number);
    ///Dodaj kwotę do zarobków profesji Service
    void addServiceWorkerEarn(double _number);
    ///Dodaj kwotę do zarobków profesji Light
    void addLightWorkerEarn(double _number);
    ///Dodaj kwotę do zarobków profesji Heavy
    void addHeavyWorkerEarn(double _number);
    ///Dodaj kwotę do zarobków profesji Low
    void addLowWorkerEarn(double _number);

    double getLeadWorkerEarn() const;
    double getServiceWorkerEarn() const;
    double getLightWorkerEarn() const;
    double getHeavyWorkerEarn() const;
    double getLowWorkerEarn() const;

    void setLeadWorkerEarn(double _number);
    void setServiceWorkerEarn(double _number);
    void setLightWorkerEarn(double _number);
    void setHeavyWorkerEarn(double _number);
    void setLowWorkerEarn(double _number);
};

#endif // CPEOPLEEARNINGS_H
