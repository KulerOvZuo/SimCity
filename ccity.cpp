#include "ccity.h"

CCity::CCity()
{
    market = new CMarket;
    market->setCity(this);
    taxes = new CTaxes;
    societyIndicators = new CSocietyIndicators;
    mapOfStructures = new CMapOfStructures;
    trafficEngine = new CTrafficEngine;
    trafficEngine->setCity(this);
    money =0;
    income=0;
}
CCity::CCity(const CCity& _C)
{ Q_UNUSED(_C);

}
CCity::~CCity()
{}


void CCity::makeTick()
{
    //[1]clearing temporary
    money += income;
    income=0;
    utilitiesGlobalNeed = CUtilitiesGlobal();
    utilitiesGlobalProduction = CUtilitiesGlobal();
    market->clearTemporary();
    societyIndicators->clearTemporary();
    mapOfStructures->clearTemporaryForStructures();

    //[/1]
    //[2]make all with schools
    for(int i=0; i<mapOfStructures->getAllSchools().count();i++)
    {   mapOfStructures->getAllSchools().at(i)->addAge(1);
        mapOfStructures->getAllSchools().at(i)->sendUtilitiesToCity();
        mapOfStructures->getAllSchools().at(i)->countSetEducationQuality();
        mapOfStructures->getAllSchools().at(i)->sendWorkInfoToCity();
    }
    //[/2]complited schools
    //[3]all with production (other interaction will be thru market)
    for(int i=0; i<mapOfStructures->getAllProductionBuildings().count();i++)
    {   mapOfStructures->getAllProductionBuildings().at(i)->addAge(1);
        mapOfStructures->getAllProductionBuildings().at(i)->sendUtilitiesToCity();
        mapOfStructures->getAllProductionBuildings().at(i)->countSetActualProductionPerTick();
        mapOfStructures->getAllProductionBuildings().at(i)->sendProductionInfoToMarket();
        mapOfStructures->getAllProductionBuildings().at(i)->sendWorkInfoToCity();
        mapOfStructures->getAllProductionBuildings().at(i)->payWorkers();
    }
    //[/3]
    //[4]
    for(int i=0; i<mapOfStructures->getAllServiceBuildings().count();i++)
    {   mapOfStructures->getAllServiceBuildings().at(i)->addAge(1);
        mapOfStructures->getAllServiceBuildings().at(i)->sendUtilitiesToCity();
        mapOfStructures->getAllServiceBuildings().at(i)->countSetServiceQuality();
        mapOfStructures->getAllServiceBuildings().at(i)->countSetActualServiceCost();
        mapOfStructures->getAllServiceBuildings().at(i)->sendWorkInfoToCity();
        mapOfStructures->getAllServiceBuildings().at(i)->payWorkers();
    }
    //[/4]
    for(int i=0; i<mapOfStructures->getAllRecreationBuildings().count();i++)
    {   mapOfStructures->getAllRecreationBuildings().at(i)->addAge(1);
        mapOfStructures->getAllRecreationBuildings().at(i)->sendUtilitiesToCity();
        mapOfStructures->getAllRecreationBuildings().at(i)->sendWorkInfoToCity();
        mapOfStructures->getAllRecreationBuildings().at(i)->countSetRecreationQuality();
    }
    for(int i=0; i<mapOfStructures->getAllRoadsAndBridges().count();i++)
    {   mapOfStructures->getAllRoadsAndBridges().at(i)->addAge(1);    }
    for(int i=0; i<mapOfStructures->getAllGreenTerrains().count();i++)
    {   mapOfStructures->getAllGreenTerrains().at(i)->addAge(1);    }
    for(int i=0; i<mapOfStructures->getAllPublicUtilityBuildings().count();i++)
    {   mapOfStructures->getAllPublicUtilityBuildings().at(i)->addAge(1);
        mapOfStructures->getAllPublicUtilityBuildings().at(i)->sendWorkInfoToCity();
        mapOfStructures->getAllPublicUtilityBuildings().at(i)->sendUtilitiesToCity();    }

    //[5]
    for(int i=0; i<mapOfStructures->getAllLivings().count();i++)
    {   mapOfStructures->getAllLivings().at(i)->addAge(1);
        mapOfStructures->getAllLivings().at(i)->sendUtilitiesToCity();
        mapOfStructures->getAllLivings().at(i)->sendBirthRateToCity();
        mapOfStructures->getAllLivings().at(i)->makeDeadsAndBorns();
        mapOfStructures->getAllLivings().at(i)->sendChildrenInfoToCity();
    }
    for(int i=0; i<mapOfStructures->getAllLivings().count();i++)
    {   mapOfStructures->getAllLivings().at(i)->searchAndGoToWork();}
    for(int i=0; i<mapOfStructures->getAllLivings().count();i++)
    {   mapOfStructures->getAllLivings().at(i)->sendPeopleInfoToCity();
        mapOfStructures->getAllLivings().at(i)->searchSetForBetterSchool();
        mapOfStructures->getAllLivings().at(i)->searchAndSendNeedsToShops();
        mapOfStructures->getAllLivings().at(i)->searchForService();
    }
    //[/5]

    for(int i=0; i<mapOfStructures->getAllServiceBuildings().count();i++)
    {   mapOfStructures->getAllServiceBuildings().at(i)->giveServiceToLivings();  }
    //[6] shops and market
    for(int i=0; i<mapOfStructures->getAllShops().count();i++)
    {   mapOfStructures->getAllShops().at(i)->addAge(1);
        mapOfStructures->getAllShops().at(i)->sendUtilitiesToCity();
        mapOfStructures->getAllShops().at(i)->sendWorkInfoToCity();
        mapOfStructures->getAllShops().at(i)->sendProductsNeedToMarket();
    }
    market->countSetActualProductsCost();
    market->takeAndPayPBForProducts();
    market->splitAndSendProductsToShops();
    for(int i=0; i<mapOfStructures->getAllShops().count();i++)
    {   mapOfStructures->getAllShops().at(i)->countSetProductsSellPrice();
        mapOfStructures->getAllShops().at(i)->sendProductsToLivings();
        mapOfStructures->getAllShops().at(i)->payWorkers();
    }
    //[/6]shops end
    societyIndicators->countSetProffesionsToEducate();
    //[5]
    for(int i=0; i<mapOfStructures->getAllLivings().count();i++)
    {   mapOfStructures->getAllLivings().at(i)->changeLivingPlace(); }
    for(int i=0; i<mapOfStructures->getAllLivings().count();i++)
    {   mapOfStructures->getAllLivings().at(i)->extractEducatedPeople();
        mapOfStructures->getAllLivings().at(i)->chooseChildrenProfessionsAndAdd();
        mapOfStructures->getAllLivings().at(i)->educatePeople();
        mapOfStructures->getAllLivings().at(i)->optimizeListOfLearningPeople();
        mapOfStructures->getAllLivings().at(i)->getSetTrafficInformation();
        mapOfStructures->getAllLivings().at(i)->countSetInfluanceFromOthers();
        mapOfStructures->getAllLivings().at(i)->countSetBirthRate();
        mapOfStructures->getAllLivings().at(i)->countSetLifeSatAndPeopleNeeds();
        mapOfStructures->getAllLivings().at(i)->countSetIncome();
    }
    //[/5]
    societyIndicators->countSetPeopleEarnings();
    trafficEngine->countTraffic();
    publicBuildingsKeepCost();
    takeTaxes();
}

void CCity::addMoney(double _money)
{   money+=_money;
}
void CCity::addUtilitiesGlobalNeed(CUtilitiesGlobal _U)
{
    utilitiesGlobalNeed += _U;
}
double CCity::publicBuildingsKeepCost()
{   ///pay for roadsAndBridges, schools, greenterrain, recreation
    double _allKeepCosts=0;
    CPeopleEarnings _earn = societyIndicators->getPeopleEarnings();
    for(int i=0; i<mapOfStructures->getAllSchools().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllSchools().at(i)->getCostPerTick();
        _allKeepCosts += mapOfStructures->getAllSchools().at(i)->getActualNumberOfWorkers().getDoubleMultiplyIndividualPeopleBy(_earn);
    }
    for(int i=0; i<mapOfStructures->getAllRoadsAndBridges().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllRoadsAndBridges().at(i)->getCostPerTick();
    }
    for(int i=0; i<mapOfStructures->getAllGreenTerrains().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllGreenTerrains().at(i)->getCostPerTick();
    }
    for(int i=0; i<mapOfStructures->getAllRecreationBuildings().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllRecreationBuildings().at(i)->getCostPerTick();
        _allKeepCosts += mapOfStructures->getAllRecreationBuildings().at(i)->getActualNumberOfWorkers().getDoubleMultiplyIndividualPeopleBy(_earn);
    }
    for(int i=0; i<mapOfStructures->getAllPublicUtilityBuildings().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllPublicUtilityBuildings().at(i)->getCostPerTick();
        _allKeepCosts += mapOfStructures->getAllPublicUtilityBuildings().at(i)->getActualNumberOfWorkers().getDoubleMultiplyIndividualPeopleBy(_earn);
    }
    income -= _allKeepCosts;
    return _allKeepCosts;
}
double CCity::takeTaxes()
{
    double _taxes=0;
    for(int i=0; i <mapOfStructures->getAllLivings().count(); i++)
    {
        _taxes += mapOfStructures->getAllLivings().at(i)->giveTaxes(taxes->getFromPeopleInd());
    }
    for(int i=0; i <mapOfStructures->getAllProductionBuildings().count(); i++)
    {
        _taxes += mapOfStructures->getAllProductionBuildings().at(i)->giveTaxes(taxes->getFromProductionInd());
    }
    for(int i=0; i <mapOfStructures->getAllShops().count(); i++)
    {
        _taxes += mapOfStructures->getAllShops().at(i)->giveTaxes(taxes->getFromOthersInd());
    }
    for(int i=0; i <mapOfStructures->getAllServiceBuildings().count(); i++)
    {
        _taxes += mapOfStructures->getAllServiceBuildings().at(i)->giveTaxes(taxes->getFromOthersInd());
    }
    income += _taxes;
    return _taxes;
}

bool CCity::addStructureProperly(CStructure* _S)
{   if(mapOfStructures->addStructureProperly(_S))
    {   _S->setCity(this);
        return true;}
    return false;
}
bool CCity::removeStructureProperly(CStructure* _S)
{   if(mapOfStructures->removeStructureProperly(_S))
        return true;
    return false;
}
///getters, not const
CUtilitiesGlobal CCity::getUtilitiesGlobalProduction()
{   return utilitiesGlobalProduction;}
CUtilitiesGlobal CCity::getUtilitiesGlobalNeed()
{   return utilitiesGlobalNeed;}
CMarket* CCity::getMarket()
{   return market;}
CTaxes* CCity::getTaxes()
{   return taxes;}
CSocietyIndicators* CCity::getSocietyIndicators()
{   return societyIndicators;}
CMapOfStructures* CCity::getMapOfStructures()
{   return mapOfStructures;}
CTrafficEngine* CCity::getTrafficEngine()
{   return trafficEngine;}
double CCity::getMoney()
{   return money;}

///setters
void CCity::setUtilitiesGlobalProduction(CUtilitiesGlobal _U)
{
    utilitiesGlobalProduction = _U;
}
void CCity::setUtilitiesGlobalNeed(CUtilitiesGlobal _U)
{   utilitiesGlobalNeed =_U;}
void CCity::setMarket(CMarket* _M)
{   market = _M;}
void CCity::setTaxes(CTaxes* _T)
{   taxes=_T;}
void CCity::setSocietyIndicators(CSocietyIndicators* _S)
{   societyIndicators=_S;}
void CCity::setMapOfStructures(CMapOfStructures* _M)
{   mapOfStructures=_M;}
void CCity::setTrafficEngine(CTrafficEngine* _engine)
{   trafficEngine = _engine;}
void CCity::setMoney(double _money)
{   money = _money;}
