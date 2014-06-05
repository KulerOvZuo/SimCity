#ifndef CMAPOFSTRUCTURES_H
#define CMAPOFSTRUCTURES_H

#include "croad.h"
#include "cutilitiesglobal.h"
#include "cgreenterrain.h"
#include "cliving.h"
#include "cbuilding.h"
#include "cproductionbuilding.h"
#include "cfoodproduction.h"
#include "cfactory.h"
#include "cpublicutilitybuilding.h"
#include "cservicebuilding.h"
#include "crecreationbuilding.h"
#include "cschool.h"
#include "cshop.h"
#include <QList>
#include <QVector>

class CMapOfStructures
{
protected:
    CCoordinates mapSize;
    bool** mapOfTakenPlaces;
    QVector<CRoadsAndBridges*> allRoadsAndBridges;
    QVector<CGreenTerrain*> allGreenTerrains;
    QVector<CLiving*> allLivings;
    QVector<CProductionBuilding*> allProductionBuildings;
    QVector<CPublicUtilityBuilding*> allPublicUtilityBuildings;
    QVector<CServiceBuilding*> allServiceBuildings;
    QVector<CSchool*> allSchools;
    QVector<CShop*> allShops;
    QVector<CRecreationBuilding*> allRecreationBuildings;

public:
    CMapOfStructures();
    CMapOfStructures(const CMapOfStructures& _M);
    virtual ~CMapOfStructures();

    void clearTemporaryForStructures();

    bool addStructureProperly(CStructure* _S);
    bool removeStructureProperly(CStructure* _S);
    bool checkIfBuildingExistsOnLists(CStructure* _S);
    bool checkIfCanBePlaced(CStructure* _S);
    CWorking* getRandomWorkingBuilding();

    ///setters
    void setMapSize(CCoordinates _C);
    bool setMakeMapOfTakenPlaces();

    ///getters
    CCoordinates getMapSize() const;
    bool** getMapOfTakenPlaces() const;
    QVector<CRoadsAndBridges*> getAllRoadsAndBridges() const;
    QVector<CGreenTerrain*> getAllGreenTerrains() const;
    QVector<CLiving*> getAllLivings() const;
    QVector<CProductionBuilding*> getAllProductionBuildings() const;
    QVector<CPublicUtilityBuilding*> getAllPublicUtilityBuildings() const;
    QVector<CServiceBuilding*> getAllServiceBuildings() const;
    QVector<CSchool*> getAllSchools() const;
    QVector<CShop*> getAllShops() const;
    QVector<CRecreationBuilding*> getAllRecreationBuildings() const;
};

#endif // CMAPOFSTRUCTURES_H
