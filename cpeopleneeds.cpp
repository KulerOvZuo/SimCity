#include "cpeopleneeds.h"

CPeopleNeeds::CPeopleNeeds()
{
    productsNeed=CProducts(1,1,1);
    serviceNeed=CService(1);
    recreationNeed=CRecreation(1);
    disturbanceNeed=1;
    traffic=1;
}
CPeopleNeeds::CPeopleNeeds(CProducts _prod, CService _serv, CRecreation _rec, double _disturb, double _traffic)
{
    productsNeed=_prod;
    serviceNeed=_serv;
    recreationNeed=_rec;
    disturbanceNeed=_disturb;
    traffic=_traffic;
}
CPeopleNeeds::CPeopleNeeds(const CPeopleNeeds& _C)
{
    productsNeed = _C.getProductsNeed();
    serviceNeed=_C.getServiceNeed();
    recreationNeed = _C.getRecreationNeed();
    disturbanceNeed = _C.getDisturbance();
    traffic = _C.getTraffic();
}
CPeopleNeeds CPeopleNeeds::operator+ (CPeopleNeeds _C)
{
    CProducts _prod(_C.getProductsNeed());
    CService _serv(_C.getServiceNeed());
    CRecreation _rec(_C.getRecreationNeed());
    double _traffic = _C.getTraffic();
    double _dist = _C.getDisturbance();
    return CPeopleNeeds(productsNeed+_prod,serviceNeed+_serv,recreationNeed+_rec,disturbanceNeed+_dist,traffic+_traffic);
}
CPeopleNeeds& CPeopleNeeds::operator+= (CPeopleNeeds const &_C)
{
    CProducts _prod(_C.getProductsNeed());
    CService _serv(_C.getServiceNeed());
    CRecreation _rec(_C.getRecreationNeed());
    double _traffic = _C.getTraffic();
    double _dist = _C.getDisturbance();

    this->productsNeed += _prod;
    this->serviceNeed +=_serv;
    this->recreationNeed +=_rec;
    this->disturbanceNeed +=_dist;
    this->traffic +=_traffic;
    return *this;
}
CPeopleNeeds& CPeopleNeeds::operator+= (CProducts const &_C)
{
    productsNeed += _C;
    return *this;
}
CPeopleNeeds& CPeopleNeeds::operator+= (CService const &_C)
{
    serviceNeed += _C;
    return *this;
}
CPeopleNeeds& CPeopleNeeds::operator+= (CRecreation const &_C)
{
    recreationNeed += _C;
    return *this;
}
CPeopleNeeds& CPeopleNeeds::operator=(CPeopleNeeds const &_C)
{
    if(this != &_C)
    {   CProducts _prod(_C.getProductsNeed());
        CService _serv(_C.getServiceNeed());
        CRecreation _rec(_C.getRecreationNeed());
        double _traffic = _C.getTraffic();
        double _dist = _C.getDisturbance();

        this->productsNeed = _prod;
        this->serviceNeed =_serv;
        this->recreationNeed =_rec;
        this->disturbanceNeed =_dist;
        this->traffic =_traffic;
    }
    return *this;
}


CPeopleNeeds CPeopleNeeds::countNewNeeds(double _lifeSatisfaction)
{
    double _food=1+0.6*_lifeSatisfaction;
    double _light=0.5+1*_lifeSatisfaction;
    double _heavy=0.5+0.8*_lifeSatisfaction;
    double _serv1=0.5+1*_lifeSatisfaction;
    double _rec1=0.5+1*_lifeSatisfaction;
    double _disturbance=1+0.4*_lifeSatisfaction;
    double _traffic=2+0.3*_lifeSatisfaction;

    this->setAll(CProducts(_light,_heavy,_food),CService(_serv1),CRecreation(_rec1),_traffic,_disturbance);
    return CPeopleNeeds(CProducts(_light,_heavy,_food),CService(_serv1),CRecreation(_rec1),_traffic,_disturbance);
}
double CPeopleNeeds::countLifeSatisfation(double _income)
{
    double lifeSat;
    int aInc=1;
    if(_income<0)
        aInc=-1;
    double aDist=1;
    if(disturbanceNeed<0)
        aDist=-1;
    if(traffic<1)
        traffic=1;
    if(abs(disturbanceNeed)<1)
        disturbanceNeed=1;
    if(abs(_income)<1)
        _income=1;
    double _rec1=recreationNeed.getRecreation1();
    if(_rec1<1)
        _rec1=1;
    double _food=productsNeed.getFood();
    if(_food<1)
        _food=1;
    double _light=productsNeed.getLight();
    if(_light<1)
        _light=1;
    double _heavy =productsNeed.getHeavy();
    if(_heavy<1)
        _heavy=1;
    double _service=serviceNeed.getService1();
    if(_service<1)
        _service=1;

    lifeSat = (1+0.2*(trafficInd*log10(traffic)+aDist*disturbanceInd*log10(abs(disturbanceNeed))+
                             recreationInd*log10(_rec1)+foodInd*log10(_food)+
                             lightInd*log10(_light)+heavyInd*log10(_heavy)+
                         serviceInd*log10(_service)+aInc*incomeInd*log10(abs(_income))));
    return lifeSat;
}
double CPeopleNeeds::countLifeSatisfation(double _income, double _lifeSatPast)
{
    double lifeSat=countLifeSatisfation(_income);
    return (3*_lifeSatPast+lifeSat)/4;
}
void CPeopleNeeds::setAll(CProducts _prod,CService _serv,CRecreation _rec,double _traf,double _dist)
{
    productsNeed = _prod;
    serviceNeed=_serv;
    recreationNeed=_rec;
    traffic = _traf;
    disturbanceNeed=_dist;
}
void CPeopleNeeds::setProductsNeed(CProducts _prod)
{ productsNeed = _prod;}
void CPeopleNeeds::setServiceNeed(CService _serv)
{ serviceNeed=_serv;}
void CPeopleNeeds::setRecreationNeed(CRecreation _rec)
{ recreationNeed=_rec;}
void CPeopleNeeds::setTraffic(double _traf)
{ traffic = _traf;}
void CPeopleNeeds::setDistrurbance(double _dist)
{ disturbanceNeed=_dist;}
void CPeopleNeeds::addTraffic(double _traf)
{ traffic +=_traf;}
void CPeopleNeeds::addDisturbance(double _dist)
{   disturbanceNeed += _dist;}


CProducts CPeopleNeeds::getProductsNeed() const
{   return productsNeed;}
CService CPeopleNeeds::getServiceNeed() const
{ return serviceNeed;}
CRecreation CPeopleNeeds::getRecreationNeed() const
{   return recreationNeed;}
double CPeopleNeeds::getDisturbance() const
{ return disturbanceNeed;}
double CPeopleNeeds::getTraffic() const
{ return traffic;}


///CProducts
CProducts::CProducts()
{
    lightIndustry=0;
    heavyIndustry=0;
    food=0;
}
CProducts::CProducts(double _light, double _heavy, double _food)
{
    lightIndustry=_light;
    heavyIndustry=_heavy;
    food=_food;
}
CProducts::CProducts(const CProducts& _C)
{
    lightIndustry=_C.getLight();
    heavyIndustry=_C.getHeavy();
    food=_C.getFood();
}
CProducts CProducts::operator+ (CProducts _C)
{
    return CProducts(lightIndustry+_C.getLight(),heavyIndustry+_C.getHeavy(),food+_C.getFood());
}
CProducts& CProducts::operator+= (CProducts const &_C)
{
    this->lightIndustry +=_C.getLight();
    this->heavyIndustry +=_C.getHeavy();
    this->food +=_C.getFood();
    return *this;
}
CProducts& CProducts::operator=(CProducts const &_C)
{
    if(this != &_C)
        {   this->lightIndustry =_C.getLight();
         this->heavyIndustry =_C.getHeavy();
         this->food =_C.getFood();
        }
    return *this;
}

double CProducts::getLight() const
{return lightIndustry;}
double CProducts::getHeavy() const
{return heavyIndustry;}
double CProducts::getFood() const
{return food;}
void CProducts::setAll(double _light, double _heavy, double _food)
{
    lightIndustry=_light;
    heavyIndustry=_heavy;
    food=_food;
}
void CProducts::setLight(double _light)
{ lightIndustry=_light;}
void CProducts::setHeavy(double _heavy)
{ heavyIndustry=_heavy;}
void CProducts::setFood(double _food)
{ food=_food;}

///CService
CService::CService()
{
    service1=0;
}
CService::CService(double _serv1)
{
    service1=_serv1;
}
CService::CService(const CService& _C)
{
    service1=_C.getService1();
}
CService CService::operator+ (CService _C)
{
    return CService(service1+_C.getService1());
}
CService& CService::operator+= (CService const &_C)
{
    this->service1 += _C.getService1();
    return *this;
}
CService& CService::operator=(CService const &_C)
{
    if(this != &_C)
        {   this->service1 = _C.getService1();
        }
    return *this;
}
double CService::getService1() const
{ return service1;}
void CService::setService1(double _serv)
{   service1=_serv;}

///CRecreation
CRecreation::CRecreation()
{ recreation1=0;}
CRecreation::CRecreation(double _recr1)
{ recreation1=_recr1;}
CRecreation::CRecreation(const CRecreation& _C)
{
    recreation1=_C.getRecreation1();
}
CRecreation CRecreation::operator+ (CRecreation _C)
{
    return CRecreation(recreation1+_C.getRecreation1());
}
CRecreation& CRecreation::operator+= (CRecreation const &_C)
{
    this->recreation1 +=_C.getRecreation1();
    return *this;
}
CRecreation& CRecreation::operator=(CRecreation const &_C)
{
    if(this != &_C)
        {   this->recreation1 =_C.getRecreation1();
        }
    return *this;
}

double CRecreation::getRecreation1() const
{   return recreation1;}
void CRecreation::setRecreation1(double _rec)
{   recreation1=_rec;}
