#ifndef CLEARNINGPEOPLE_H
#define CLEARNINGPEOPLE_H

#include "cpeople.h"
#include "enumerators.h"

class CLearningPeople : public CPeople
{
protected:
    double leadWorkerEdu;
    double serviceWorkerEdu;
    double lightWorkerEdu;
    double heavyWorkerEdu;
    double lowWorkerEdu;
public:
    CLearningPeople();
    CLearningPeople(double _lead, double _serv, double _light,double _heavy, double _low);
    CLearningPeople(CPeople _P,double _lead, double _serv, double _light,double _heavy, double _low);
    CLearningPeople(const CLearningPeople& _P);
    CLearningPeople operator+ (CLearningPeople _P);
    CLearningPeople& operator+= (CLearningPeople const &_P);
    CLearningPeople& operator-= (CLearningPeople const &_P);
    CLearningPeople& operator= (CLearningPeople const &_P);

    CPeople getWhoIsEducated();
    CPeople extractWhoIsEducated();

    void addAllEducation(double _edu);
    void addLeadWorkerEdu(double _number);
    void addServiceWorkerEdu(double _number);
    void addLightWorkerEdu(double _number);
    void addHeavyWorkerEdu(double _number);
    void addLowWorkerEdu(double _number);

    double getLeadWorkerEdu() const;
    double getServiceWorkerEdu() const;
    double getLightWorkerEdu() const;
    double getHeavyWorkerEdu() const;
    double getLowWorkerEdu() const;

    void setLeadWorkerEdu(double _number);
    void setServiceWorkerEdu(double _number);
    void setLightWorkerEdu(double _number);
    void setHeavyWorkerEdu(double _number);
    void setLowWorkerEdu(double _number);
};

#endif // CLEARNINGPEOPLE_H
