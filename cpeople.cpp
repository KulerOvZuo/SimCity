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
int CPeople::randBetween(int min, int max)
{
    return qrand() % ((max + 1) - min) + min;
}
void CPeople::randomAdd(int _free)
{
    while(_free > 0)
    {   switch (randBetween(1,5)) {
        case 1:
            addLeadWorker(1);
            _free--;
            break;
        case 2:
            addServiceWorker(1);
            _free--;
            break;
        case 3:
            addLightWorker(1);
            _free--;
            break;
        case 4:
            addHeavyWorker(1);
            _free--;
            break;
        case 5:
            addLowWorker(1);
            _free--;
            break;
        default:
            break;
        }
    }
}
void CPeople::randomSubb(int _free)
{
    int counter = _free*4; //using as watchdog
    while(_free > 0)
    {   switch (randBetween(1,5)) {
        case 1:
            if(leadWorker >0)
            {   addLeadWorker(-1);
                _free--;}
            else
               counter--;
            break;
        case 2:
            if(serviceWorker>0)
            {   addServiceWorker(-1);
                _free--;}
            else
               counter--;
            break;
        case 3:
            if(lightWorker>0)
            {   addLightWorker(-1);
                _free--;}
            else
               counter--;
            break;
        case 4:
            if(heavyWorker >0)
            {   addHeavyWorker(-1);
                _free--;}
            else
               counter--;
            break;
        case 5:
            if(lowWorker >0)
            {   addLowWorker(-1);
                _free--;}
            else
               counter--;
            break;
        default:
            break;
        }
        if(counter<=0)
        {   _free =-1;
            break;}
    }
}
CPeople CPeople::randomExtract(int _free)
{
    CPeople _P;
    int counter = _free*4; //using as watchdog
    while(_free > 0)
    {   switch (randBetween(1,5)) {
        case 1:
            if(leadWorker >0)
            {   addLeadWorker(-1);
                _P.addLeadWorker(1);
                _free--;}
            else
               counter--;
            break;
        case 2:
            if(serviceWorker>0)
            {   addServiceWorker(-1);
                _P.addServiceWorker(1);
                _free--;}
            else
               counter--;
            break;
        case 3:
            if(lightWorker>0)
            {   addLightWorker(-1);
                _P.addLightWorker(1);
                _free--;}
            else
               counter--;
            break;
        case 4:
            if(heavyWorker >0)
            {   addHeavyWorker(-1);
                _P.addHeavyWorker(1);
                _free--;}
            else
               counter--;
            break;
        case 5:
            if(lowWorker >0)
            {   addLowWorker(-1);
                _P.addLowWorker(1);
                _free--;}
            else
               counter--;
            break;
        default:
            break;
        }
        if(counter<=0)
        {   _free =-1;
            break;}
    }
    return _P;
}
CPeopleEarnings CPeople::multiplyIndividualPeopleBy(CPeopleEarnings _multiply)
{
    return CPeopleEarnings(_multiply.getLeadWorkerEarn()*leadWorker,
                           _multiply.getServiceWorkerEarn()*serviceWorker,
                           _multiply.getLightWorkerEarn()*lightWorker,
                           _multiply.getHeavyWorkerEarn()*heavyWorker,
                           _multiply.getLowWorkerEarn()*lowWorker);
}
double CPeople::getDoubleMultiplyIndividualPeopleBy(CPeopleEarnings _multiply)
{
    double sum=0;
    CPeopleEarnings _P = multiplyIndividualPeopleBy(_multiply);
    sum = (_P.getLeadWorkerEarn()+ _P.getServiceWorkerEarn()+_P.getLightWorkerEarn()+
           _P.getHeavyWorkerEarn()+_P.getLowWorkerEarn());
    return sum;
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
