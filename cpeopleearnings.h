#ifndef CPEOPLEEARNINGS_H
#define CPEOPLEEARNINGS_H

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
    CPeopleEarnings(double _lead, double _serv, double _light,double _heavy, double _low);
    CPeopleEarnings(const CPeopleEarnings& _P);
    CPeopleEarnings operator+ (CPeopleEarnings _P);
    CPeopleEarnings& operator+= (CPeopleEarnings const &_P);
    CPeopleEarnings& operator= (CPeopleEarnings const &_P);

    void addLeadWorkerEarn(double _number);
    void addServiceWorkerEarn(double _number);
    void addLightWorkerEarn(double _number);
    void addHeavyWorkerEarn(double _number);
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
