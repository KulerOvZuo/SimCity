#include "cliving.h"
#include "ccity.h"

CLiving::CLiving() : CBuilding(),schoolConnected(NULL)
{
    maxLivingPeople=0;
    children=0;
    birthRate=0;
    income=0;
    lifeSatisfaction=0;
    learningPeopleList.clear();
}
CLiving::CLiving(const CLiving& _L) : CBuilding(_L)
{
    maxLivingPeople=_L.getMaxLivingPeople();
    livingWorkingPeople = _L.getLivingWorkingPeople();
    livingNotWorkingPeople = _L.getLivingNotWorkingPeople();
    learningPeopleList = _L.getListOfLearningPeople();
    children=_L.getChildren();
    birthRate=_L.getBirthRate();
    income=_L.getIncome();
    lifeSatisfaction=_L.getLifeSatisfaction();
    schoolConnected = _L.getSchool();
    peopleNeeds =_L.getPeopleNeeds();
}
CLiving::~CLiving()
{
    learningPeopleList.clear();
}


bool CLiving::searchSetForBetterSchool()
{
    CSchool* best=NULL;
    double rangeInd=1;
    if(schoolConnected != NULL)
        rangeInd = 1- this->distanceToOther(schoolConnected)/50;
    if(rangeInd <0.1)
        rangeInd=0.1;
    double actual=0;
    if(schoolConnected != NULL)
        actual= schoolConnected->getActualEducationIndicator()*rangeInd;
    double temp;
    for(int i=0; i<((city->getMapOfStructures())->getAllSchools()).count(); i++)
    {   rangeInd = 1- this->distanceToOther(city->getMapOfStructures()->getAllSchools().at(i))/50;
        if(rangeInd <0.1)
            rangeInd=0.1;
        temp = (city->getMapOfStructures()->getAllSchools().at(i)->getActualEducationIndicator())*rangeInd;
        if( temp > 1.1*actual)
        {   best = dynamic_cast<CSchool*>(((city->getMapOfStructures())->getAllSchools()).at(i));
            actual = temp;}
    }
    if(best != NULL)
    {   ///need to transfer children
        int _children=getNumberOfLearningPeople().getAllPeople();
        if(schoolConnected != NULL)
        {   schoolConnected->addNOChildren(-_children);
            schoolConnected->countSetEducationQuality();}
        schoolConnected = best;
        if(schoolConnected != NULL)
        {   schoolConnected->addNOChildren(_children);
            schoolConnected->countSetEducationQuality();
            return true;
        }
        return false;
    }
    return false;
}
bool CLiving::searchAndSendNeedsToShops()
{
    double rangeIndicator =0;
    double maxDist=0;
    //get max dist to shops
    for(int i=0; i<(city->getMapOfStructures()->getAllShops()).count(); i++)
    {
        if(maxDist<distanceToOther((city->getMapOfStructures()->getAllShops()).at(i)))
        {   maxDist=distanceToOther((city->getMapOfStructures()->getAllShops()).at(i));}
    }
    if(maxDist==0)
        maxDist=1;
    double sum=0;
    QVector<double> _tempList;
    _tempList.clear();
    //get cost indicators at all shops
    for(int i=0; i<(city->getMapOfStructures()->getAllShops()).count(); i++)
    {   rangeIndicator=distanceToOther((city->getMapOfStructures()->getAllShops()).at(i))/maxDist;
        if(rangeIndicator<0.3)
            rangeIndicator=0.3;
        double _food=(peopleNeeds.getProductsNeed().getFood())*((city->getMapOfStructures()->getAllShops()).at(i)->getProductsSellPrice().getFood());
        double _light =(peopleNeeds.getProductsNeed().getLight())*((city->getMapOfStructures()->getAllShops()).at(i)->getProductsSellPrice().getLight());
        double _heavy= (peopleNeeds.getProductsNeed().getHeavy())*((city->getMapOfStructures()->getAllShops()).at(i)->getProductsSellPrice().getHeavy());
        double x=((_food+_heavy+_light)*rangeIndicator);
        if(x<=0)
            x=100;
        double _ind = 1/x;
        _tempList.append(_ind); //the highest _ind the best
        sum+=_ind;
    }
    //decide,split and send to shops needs
    double sendIndicator;
    for(int i=0; i<(city->getMapOfStructures()->getAllShops()).count(); i++)
    {
        sendIndicator= (_tempList.at(i))/sum; //to the best shop, send max
        CProducts _prod;
        _prod.setFood(peopleNeeds.getProductsNeed().getFood()*sendIndicator);
        _prod.setHeavy(peopleNeeds.getProductsNeed().getHeavy()*sendIndicator);
        _prod.setLight(peopleNeeds.getProductsNeed().getLight()*sendIndicator);
        CProductsBuildingPointer* P = new CProductsBuildingPointer;
        P->setBuilding(this);
        P->setProducts(_prod);
        (city->getMapOfStructures()->getAllShops()).at(i)->addLivingToProductsNeeds(P);
    }
    peopleNeeds.setProductsNeed(CProducts(0,0,0));
    return true;
}
bool CLiving::buyProductsFromShop(CProducts _prod, CProducts _price)
{   bool _good =_prod.restoreIfNotPossitiveNONeeds();
    peopleNeeds.setProductsNeed(peopleNeeds.getProductsNeed()+_prod);
    income -= (_prod.getLight()*_price.getLight()+_prod.getHeavy()*_price.getHeavy()+_prod.getFood()*_price.getFood());
    return _good;
}

void CLiving::countSetIncome()
{
    income=0;
    CPeopleEarnings _E = city->getSocietyIndicators()->getPeopleEarnings();
    income += livingWorkingPeople.getLeadWorker()*_E.getLeadWorkerEarn();
    income += livingWorkingPeople.getServiceWorker()*_E.getServiceWorkerEarn();
    income += livingWorkingPeople.getLightWorker()*_E.getLightWorkerEarn();
    income += livingWorkingPeople.getHeavyWorker()*_E.getHeavyWorkerEarn();
    income += livingWorkingPeople.getLowWorker()*_E.getLowWorkerEarn();
}
double CLiving::giveTaxes(double _tax)
{
    double tax = income * _tax/100;
    income -= tax;
    return tax;
}
double CLiving::countSetBirthRate()
{   double _birth= -0.5 + lifeSatisfaction*1;
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople();
    birthRate = _birth*_allPeople;
    return _birth;
}
CPeopleNeeds CLiving::countPeopleNeeds()
{
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople()+children;
    for(int i=0; i<learningPeopleList.count(); i++)
    {
        _allPeople += (learningPeopleList.at(i)).getAllPeople();
    }
    double _food=1+0.6*lifeSatisfaction;
    _food *= _allPeople;
    double _light=0.5+1*lifeSatisfaction;
    _light*= _allPeople;
    double _heavy=0.5+0.8*lifeSatisfaction;
    _heavy*= _allPeople;
    double _serv1=0.5+1*lifeSatisfaction;
    _serv1*= _allPeople;
    double _rec1=0.5+1*lifeSatisfaction;
    _rec1*= _allPeople;

    double _disturbance=1+0.4*lifeSatisfaction;
    double _traffic=2+0.3*lifeSatisfaction;
    //for all people in building
    return CPeopleNeeds(CProducts(_light,_heavy,_food),CService(_serv1),CRecreation(_rec1),_traffic,_disturbance);
}
double CLiving::countLifeSatisfaction()
{
    double _pastLifeSat = lifeSatisfaction;
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople()+children;
    for(int i=0; i<learningPeopleList.count(); i++)
    {
        _allPeople += (learningPeopleList.at(i)).getAllPeople();
    }
    double lifeSat;
    int aInc=1;
    if(income<0)
        aInc=-1;
    double aDist=1;
    if(peopleNeeds.getDisturbance()<0)
        aDist=-1;
    if(peopleNeeds.getTraffic()<1)
        peopleNeeds.setTraffic(1);
    if(abs(peopleNeeds.getDisturbance())<1)
        peopleNeeds.setDistrurbance(1);
    if(abs(income)<1)
        income=1;
    double _rec1= (peopleNeeds.getRecreationNeed()).getRecreation1()/_allPeople;
    if(_rec1<1)
        _rec1=1;
    double _food=(peopleNeeds.getProductsNeed()).getFood()/_allPeople;
    if(_food<1)
        _food=1;
    double _light= (peopleNeeds.getProductsNeed()).getLight()/_allPeople;
    if(_light<1)
        _light=1;
    double _heavy = (peopleNeeds.getProductsNeed()).getHeavy()/_allPeople;
    if(_heavy<1)
        _heavy=1;
    double _service= (peopleNeeds.getServiceNeed()).getService1()/_allPeople;
    if(_service<1)
        _service=1;

    lifeSat = (1+0.2*(trafficInd*log10(peopleNeeds.getTraffic())+aDist*disturbanceInd*log10(abs(peopleNeeds.getDisturbance()))+
                             recreationInd*log10(_rec1)+foodInd*log10(_food)+
                             lightInd*log10(_light)+heavyInd*log10(_heavy)+
                         serviceInd*log10(_service)+aInc*incomeInd*log10(abs(income/_allPeople))));
    return (3*_pastLifeSat+lifeSat)/4;
}

//list
void CLiving::addNewLearningPeople(CPeople _professions)
{
    learningPeopleList.append(CLearningPeople(_professions,0,0,0,0,0));
}
void CLiving::clearListOfLearningPeople()
{
    learningPeopleList.clear();

}
void CLiving::optimizeListOfLearningPeople()
{
    int _i;
    int _end = learningPeopleList.count();
    for(_i=0; _i < _end; _i++)
    {   if(learningPeopleList[_i].getAllPeople() <=0)
        {   learningPeopleList.removeAt(_i); //remove
            _end = learningPeopleList.count();  //count number of values
            _i += -1; //start searching from same point
        }
    }
}
void CLiving::educatePeople()
{
    double _educationIndicator = schoolConnected->getActualEducationIndicator();
    for(int i=0; i<learningPeopleList.size(); i++)
    {
        learningPeopleList[i].addAllEducation(_educationIndicator);
    }
}

CPeople CLiving::extractEducatedPeople()
{
    CPeople _P;
    for(int i=0; i<learningPeopleList.size(); i++)
    {   //extract educated people
        _P += learningPeopleList[i].extractWhoIsEducated();
    }
    schoolConnected->addNOChildren(-1*_P.getAllPeople());
    schoolConnected->countSetEducationQuality();
    livingNotWorkingPeople += _P;
    return _P;
}

CPeople CLiving::getNumberOfLearningPeople()
{
    CPeople _P;
    for(int i=0; i<learningPeopleList.size(); i++)
    {   //add all learning people
        _P += learningPeopleList[i];
    }
    return _P;
}

void CLiving::setMaxLivingPeople(int _max)
{   maxLivingPeople = _max;}
void CLiving::setLivingWorkingPeople(CPeople _P)
{   livingWorkingPeople = _P;}
void CLiving::setLivingNotWorkingPeople(CPeople _P)
{   livingNotWorkingPeople = _P;}
void CLiving::setChildren(int _children)
{   children = _children;}
void CLiving::setIncome(int _income)
{   income = _income;}
void CLiving::setLifeSatisfaction( double _lifeSat)
{  lifeSatisfaction=_lifeSat; }
bool CLiving::setSchool(CSchool* _school)
{   schoolConnected = _school;
    if(_school == NULL)
        return false;
    return true;
}
void CLiving::setPeopleNeeds(CPeopleNeeds _P)
{   peopleNeeds = _P;}

int CLiving::getMaxLivingPeople()const
{ return maxLivingPeople;}
CPeople CLiving::getLivingWorkingPeople()const
{ return livingWorkingPeople;}
CPeople CLiving::getLivingNotWorkingPeople()const
{   return livingNotWorkingPeople;}
QList<CLearningPeople> CLiving::getListOfLearningPeople() const
{ return learningPeopleList;}
int CLiving::getChildren()const
{ return children;}
double CLiving::getBirthRate() const
{ return birthRate;}
double CLiving::getIncome()const
{   return income;}
double CLiving::getLifeSatisfaction()const
{ return lifeSatisfaction;}
CSchool* CLiving::getSchool()const
{ return schoolConnected;}
CPeopleNeeds CLiving::getPeopleNeeds()const
{ return peopleNeeds;}


///CBLocks
CBlocks::CBlocks() : CLiving()
{}
CBlocks::CBlocks(const CBlocks& _B): CLiving(_B)
{}

///CHouse
CHouse::CHouse(): CLiving()
{}
CHouse::CHouse(const CHouse& _H): CLiving(_H)
{}
