#include "cliving.h"
#include "ccity.h"
#include "crecreationbuilding.h"

CLiving::CLiving() : CBuilding(),schoolConnected(NULL)
{
    maxLivingPeople=0;
    children=0;
    birthRate=0;
    income=0;
    lifeSatisfaction=0;
    learningPeopleList.clear();
    setRandomName(1);
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
QList<QString> CLiving::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CBuilding::infoToDisplay());
    info.append(QString("Income: %1$").arg(income,1,'f',2));
    info.append(QString("Maximum living people: %1\nChildren: %2").arg(maxLivingPeople,1).arg(children,1));
    info.append(QString("Living working people:\nLead workers: %1\nService workers: %2\nLight workers: %3\nHeavy workers: %4\nLow workers: %5").
                arg(livingWorkingPeople.getLeadWorker(),1).
                arg(livingWorkingPeople.getServiceWorker(),1).
                arg(livingWorkingPeople.getLightWorker(),1).
                arg(livingWorkingPeople.getHeavyWorker(),1).
                arg(livingWorkingPeople.getLowWorker(),1));
    info.append(QString("Living NOT working people:\nLead workers: %1\nService workers: %2\nLight workers: %3\nHeavy workers: %4\nLow workers: %5").
                arg(livingNotWorkingPeople.getLeadWorker(),1).
                arg(livingNotWorkingPeople.getServiceWorker(),1).
                arg(livingNotWorkingPeople.getLightWorker(),1).
                arg(livingNotWorkingPeople.getHeavyWorker(),1).
                arg(livingNotWorkingPeople.getLowWorker(),1));
    CPeople _learningPeople;
    for(int i=0;i<learningPeopleList.count();i++)
    {   _learningPeople += *(learningPeopleList.at(i));}
    info.append(QString("People learning to professions:\nLead workers: %1\nService workers: %2\nLight workers: %3\nHeavy workers: %4\nLow workers: %5").
                arg(_learningPeople.getLeadWorker(),1).
                arg(_learningPeople.getServiceWorker(),1).
                arg(_learningPeople.getLightWorker(),1).
                arg(_learningPeople.getHeavyWorker(),1).
                arg(_learningPeople.getLowWorker(),1));
    info.append(QString("Life satisfaction: %1").arg(lifeSatisfaction,1,'f',2));
    info.append(QString("People needs:\nProducts need:\n   Food: %1\n   Light products: %2\n   Heavy products: %3\nService: %4\nRecreation: %5\nPeace need: %6\nTraffic need: %7").
                arg(peopleNeeds.getProductsNeed().getFood(),1,'f',2).
                arg(peopleNeeds.getProductsNeed().getLight(),1,'f',2).
                arg(peopleNeeds.getProductsNeed().getHeavy(),1,'f',2).
                arg(peopleNeeds.getServiceNeed().getService1(),1,'f',2).
                arg(peopleNeeds.getRecreationNeed().getRecreation1(),1,'f',2).
                arg(peopleNeeds.getDisturbance(),1,'f',2).
                arg(peopleNeeds.getTraffic(),1,'f',2));
    if(schoolConnected!=NULL)
    {   info.append(QString("School's connected name: %1").arg(schoolConnected->getName(),1));
        info.append(QString("School's connected education indicator: %1").arg(schoolConnected->getActualEducationIndicator(),1,'f',2));
    }else
        info.append(QString("No school connected"));
    return info;
}
bool CLiving::setRandomName(int size)
{   Q_UNUSED(size);
    CStructure::setRandomName(1);
return true;}
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
        if( temp >= 1.1*actual)
        {   best = dynamic_cast<CSchool*>(((city->getMapOfStructures())->getAllSchools()).at(i));
            actual = temp;}
    }
    if(best != NULL)
    {   //need to transfer children
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
    //get indicators at all shops
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
bool CLiving::takeServiceFromSB(CService _serv, CService _cost)
{   bool _good = _serv.restoreIfNotPossitiveNONeeds();
    peopleNeeds.setServiceNeed(peopleNeeds.getServiceNeed()+_serv);
    income -= (_serv.getService1()*_cost.getService1());
    return _good;
}
bool CLiving::searchForService()
{
    double rangeIndicator =0;
    double maxDist=0;
    //get max dist to service
    for(int i=0; i<(city->getMapOfStructures()->getAllServiceBuildings()).count(); i++)
    {
        if(maxDist<distanceToOther((city->getMapOfStructures()->getAllServiceBuildings()).at(i)))
        {   maxDist=distanceToOther((city->getMapOfStructures()->getAllServiceBuildings()).at(i));}
    }
    if(maxDist==0)
        maxDist=1;
    double sum=0;
    QVector<double> _tempList;
    _tempList.clear();
    //get efficiency indicator of all
    for(int i=0; i<(city->getMapOfStructures()->getAllServiceBuildings()).count(); i++)
    {   rangeIndicator=distanceToOther((city->getMapOfStructures()->getAllServiceBuildings()).at(i))/maxDist;
        if(rangeIndicator<0.3)
            rangeIndicator=0.3;
        double _serv = (peopleNeeds.getServiceNeed().getService1())*((city->getMapOfStructures()->getAllServiceBuildings()).at(i))->getActualService().getService1();
        double _ind = _serv/rangeIndicator;
        _tempList.append(_ind);
        sum+=_ind;
    }
    //decide to which service building to go
    double sendIndicator;
    for(int i=0; i<(city->getMapOfStructures()->getAllServiceBuildings()).count(); i++)
    {   if(sum!=0)
            sendIndicator = (_tempList.at(i))/sum;
        else
            sendIndicator=0;
        CService _S;
        _S.setService1((peopleNeeds.getServiceNeed().getService1())*sendIndicator);
        CPeopleNeedsBuildingPointer* _PN = new CPeopleNeedsBuildingPointer;
        _PN->setPeopleNeeds(CPeopleNeeds(CProducts(0,0,0),_S,CRecreation(0),0,0));
        _PN->setBuilding(this);
        (city->getMapOfStructures()->getAllServiceBuildings()).at(i)->addLivingTolist(_PN);
        (city->getMapOfStructures()->getAllServiceBuildings()).at(i)->countSetServiceQuality();
    }
    peopleNeeds.setServiceNeed(CService(0));
    return true;
}
void CLiving::clearTemporary()
{   money+=income;
    income=0;
}
void CLiving::makeDeadsAndBorns()
{
    CPeople A;
    children += (int)(0.05*A.randBetween(birthRate/2,birthRate));
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople();
    if(children<1 && _allPeople>=2)
        children=1;

    int _deads = (int)(0.1*A.randBetween(_allPeople/2,_allPeople));
    if(_deads<1)
        _deads=1;
    if(_deads/2>=1)
    {   livingWorkingPeople.randomSubb((int)(_deads*0.75));
        livingNotWorkingPeople.randomSubb((int)(_deads*0.25));
    }
    else
    {   livingWorkingPeople.randomSubb(_deads);}

    livingWorkingPeople.restoreIfNotPossitiveNOPeople();
    livingNotWorkingPeople.restoreIfNotPossitiveNOPeople();
}
bool CLiving::changeLivingPlace()
{   CLiving* bestLiving = NULL;
    double bestLifeSat = lifeSatisfaction*1.3;
    //choose best
    for(int i=0; i<city->getMapOfStructures()->getAllLivings().count(); i++)
    {   if(city->getMapOfStructures()->getAllLivings().at(i)->getLifeSatisfaction() > bestLifeSat)
        {   bestLifeSat = city->getMapOfStructures()->getAllLivings().at(i)->getLifeSatisfaction();
            bestLiving = dynamic_cast<CLiving*>(city->getMapOfStructures()->getAllLivings().at(i));
        }
    }
    //decide if can move
    double movingPercent =0.1;
    if(dynamic_cast<CHouse*>(this))
        movingPercent =0.2;
    if(bestLiving != this && bestLiving != NULL)
    {   int movingPeople = (this->getAllPeopleLiving())*movingPercent;
        if(movingPeople !=0)
        {   if(bestLiving->getMaxLivingPeople() - bestLiving->getAllPeopleLiving() - movingPeople < 0)
                return false;
            //decide who can go
            int _learning=0;
            for(int i=0; i < learningPeopleList.count();i++)
                _learning += learningPeopleList.at(i)->getAllPeople();
            _learning = _learning*movingPercent;
            int _working = livingWorkingPeople.getAllPeople()*movingPercent;
            int _notWorking = livingNotWorkingPeople.getAllPeople()*movingPercent;
            if(_learning+_working+_notWorking <= movingPeople)
            {
                QList<CLearningPeople*> _learningPeopleListMoving;
                _learningPeopleListMoving.clear();
                int _actualLearning = _learning;
                for(int i=0; i<learningPeopleList.count();i++)
                {   if(learningPeopleList.at(i)->getAllPeople() < _actualLearning)
                    {   CLearningPeople* _L = new CLearningPeople(CPeople(learningPeopleList.at(i)->getLeadWorker(),
                                                                         learningPeopleList.at(i)->getServiceWorker(),
                                                                         learningPeopleList.at(i)->getLightWorker(),
                                                                         learningPeopleList.at(i)->getHeavyWorker(),
                                                                         learningPeopleList.at(i)->getLowWorker()),
                                                                 learningPeopleList.at(i)->getLeadWorkerEdu(),
                                                                 learningPeopleList.at(i)->getServiceWorkerEdu(),
                                                                 learningPeopleList.at(i)->getLightWorkerEdu(),
                                                                 learningPeopleList.at(i)->getHeavyWorkerEdu(),
                                                                 learningPeopleList.at(i)->getLowWorkerEdu());
                        bestLiving->addLearningPeople(_L);
                        _actualLearning -=learningPeopleList.at(i)->getAllPeople();
                        learningPeopleList.at(i)->setAll(0,0,0,0,0);
                    }
                    else
                    {   CPeople _P = learningPeopleList.at(i)->randomExtract(_actualLearning);
                        CLearningPeople* _L = new CLearningPeople(_P,learningPeopleList.at(i)->getLeadWorkerEdu(),
                                                                     learningPeopleList.at(i)->getServiceWorkerEdu(),
                                                                     learningPeopleList.at(i)->getLightWorkerEdu(),
                                                                     learningPeopleList.at(i)->getHeavyWorkerEdu(),
                                                                     learningPeopleList.at(i)->getLowWorkerEdu());
                        bestLiving->addLearningPeople(_L);
                        break;}
                }
                //take children from school
                if(schoolConnected!=NULL)
                {   this->schoolConnected->addNOChildren(-1*_learning);
                    this->schoolConnected->countSetEducationQuality();}
                bestLiving->setLivingWorkingPeople(bestLiving->getLivingWorkingPeople()+livingWorkingPeople.randomExtract(_working));
                bestLiving->setLivingNotWorkingPeople(bestLiving->getLivingNotWorkingPeople()+livingNotWorkingPeople.randomExtract(_notWorking));
                return true;
            }
            else
                return false;
        }
    }
    else
        return false;
    return true;
}
void CLiving::countSetIncome()
{
    CPeopleEarnings _E = city->getSocietyIndicators()->getPeopleEarnings();
    income += livingWorkingPeople.getLeadWorker()*_E.getLeadWorkerEarn();
    income += livingWorkingPeople.getServiceWorker()*_E.getServiceWorkerEarn();
    income += livingWorkingPeople.getLightWorker()*_E.getLightWorkerEarn();
    income += livingWorkingPeople.getHeavyWorker()*_E.getHeavyWorkerEarn();
    income += livingWorkingPeople.getLowWorker()*_E.getLowWorkerEarn();
}
double CLiving::giveTaxes(double _tax)
{
    if(income <0)
        return 0;
    double tax = income * _tax/100;
    income -= tax;
    return tax;
}
bool CLiving::countSetInfluanceFromOthers()
{   //production
    for(int i=0; i<city->getMapOfStructures()->getAllProductionBuildings().count();i++)
    {   double distance = distanceToOther(city->getMapOfStructures()->getAllProductionBuildings().at(i));
        if(distance<15)
            distance=1;
        else
        {   if(distance<30)
                distance = 1-distance/30;
            else
                distance=0;  }
        if(dynamic_cast<CLightFactory*>(city->getMapOfStructures()->getAllProductionBuildings().at(i)) != NULL)
        {   peopleNeeds.addDisturbance(-1*distance*lightInf);}
        else
        {   if(dynamic_cast<CHeavyFactory*>(city->getMapOfStructures()->getAllProductionBuildings().at(i)) != NULL)
            {   peopleNeeds.addDisturbance(-1*distance*heavyInf);}
            else
            {   if(dynamic_cast<CFoodProduction*>(city->getMapOfStructures()->getAllProductionBuildings().at(i)) != NULL)
                {   peopleNeeds.addDisturbance(-1*distance*foodInf);}
            }
        }
    }
    //public utility buildings
    for(int i=0; i<city->getMapOfStructures()->getAllPublicUtilityBuildings().count();i++)
    {   double distance = distanceToOther(city->getMapOfStructures()->getAllPublicUtilityBuildings().at(i));
        if(distance<15)
            distance=1;
        else
        {   if(distance<30)
                distance = 1-distance/30;
            else
                distance=0;  }
        if(dynamic_cast<CPublicUtilityBuilding*>(city->getMapOfStructures()->getAllPublicUtilityBuildings().at(i)) !=NULL)
            peopleNeeds.addDisturbance(-1*distance*utilityInf);
    }
    //other livings
    for(int i=0; i<city->getMapOfStructures()->getAllLivings().count();i++)
    {   double distance = distanceToOther(city->getMapOfStructures()->getAllLivings().at(i));
        if(distance<10)
            distance=1;
        else
        {   if(distance<20)
                distance = 1-distance/20;
            else
                distance=0;  }
        if(city->getMapOfStructures()->getAllLivings().at(i) == this)
            continue;
        if(dynamic_cast<CHouse*>(city->getMapOfStructures()->getAllLivings().at(i)) != NULL)
        {   peopleNeeds.addDisturbance(-1*distance*livingInf*0.25);}
        else
        {   if(dynamic_cast<CBlocks*>(city->getMapOfStructures()->getAllLivings().at(i)) != NULL)
            {   peopleNeeds.addDisturbance(-1*distance*livingInf);}
        }
    }
    //green terrains
    for(int i=0; i<city->getMapOfStructures()->getAllGreenTerrains().count();i++)
    {   double distance = distanceToOther(city->getMapOfStructures()->getAllGreenTerrains().at(i));
        if(distance<20)
            distance=1;
        else
        {   if(distance<40)
                distance = 1-distance/40;
            else
                distance=0;  }
        if(dynamic_cast<CPark*>(city->getMapOfStructures()->getAllGreenTerrains().at(i)) != NULL)
        {   peopleNeeds.addDisturbance(parkInf*distance);       }
        else
        {   if(dynamic_cast<CLawn*>(city->getMapOfStructures()->getAllGreenTerrains().at(i)) != NULL)
            {    peopleNeeds.addDisturbance(lawnInf*distance);}
        }
    }
    //recreation
    for(int i=0; i<city->getMapOfStructures()->getAllRecreationBuildings().count();i++)
    {   double distance = distanceToOther(city->getMapOfStructures()->getAllRecreationBuildings().at(i));
        if(distance<20)
            distance=1;
        else
        {   if(distance<40)
                distance = 1-distance/40;
            else
                distance=0;  }
        if(dynamic_cast<CCinema*>(city->getMapOfStructures()->getAllRecreationBuildings().at(i))!=NULL)
            peopleNeeds.setRecreationNeed(peopleNeeds.getRecreationNeed()+
                        (city->getMapOfStructures()->getAllRecreationBuildings().at(i))->getActualRecreation());
    }
    return true;
}
double CLiving::getSetTrafficInformation()
{   peopleNeeds.setTraffic(city->getTrafficEngine()->giveTrafficInfo(countCoordinatesOfCentre()));
    return peopleNeeds.getTraffic();
}
void CLiving::sendPeopleInfoToCity()
{
    CSocietyIndicators* S = city->getSocietyIndicators();
    S->setAllLivingWorkingPeople(S->getallLivingWorkingPeople()+livingWorkingPeople);
    S->setAllLivingNotWorkingPeople(S->getallLivingNotWorkingPeople()+livingNotWorkingPeople);

    CPeople A;
    for(int i=0; i<learningPeopleList.count(); i++)
    {   A += *(dynamic_cast<CPeople*>(learningPeopleList.at(i)));}
    S->setAllLearningPeople(S->getAllLearningPeople()+A);

    A += livingNotWorkingPeople;
    A += livingWorkingPeople;
    S->setAllPeople(S->getAllPeople()+A);
}
void CLiving::sendChildrenInfoToCity()
{   city->getSocietyIndicators()->addChildren(children);}
double CLiving::countSetBirthRate()
{   double _birth;
    if(lifeSatisfaction <3)
         _birth = lifeSatisfaction*1;
    else
    {   if(lifeSatisfaction <6)
            _birth = 6 - (lifeSatisfaction)*5/6;
        else
             _birth=1;
    }
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople();
    birthRate = _birth*_allPeople;
    return _birth;
}
void CLiving::sendBirthRateToCity()
{
    city->getSocietyIndicators()->addBirthIndicator(birthRate);
}
CPeopleNeeds CLiving::countPeopleNeeds()
{
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople()+children;
    for(int i=0; i<learningPeopleList.count(); i++)
    {
        _allPeople += (learningPeopleList.at(i))->getAllPeople();
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
    //_rec1*= _allPeople;

    double _disturbance=1+0.4*lifeSatisfaction;
    double _traffic=2+0.3*lifeSatisfaction;
    //for all people in building
    return CPeopleNeeds(CProducts(_light,_heavy,_food),CService(_serv1),CRecreation(_rec1),_traffic,_disturbance);
}
void CLiving::countSetLifeSatAndPeopleNeeds()
{   lifeSatisfaction = countLifeSatisfaction();
    peopleNeeds = countPeopleNeeds();
}
double CLiving::countLifeSatisfaction()
{
    double _pastLifeSat = lifeSatisfaction;
    int _allPeople = livingWorkingPeople.getAllPeople() + livingNotWorkingPeople.getAllPeople()+children;
    for(int i=0; i<learningPeopleList.count(); i++)
    {
        _allPeople += (learningPeopleList.at(i))->getAllPeople();
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
    if(_allPeople<=0)
        _allPeople=1;
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
void CLiving::searchAndGoToWork()
{
    //CSocietyIndicators* S = city->getSocietyIndicators();
    int numOfTries=5;
    CWorking* _W = NULL;
    CWorking* best = NULL;
    double rate =-1;
    double bestRate=-1;

    //for all lead
    for(int l=0; l<livingNotWorkingPeople.getLeadWorker();l++)
    {   //search numOfTries times
        for(int i=0; i<numOfTries; i++)
        {   _W=city->getMapOfStructures()->getRandomWorkingBuilding();
            if(_W != NULL)
            {   CPeople deltaW = _W->getNeededNumberOfWorkers();
                deltaW -= _W->getActualNumberOfWorkers();
                if(deltaW.getLeadWorker() >0)
                {   rate = age;
                    if(rate > bestRate)
                    {   bestRate = rate;
                        best = _W;}
                }
            }
        }
        //end of 1 lead
        if(best != NULL)
        {   best->addWorkers(CPeople(1,0,0,0,0));
            livingNotWorkingPeople.addLeadWorker(-1);
            livingWorkingPeople.addLeadWorker(1);}
        best = NULL;
        _W = NULL;
        bestRate = -1;
        rate = -1;
    }
    //for all service
    for(int l=0; l<livingNotWorkingPeople.getServiceWorker();l++)
    {   //search numOfTries times
        for(int i=0; i<numOfTries; i++)
        {   _W=city->getMapOfStructures()->getRandomWorkingBuilding();
            if(_W != NULL)
            {   CPeople deltaW = _W->getNeededNumberOfWorkers();
                deltaW -= _W->getActualNumberOfWorkers();
                if(deltaW.getServiceWorker() >0)
                {   rate = age;
                    if(rate > bestRate)
                    {   bestRate = rate;
                        best = _W;}
                }
            }
        }
        //end of 1 Service
        if(best != NULL)
        {   best->addWorkers(CPeople(0,1,0,0,0));
            livingNotWorkingPeople.addServiceWorker(-1);
            livingWorkingPeople.addServiceWorker(1);}
        best = NULL;
        _W = NULL;
        bestRate = -1;
        rate = -1;
    }
    //for all Light
    for(int l=0; l<livingNotWorkingPeople.getLightWorker();l++)
    {   //search numOfTries times
        for(int i=0; i<numOfTries; i++)
        {   _W=city->getMapOfStructures()->getRandomWorkingBuilding();
            if(_W != NULL)
            {   CPeople deltaW = _W->getNeededNumberOfWorkers();
                deltaW -= _W->getActualNumberOfWorkers();
                if(deltaW.getLightWorker() >0)
                {   rate = age;
                    if(rate > bestRate)
                    {   bestRate = rate;
                        best = _W;}
                }
            }
        }
        //end of 1 Light
        if(best != NULL)
        {   best->addWorkers(CPeople(0,0,1,0,0));
            livingNotWorkingPeople.addLightWorker(-1);
            livingWorkingPeople.addLightWorker(1);}
        best = NULL;
        _W = NULL;
        bestRate = -1;
        rate = -1;
    }
    //for all Heavy
    for(int l=0; l<livingNotWorkingPeople.getHeavyWorker();l++)
    {   //search numOfTries times
        for(int i=0; i<numOfTries; i++)
        {   _W=city->getMapOfStructures()->getRandomWorkingBuilding();
            if(_W != NULL)
            {   CPeople deltaW = _W->getNeededNumberOfWorkers();
                deltaW -= _W->getActualNumberOfWorkers();
                if(deltaW.getHeavyWorker() >0)
                {   rate = age;
                    if(rate > bestRate)
                    {   bestRate = rate;
                        best = _W;}
                }
            }
        }
        //end of 1 Heavy
        if(best != NULL)
        {   best->addWorkers(CPeople(0,0,0,1,0));
            livingNotWorkingPeople.addHeavyWorker(-1);
            livingWorkingPeople.addHeavyWorker(1);}
        best = NULL;
        _W = NULL;
        bestRate = -1;
        rate = -1;
    }
    //for all Low
    for(int l=0; l<livingNotWorkingPeople.getLowWorker();l++)
    {   //search numOfTries times
        for(int i=0; i<numOfTries; i++)
        {   _W=city->getMapOfStructures()->getRandomWorkingBuilding();
            if(_W != NULL)
            {   CPeople deltaW = _W->getNeededNumberOfWorkers();
                deltaW -= _W->getActualNumberOfWorkers();
                if(deltaW.getLowWorker() >0)
                {   rate = age;
                    if(rate > bestRate)
                    {   bestRate = rate;
                        best = _W;}
                }
            }
        }
        //end of 1 Low
        if(best != NULL)
        {   best->addWorkers(CPeople(0,0,0,0,1));
            livingNotWorkingPeople.addLowWorker(-1);
            livingWorkingPeople.addLowWorker(1);}
        best = NULL;
        _W = NULL;
        bestRate = -1;
        rate = -1;
    }
}

//list
void CLiving::chooseChildrenProfessionsAndAdd()
{
    CPeople _temp = city->getSocietyIndicators()->getAllProfessionsToEducate();
    CPeople _prof = _temp.randomExtract(children);
    addNewLearningPeople(_prof);
    city->getSocietyIndicators()->setAllProfessionsToEducate(_temp);
}
void CLiving::addNewLearningPeople(CPeople _professions)
{
    CLearningPeople* _L = new CLearningPeople(_professions,0,0,0,0,0);
    learningPeopleList.append(_L);
}
void CLiving::addLearningPeople(CLearningPeople* _learning)
{
    learningPeopleList.append(_learning);
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
    {   if(learningPeopleList[_i]->getAllPeople() <=0)
        {   learningPeopleList.removeAt(_i); //remove
            _end = learningPeopleList.count();  //count number of values
            _i += -1; //start searching from same point
        }
    }
}
void CLiving::educatePeople()
{
    if(schoolConnected !=NULL)
    {   double _educationIndicator = schoolConnected->getActualEducationIndicator();
        for(int i=0; i<learningPeopleList.size(); i++)
        {
            learningPeopleList[i]->addAllEducation(_educationIndicator);
        }
    }
}

CPeople CLiving::extractEducatedPeople()
{
    CPeople _P;
    for(int i=0; i<learningPeopleList.size(); i++)
    {   //extract educated people
        _P += learningPeopleList[i]->extractWhoIsEducated();
    }
    if(schoolConnected!=NULL)
    {   schoolConnected->addNOChildren(-1*_P.getAllPeople());
        schoolConnected->countSetEducationQuality();}
    livingNotWorkingPeople += _P;
    return _P;
}

CPeople CLiving::getNumberOfLearningPeople()
{
    CPeople _P;
    for(int i=0; i<learningPeopleList.size(); i++)
    {   //add all learning people
        _P += *(learningPeopleList[i]);
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
void CLiving::setProductsNeed(CProducts _prod)
{   peopleNeeds.setProductsNeed(_prod);}
void CLiving::setServiceNeed(CService _serv)
{   peopleNeeds.setServiceNeed(_serv);}
void CLiving::setRecreationNeed(CRecreation _rec)
{   peopleNeeds.setRecreationNeed(_rec);}
void CLiving::setTraffic(double _traf)
{   peopleNeeds.setTraffic(_traf);}
void CLiving::setDistrurbance(double _dist)
{   peopleNeeds.setDistrurbance(_dist);}

int CLiving::getAllPeopleLiving() const
{   int q=0;
    q += livingWorkingPeople.getAllPeople();
    q += livingNotWorkingPeople.getAllPeople();
    q += children;
    for(int i=0; i<learningPeopleList.count();i++)
        q += learningPeopleList.at(i)->getAllPeople();
    return q;
}
int CLiving::getMaxLivingPeople()const
{ return maxLivingPeople;}
CPeople CLiving::getLivingWorkingPeople()const
{ return livingWorkingPeople;}
CPeople CLiving::getLivingNotWorkingPeople()const
{   return livingNotWorkingPeople;}
QList<CLearningPeople*> CLiving::getListOfLearningPeople() const
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
CPeopleNeeds CLiving::getPeopleNeeds() const
{ return peopleNeeds;}


//CBLocks
CBlocks::CBlocks() : CLiving()
{   sizeOnGameMap = CCoordinates(3,4);}
CBlocks::CBlocks(const CBlocks& _B): CLiving(_B)
{   sizeOnGameMap = _B.getSizeOnGameMap();}

//CHouse
CHouse::CHouse(): CLiving()
{   sizeOnGameMap = CCoordinates(3,2);}
CHouse::CHouse(const CHouse& _H): CLiving(_H)
{   sizeOnGameMap = _H.getSizeOnGameMap();}
