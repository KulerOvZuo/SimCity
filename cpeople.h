#ifndef CPEOPLE_H
#define CPEOPLE_H

#include <qglobal.h>
#include <QTime>
#include "cpeopleearnings.h"

class CPeople
{
protected:
    int leadWorker;
    int serviceWorker;
    int lightWorker;
    int heavyWorker;
    int lowWorker;
    int randBetween(int min, int max);
public:
    CPeople();
    CPeople(int _lead, int _serv, int _light,int _heavy, int _low);
    CPeople(const CPeople& _P);
    CPeople operator+ (CPeople _P);
    CPeople& operator+= (CPeople const &_P);
    CPeople& operator-= (CPeople const &_P);
    CPeople& operator= (CPeople const &_P);

    bool restoreIfNotPossitiveNOPeople();
    void randomAdd(int _free);
    CPeopleEarnings multiplyIndividualPeopleBy(CPeopleEarnings _multiply);
    double getDoubleMultiplyIndividualPeopleBy(CPeopleEarnings _multiply);
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
