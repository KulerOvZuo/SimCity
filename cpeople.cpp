#include "cpeople.h"

CPeople::CPeople()
{
    leadWorker = 0;
    serviceWorker =0;
    lightWorker =0;
    heavyWorker =0;
    lowWorker = 0;
}
CPeople::CPeople(int _lead, int _serv, int _light,int _heavy, int _low)
{
    leadWorker = _lead;
    serviceWorker =_serv;
    lightWorker =_light;
    heavyWorker =_heavy;
    lowWorker = _low;
}
CPeople::CPeople(const CPeople& _P)
{
    leadWorker = _P.getLeadWorker();
    serviceWorker =_P.getServiceWorker();
    lightWorker =_P.getLightWorker();
    heavyWorker =_P.getHeavyWorker();
    lowWorker = _P.getLowWorker();
}
CPeople CPeople::operator+ (CPeople _P)
{
    return CPeople(leadWorker+_P.getLeadWorker(),serviceWorker+_P.getServiceWorker(),
                   lightWorker+_P.getLightWorker(),heavyWorker+_P.getHeavyWorker(),lowWorker + _P.getLowWorker());
}
CPeople& CPeople::operator+= (CPeople const &_P)
{
    this->leadWorker += _P.getLeadWorker();
    this->serviceWorker +=_P.getServiceWorker();
    this->lightWorker +=_P.getLightWorker();
    this->heavyWorker +=_P.getHeavyWorker();
    this->lowWorker += _P.getLowWorker();

    return *this;
}
CPeople& CPeople::operator-= (CPeople const &_P)
{
    this->leadWorker -= _P.getLeadWorker();
    this->serviceWorker -=_P.getServiceWorker();
    this->lightWorker -=_P.getLightWorker();
    this->heavyWorker -=_P.getHeavyWorker();
    this->lowWorker -= _P.getLowWorker();
    return *this;
}
CPeople& CPeople::operator= (CPeople const &_P)
{
    if(this != &_P)
    {
        leadWorker = _P.getLeadWorker();
        serviceWorker =_P.getServiceWorker();
        lightWorker =_P.getLightWorker();
        heavyWorker =_P.getHeavyWorker();
        lowWorker = _P.getLowWorker();
    }
    return *this;
}


bool CPeople::restoreIfNotPossitiveNOPeople()
{
    bool _good = true;
    if(leadWorker<0)
    {   leadWorker=0;
        _good=false;}
    if(serviceWorker<0)
    {   serviceWorker=0;
        _good=false;}
    if(lightWorker<0)
    {   lightWorker=0;
        _good=false;}
    if(heavyWorker<0)
    {   heavyWorker=0;
        _good=false;}
    if(lowWorker<0)
    {   lowWorker=0;
        _good=false;}
    return _good;
}
void CPeople::addAll(int _lead, int _serv, int _light,int _heavy, int _low)
{
    leadWorker += _lead;
    serviceWorker +=_serv;
    lightWorker +=_light;
    heavyWorker +=_heavy;
    lowWorker += _low;
}
void CPeople::addLeadWorker(int _number)
{   leadWorker += _number;  }
void CPeople::addServiceWorker(int _number)
{   serviceWorker+= _number;}
void CPeople::addLightWorker(int _number)
{   lightWorker+= _number;}
void CPeople::addHeavyWorker(int _number)
{   heavyWorker+= _number;}
void CPeople::addLowWorker(int _number)
{   lowWorker+= _number;}

int CPeople::getAllPeople() const
{
    return leadWorker+serviceWorker+lightWorker+heavyWorker+lowWorker;}
int CPeople::getLeadWorker() const
{   return leadWorker;}
int CPeople::getServiceWorker() const
{ return serviceWorker;}
int CPeople::getLightWorker() const
{ return lightWorker;}
int CPeople::getHeavyWorker() const
{ return heavyWorker; }
int CPeople::getLowWorker() const
{ return lowWorker;}

void CPeople::setAll(int _lead, int _serv, int _light,int _heavy, int _low)
{
    leadWorker = _lead;
    serviceWorker =_serv;
    lightWorker =_light;
    heavyWorker =_heavy;
    lowWorker = _low;
}
void CPeople::setLeadWorker(int _number)
{   leadWorker =_number;}
void CPeople::setServiceWorker(int _number)
{   serviceWorker=_number;}
void CPeople::setLightWorker(int _number)
{   lightWorker=_number;}
void CPeople::setHeavyWorker(int _number)
{   heavyWorker=_number;}
void CPeople::setLowWorker(int _number)
{   lowWorker=_number;}
