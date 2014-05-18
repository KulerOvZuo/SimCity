#include "cpeopleearnings.h"

CPeopleEarnings::CPeopleEarnings()
{
    leadWorkerEarn = 0;
    serviceWorkerEarn =0;
    lightWorkerEarn =0;
    heavyWorkerEarn =0;
    lowWorkerEarn = 0;
}
CPeopleEarnings::CPeopleEarnings(double _lead, double _serv, double _light,double _heavy, double _low)
{
    leadWorkerEarn = _lead;
    serviceWorkerEarn =_serv;
    lightWorkerEarn =_light;
    heavyWorkerEarn =_heavy;
    lowWorkerEarn = _low;
}
CPeopleEarnings::CPeopleEarnings(const CPeopleEarnings& _P)
{
    leadWorkerEarn = _P.getLeadWorkerEarn();
    serviceWorkerEarn =_P.getServiceWorkerEarn();
    lightWorkerEarn =_P.getLightWorkerEarn();
    heavyWorkerEarn =_P.getHeavyWorkerEarn();
    lowWorkerEarn = _P.getLowWorkerEarn();
}
CPeopleEarnings CPeopleEarnings::operator+ (CPeopleEarnings _P)
{
    return CPeopleEarnings(leadWorkerEarn+_P.getLeadWorkerEarn(),serviceWorkerEarn+_P.getServiceWorkerEarn(),
                   lightWorkerEarn+_P.getLightWorkerEarn(),heavyWorkerEarn+_P.getHeavyWorkerEarn(),lowWorkerEarn + _P.getLowWorkerEarn());
}
CPeopleEarnings& CPeopleEarnings::operator+= (CPeopleEarnings const &_P)
{
    this->leadWorkerEarn += _P.getLeadWorkerEarn();
    this->serviceWorkerEarn +=_P.getServiceWorkerEarn();
    this->lightWorkerEarn +=_P.getLightWorkerEarn();
    this->heavyWorkerEarn +=_P.getHeavyWorkerEarn();
    this->lowWorkerEarn += _P.getLowWorkerEarn();

    return *this;
}
CPeopleEarnings& CPeopleEarnings::operator= (CPeopleEarnings const &_P)
{
    if(this != &_P)
    {
        leadWorkerEarn = _P.getLeadWorkerEarn();
        serviceWorkerEarn =_P.getServiceWorkerEarn();
        lightWorkerEarn =_P.getLightWorkerEarn();
        heavyWorkerEarn =_P.getHeavyWorkerEarn();
        lowWorkerEarn = _P.getLowWorkerEarn();
    }
    return *this;
}

void CPeopleEarnings::addLeadWorkerEarn(double _number)
{   leadWorkerEarn += _number;  }
void CPeopleEarnings::addServiceWorkerEarn(double _number)
{   serviceWorkerEarn+= _number;}
void CPeopleEarnings::addLightWorkerEarn(double _number)
{   lightWorkerEarn+= _number;}
void CPeopleEarnings::addHeavyWorkerEarn(double _number)
{   heavyWorkerEarn+= _number;}
void CPeopleEarnings::addLowWorkerEarn(double _number)
{   lowWorkerEarn+= _number;}

double CPeopleEarnings::getLeadWorkerEarn() const
{   return leadWorkerEarn;}
double CPeopleEarnings::getServiceWorkerEarn() const
{ return serviceWorkerEarn;}
double CPeopleEarnings::getLightWorkerEarn() const
{ return lightWorkerEarn;}
double CPeopleEarnings::getHeavyWorkerEarn() const
{ return heavyWorkerEarn; }
double CPeopleEarnings::getLowWorkerEarn() const
{ return lowWorkerEarn;}

void CPeopleEarnings::setLeadWorkerEarn(double _number)
{   leadWorkerEarn =_number;}
void CPeopleEarnings::setServiceWorkerEarn(double _number)
{   serviceWorkerEarn=_number;}
void CPeopleEarnings::setLightWorkerEarn(double _number)
{   lightWorkerEarn=_number;}
void CPeopleEarnings::setHeavyWorkerEarn(double _number)
{   heavyWorkerEarn=_number;}
void CPeopleEarnings::setLowWorkerEarn(double _number)
{   lowWorkerEarn=_number;}
