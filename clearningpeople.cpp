#include "clearningpeople.h"

CLearningPeople::CLearningPeople() : CPeople()
{
    leadWorkerEdu = 0;
    serviceWorkerEdu =0;
    lightWorkerEdu =0;
    heavyWorkerEdu =0;
    lowWorkerEdu = 0;
}
CLearningPeople::CLearningPeople(double _lead, double _serv, double _light,double _heavy, double _low) : CPeople()
{
    leadWorkerEdu = _lead;
    serviceWorkerEdu =_serv;
    lightWorkerEdu =_light;
    heavyWorkerEdu =_heavy;
    lowWorkerEdu = _low;
}
CLearningPeople::CLearningPeople(CPeople _P,double _lead, double _serv, double _light,double _heavy, double _low) : CPeople(_P)
{
    leadWorkerEdu = _lead;
    serviceWorkerEdu =_serv;
    lightWorkerEdu =_light;
    heavyWorkerEdu =_heavy;
    lowWorkerEdu = _low;
}
CLearningPeople::CLearningPeople(const CLearningPeople& _P) : CPeople(_P)
{
    leadWorkerEdu = _P.getLeadWorkerEdu();
    serviceWorkerEdu =_P.getServiceWorkerEdu();
    lightWorkerEdu =_P.getLightWorkerEdu();
    heavyWorkerEdu =_P.getHeavyWorkerEdu();
    lowWorkerEdu = _P.getLowWorkerEdu();
}
CLearningPeople CLearningPeople::operator+ (CLearningPeople _P)
{
    return CLearningPeople(leadWorkerEdu+_P.getLeadWorkerEdu(),serviceWorkerEdu+_P.getServiceWorkerEdu(),
                   lightWorkerEdu+_P.getLightWorkerEdu(),heavyWorkerEdu+_P.getHeavyWorkerEdu(),lowWorkerEdu + _P.getLowWorkerEdu());
}
CLearningPeople& CLearningPeople::operator+= (CLearningPeople const &_P)
{
    this->leadWorkerEdu += _P.getLeadWorkerEdu();
    this->serviceWorkerEdu +=_P.getServiceWorkerEdu();
    this->lightWorkerEdu +=_P.getLightWorkerEdu();
    this->heavyWorkerEdu +=_P.getHeavyWorkerEdu();
    this->lowWorkerEdu += _P.getLowWorkerEdu();

    return *this;
}
CLearningPeople& CLearningPeople::operator-= (CLearningPeople const &_P)
{
    this->leadWorkerEdu -= _P.getLeadWorkerEdu();
    this->serviceWorkerEdu -=_P.getServiceWorkerEdu();
    this->lightWorkerEdu -=_P.getLightWorkerEdu();
    this->heavyWorkerEdu -=_P.getHeavyWorkerEdu();
    this->lowWorkerEdu -= _P.getLowWorkerEdu();

    return *this;
}
CLearningPeople& CLearningPeople::operator= (CLearningPeople const &_P)
{
    if(this != &_P)
    {
        leadWorkerEdu = _P.getLeadWorkerEdu();
        serviceWorkerEdu =_P.getServiceWorkerEdu();
        lightWorkerEdu =_P.getLightWorkerEdu();
        heavyWorkerEdu =_P.getHeavyWorkerEdu();
        lowWorkerEdu = _P.getLowWorkerEdu();
    }
    return *this;
}

CPeople CLearningPeople::getWhoIsEducated()
{
    int _lead=0;
    int _service=0;
    int _light=0;
    int _heavy =0;
    int _low=0;

    //get number of people educated enough
    if(leadWorkerEdu >= minLeadEdu)
        _lead=leadWorker;
    if(serviceWorkerEdu >= minServiceEdu)
        _service=serviceWorker;
    if(lightWorkerEdu >= minLightEdu)
        _light=lightWorker;
    if(heavyWorkerEdu >= minHeavyEdu)
        _heavy=heavyWorker;
    if(lowWorkerEdu >= minLowEdu)
        _low = lowWorker;

    return CPeople(_lead, _service,_light,_heavy,_low);
}
CPeople CLearningPeople::extractWhoIsEducated()
{
    CPeople _P(this->getWhoIsEducated());
    (*((CPeople*)this)) -= _P;
    return _P;
}
void CLearningPeople::addAllEducation(double _edu)
{
    leadWorkerEdu += _edu;
    serviceWorkerEdu +=_edu;
    lightWorkerEdu +=_edu;
    heavyWorkerEdu +=_edu;
    lowWorkerEdu += _edu;
}
void CLearningPeople::addLeadWorkerEdu(double _number)
{   leadWorkerEdu += _number;  }
void CLearningPeople::addServiceWorkerEdu(double _number)
{   serviceWorkerEdu+= _number;}
void CLearningPeople::addLightWorkerEdu(double _number)
{   lightWorkerEdu+= _number;}
void CLearningPeople::addHeavyWorkerEdu(double _number)
{   heavyWorkerEdu+= _number;}
void CLearningPeople::addLowWorkerEdu(double _number)
{   lowWorkerEdu+= _number;}

double CLearningPeople::getLeadWorkerEdu() const
{   return leadWorkerEdu;}
double CLearningPeople::getServiceWorkerEdu() const
{ return serviceWorkerEdu;}
double CLearningPeople::getLightWorkerEdu() const
{ return lightWorkerEdu;}
double CLearningPeople::getHeavyWorkerEdu() const
{ return heavyWorkerEdu; }
double CLearningPeople::getLowWorkerEdu() const
{ return lowWorkerEdu;}

void CLearningPeople::setLeadWorkerEdu(double _number)
{   leadWorkerEdu =_number;}
void CLearningPeople::setServiceWorkerEdu(double _number)
{   serviceWorkerEdu=_number;}
void CLearningPeople::setLightWorkerEdu(double _number)
{   lightWorkerEdu=_number;}
void CLearningPeople::setHeavyWorkerEdu(double _number)
{   heavyWorkerEdu=_number;}
void CLearningPeople::setLowWorkerEdu(double _number)
{   lowWorkerEdu=_number;}
