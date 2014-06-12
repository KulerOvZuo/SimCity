#include "cmapofstructures.h"

CMapOfStructures::CMapOfStructures() : mapSize(CCoordinates()), mapOfTakenPlaces(NULL)
{
    allRoadsAndBridges.clear();
    allGreenTerrains.clear();
    allLivings.clear();
    allProductionBuildings.clear();
    allPublicUtilityBuildings.clear();
    allServiceBuildings.clear();
    allSchools.clear();
    allShops.clear();
    allRecreationBuildings.clear();
}
CMapOfStructures::CMapOfStructures(const CMapOfStructures& _M)
{
    Q_UNUSED(_M)
}
CMapOfStructures::~CMapOfStructures()
{}

void CMapOfStructures::clearTemporaryForStructures()
{
    for(int i=0; i<allLivings.count();i++)
    {  allLivings.at(i)->clearTemporary(); }
    for(int i=0; i<allProductionBuildings.count();i++)
    {  allProductionBuildings.at(i)->clearTemporary(); }
    for(int i=0; i<allPublicUtilityBuildings.count();i++)
    {  allPublicUtilityBuildings.at(i)->clearTemporary(); }
    for(int i=0; i<allServiceBuildings.count();i++)
    {  allServiceBuildings.at(i)->clearTemporary(); }
    for(int i=0; i<allSchools.count();i++)
    {  allSchools.at(i)->clearTemporary(); }
    for(int i=0; i<allShops.count();i++)
    {  allShops.at(i)->clearTemporary(); }
    for(int i=0; i<allRecreationBuildings.count();i++)
    {  allRecreationBuildings.at(i)->clearTemporary(); }
}

bool CMapOfStructures::addStructureProperly(CStructure* _S)
{
    if(checkIfBuildingExistsOnLists(_S) == true) //if exists on any list, dont add
        return false;
    if(dynamic_cast<CStructure*>(_S)==NULL)
        return false;
    if(dynamic_cast<CRoadsAndBridges*>(_S) !=NULL)
    {   allRoadsAndBridges.append(dynamic_cast<CRoadsAndBridges*>(_S));
        return true;}
    if(dynamic_cast<CGreenTerrain*>(_S)!=NULL)
    {   allGreenTerrains.append(dynamic_cast<CGreenTerrain*>(_S));
        return true;}
    if(dynamic_cast<CLiving*>(_S)!=NULL)
    {   allLivings.append(dynamic_cast<CLiving*>(_S));
        return true;}
    if(dynamic_cast<CProductionBuilding*>(_S)!=NULL)
    {   allProductionBuildings.append(dynamic_cast<CProductionBuilding*>(_S));
        return true;}
    if(dynamic_cast<CPublicUtilityBuilding*>(_S)!=NULL)
    {   allPublicUtilityBuildings.append(dynamic_cast<CPublicUtilityBuilding*>(_S));
        return true;}
    if(dynamic_cast<CServiceBuilding*>(_S)!=NULL)
    {   allServiceBuildings.append(dynamic_cast<CServiceBuilding*>(_S));
        return true;}
    if(dynamic_cast<CSchool*>(_S)!=NULL)
    {   allSchools.append(dynamic_cast<CSchool*>(_S));
        return true;}
    if(dynamic_cast<CShop*>(_S)!=NULL)
    {   allShops.append(dynamic_cast<CShop*>(_S));
        return true;}
    if(dynamic_cast<CRecreationBuilding*>(_S)!=NULL)
    {   allRecreationBuildings.append(dynamic_cast<CRecreationBuilding*>(_S));
        return true;}
    return false;
}
bool CMapOfStructures::removeStructureProperly(CStructure* _S)
{
    if(dynamic_cast<CRoadsAndBridges*>(_S) !=NULL)
    {   for(int i=0; i<allRoadsAndBridges.count(); i++)
        {   if(allRoadsAndBridges.at(i) == _S)
            {   allRoadsAndBridges.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CGreenTerrain*>(_S)!=NULL)
    {   for(int i=0; i<allGreenTerrains.count(); i++)
        {   if(allGreenTerrains.at(i) == _S)
            {   allGreenTerrains.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CLiving*>(_S)!=NULL)
    {   for(int i=0; i<allLivings.count(); i++)
        {   if(allLivings.at(i) == _S)
            {   allLivings.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CProductionBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allProductionBuildings.count(); i++)
        {   if(allProductionBuildings.at(i) == _S)
            {   allProductionBuildings.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CPublicUtilityBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allPublicUtilityBuildings.count(); i++)
        {   if(allPublicUtilityBuildings.at(i) == _S)
            {   allPublicUtilityBuildings.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CServiceBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allServiceBuildings.count(); i++)
        {   if(allServiceBuildings.at(i) == _S)
            {   allServiceBuildings.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CSchool*>(_S)!=NULL)
    {   for(int i=0; i<allSchools.count(); i++)
        {   if(allSchools.at(i) == _S)
            {   allSchools.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CShop*>(_S)!=NULL)
    {   for(int i=0; i<allShops.count(); i++)
        {   if(allShops.at(i) == _S)
            {   allShops.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    if(dynamic_cast<CRecreationBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allRecreationBuildings.count(); i++)
        {   if(allRecreationBuildings.at(i) == _S)
            {   allRecreationBuildings.remove(i);
                _S->CStructure::~CStructure();
                return true;
            }
        }
        return false;}
    return false;
}
bool CMapOfStructures::checkIfBuildingExistsOnLists(CStructure* _S)
{
    if(dynamic_cast<CRoadsAndBridges*>(_S) !=NULL)
    {   for(int i=0; i<allRoadsAndBridges.count(); i++)
        {   if(allRoadsAndBridges.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CGreenTerrain*>(_S)!=NULL)
    {   for(int i=0; i<allGreenTerrains.count(); i++)
        {   if(allGreenTerrains.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CLiving*>(_S)!=NULL)
    {   for(int i=0; i<allLivings.count(); i++)
        {   if(allLivings.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CProductionBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allProductionBuildings.count(); i++)
        {   if(allProductionBuildings.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CPublicUtilityBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allPublicUtilityBuildings.count(); i++)
        {   if(allPublicUtilityBuildings.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CServiceBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allServiceBuildings.count(); i++)
        {   if(allServiceBuildings.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CSchool*>(_S)!=NULL)
    {   for(int i=0; i<allSchools.count(); i++)
        {   if(allSchools.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CShop*>(_S)!=NULL)
    {   for(int i=0; i<allShops.count(); i++)
        {   if(allShops.at(i) == _S)
                return true;
        }
        return false;}
    if(dynamic_cast<CRecreationBuilding*>(_S)!=NULL)
    {   for(int i=0; i<allRecreationBuildings.count(); i++)
        {   if(allRecreationBuildings.at(i) == _S)
                return true;
        }
        return false;}
    return false;
}
bool CMapOfStructures::checkIfCanBePlaced(CStructure* _S)
{    return _S->checkIfCanBeBuiled();

}
CWorking* CMapOfStructures::getRandomWorkingBuilding()
{
    CPeople A;
    int a = A.randBetween(0,5);
    int b;
    int q=3;
    while(q>0)
    {   switch (a) {
        case 0:
            if(allSchools.count()>0)
            {   b = A.randBetween(0,allSchools.count()-1);
                return allSchools.at(b);}
            else
                q--;
            break;
        case 1:
            if(allProductionBuildings.count()>0)
            {   b = A.randBetween(0,allProductionBuildings.count()-1);
                return allProductionBuildings.at(b);}
            else
                q--;
            break;
        case 2:
            if(allServiceBuildings.count()>0)
             {   b = A.randBetween(0,allServiceBuildings.count()-1);
                return allServiceBuildings.at(b);}
            else
                q--;
            break;
        case 3:
            if(allShops.count()>0)
             {   b = A.randBetween(0,allShops.count()-1);
                return allShops.at(b);}
            else
                q--;
            break;
        case 4:
            if(allPublicUtilityBuildings.count()>0)
            {   b = A.randBetween(0,allPublicUtilityBuildings.count()-1);
                return allPublicUtilityBuildings.at(b);}
            else
                q--;
            break;
        case 5:
            if(allRecreationBuildings.count()>0)
            {    b = A.randBetween(0,allRecreationBuildings.count()-1);
                return allRecreationBuildings.at(b);}
            else
                q--;
            break;
        default:
                q--;
            break;
        }
    }
    return NULL;
}
//setters
void CMapOfStructures::setMapSize(CCoordinates _C)
{   mapSize = _C;}
bool CMapOfStructures::setMakeMapOfTakenPlaces()
{
    int y = mapSize.getY();
    int x = mapSize.getX();
    bool** _mapOfTakenPlaces = new bool*[x];
    for(int _x=0;_x<x;_x++)
    {   _mapOfTakenPlaces[_x] = new bool [y];
    }
    for(int _x=0;_x<x;_x++)
    {   for(int _y=0;_y<y;_y++)
            _mapOfTakenPlaces[_x][_y]=false;
    }
    mapOfTakenPlaces = _mapOfTakenPlaces;
    return true;
}

//getters
CCoordinates CMapOfStructures::getMapSize() const
{   return mapSize;}
bool **CMapOfStructures::getMapOfTakenPlaces() const
{   return mapOfTakenPlaces;}
QVector<CRoadsAndBridges*> CMapOfStructures::getAllRoadsAndBridges() const
{   return allRoadsAndBridges;}
QVector<CGreenTerrain*> CMapOfStructures::getAllGreenTerrains() const
{   return allGreenTerrains;}
QVector<CLiving*> CMapOfStructures::getAllLivings() const
{   return allLivings;}
QVector<CProductionBuilding*> CMapOfStructures::getAllProductionBuildings() const
{    return allProductionBuildings;}
QVector<CPublicUtilityBuilding*> CMapOfStructures::getAllPublicUtilityBuildings() const
{    return allPublicUtilityBuildings;}
QVector<CServiceBuilding*> CMapOfStructures::getAllServiceBuildings() const
{    return allServiceBuildings;}
QVector<CSchool*> CMapOfStructures::getAllSchools() const
{    return allSchools;}
QVector<CShop*> CMapOfStructures::getAllShops() const
{    return allShops;}
QVector<CRecreationBuilding*> CMapOfStructures::getAllRecreationBuildings() const
{    return allRecreationBuildings;}


