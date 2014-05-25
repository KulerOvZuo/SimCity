#include "ccity.h"

CCity::CCity()
{
    market = new CMarket;
    taxes = new CTaxes;
    societyIndicators = new CSocietyIndicators;
    mapOfStructures = new CMapOfStructures;
}
CCity::CCity(const CCity& _C)
{}
CCity::~CCity()
{}


void CCity::addUtilitiesGlobalNeed()
{}
double CCity::publicBuildingsKeepCost()
{   ///pay for roadsAndBridges, schools, greenterrain, recreation
    double _allKeepCosts=0;
    for(int i=0; i<mapOfStructures->getAllSchools().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllSchools().at(i)->getCostPerTick();
    }
    for(int i=0; i<mapOfStructures->getAllRoadsAndBridges().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllRoadsAndBridges().at(i)->getCostPerTick();
    }
    for(int i=0; i<mapOfStructures->getAllGreenTerrains().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllGreenTerrains().at(i)->getCostPerTick();
    }
    for(int i=0; i<mapOfStructures->getAllRecreationBuildings().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllRecreationBuildings().at(i)->getCostPerTick();
    }
    for(int i=0; i<mapOfStructures->getAllPublicUtilityBuildings().count(); i++)
    {   _allKeepCosts += mapOfStructures->getAllPublicUtilityBuildings().at(i)->getCostPerTick();
    }
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
    return _taxes;
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
