#include "cpublicutilitybuilding.h"
#include "ccity.h"

CPublicUtilityBuilding::CPublicUtilityBuilding(): CWorking()
{
}
CPublicUtilityBuilding::CPublicUtilityBuilding(const CPublicUtilityBuilding& _U) : CWorking(_U)
{}
CPublicUtilityBuilding::~CPublicUtilityBuilding()
{}
void CPublicUtilityBuilding::setProperUtility(double _utility)
{ Q_UNUSED(_utility)}
bool CPublicUtilityBuilding::sendUtilitiesToCity()
{   city->setUtilitiesGlobalProduction((city->getUtilitiesGlobalProduction()) + utilities);
    return true;}

///power
CPowerStation::CPowerStation() : CPublicUtilityBuilding()
{}
CPowerStation::CPowerStation(const CPowerStation& _P) : CPublicUtilityBuilding(_P)
{}
void CPowerStation::setProperUtility(double _utility)
{   setUtilities(CUtilitiesGlobal(_utility,0,0));}

///water
CWaterStation::CWaterStation(): CPublicUtilityBuilding()
{}
CWaterStation::CWaterStation(const CWaterStation& _W): CPublicUtilityBuilding(_W)
{}
void CWaterStation::setProperUtility(double _utility)
{   setUtilities(CUtilitiesGlobal(0,_utility,0));}

///dump
CDumpStation::CDumpStation(): CPublicUtilityBuilding()
{}
CDumpStation::CDumpStation(const CDumpStation& _D): CPublicUtilityBuilding(_D)
{}
void CDumpStation::setProperUtility(double _utility)
{   setUtilities(CUtilitiesGlobal(0,0,_utility));}

///allon1
CPublicUtilityBuildingAllInOne::CPublicUtilityBuildingAllInOne(): CPublicUtilityBuilding()
{}
CPublicUtilityBuildingAllInOne::CPublicUtilityBuildingAllInOne(const CPublicUtilityBuildingAllInOne& _P): CPublicUtilityBuilding(_P)
{}
void CPublicUtilityBuildingAllInOne::setProperUtility(double _utility)
{ Q_UNUSED(_utility)}
