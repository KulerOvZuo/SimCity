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

bool CMapOfStructures::addStructureProperly(CStructure* _S)
{
    if(checkIfBuildingExistsOnLists(_S) == true) ///if exists on any list, dont add
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

///setters
void CMapOfStructures::setMapSize(CCoordinates _C)
{   mapSize = _C;}
bool CMapOfStructures::setMakeMapOfTakenPlaces()
{
    int y = mapSize.getY();
    int x = mapSize.getX();
    bool** _mapOfTakenPlaces = new bool*[y];
    for(int _y=0;_y<y;_y++)
    {   _mapOfTakenPlaces[_y] = new bool [x];
    }
    for(int _y=0;_y<y;_y++)
    {   for(int _x=0; _x<x; _x++)
            _mapOfTakenPlaces[_x][_y]=false;
    }
    mapOfTakenPlaces = _mapOfTakenPlaces;
    return true;
}

///getters
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


