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

/**
 * @brief Klasa CMapOfStructures (mapa struktur)
 *
 *Klasa odpowiadająca za przechowywanie informacji o strukturach w mieście,
 *a także za ich poprawne dodawanie i usuwanie.
 */
class CMapOfStructures
{
protected:
    ///Rozmiar mapy z żetonach
    CCoordinates mapSize;
    ///Dwuwymiarowa tablica bool'i określająca czy dane miejsce jest już zabudowane.
    bool** mapOfTakenPlaces;
    ///Wektor wszystkich dróg i mostów
    QVector<CRoadsAndBridges*> allRoadsAndBridges;
    ///Wektor wszystkich terenów zielonych
    QVector<CGreenTerrain*> allGreenTerrains;
    ///Wektor wszystkich budynków mieszkalnych
    QVector<CLiving*> allLivings;
    ///Wektor wszystkich budynków produkcyjnych
    QVector<CProductionBuilding*> allProductionBuildings;
    ///Wektor wszystkich budynków komunalnych
    QVector<CPublicUtilityBuilding*> allPublicUtilityBuildings;
    ///Wektor wszystkich budynków usług
    QVector<CServiceBuilding*> allServiceBuildings;
    ///Wektor wszystkich szkół
    QVector<CSchool*> allSchools;
    ///Wektor wszystkich sklepów
    QVector<CShop*> allShops;
    ///Wektor wszystkich budynkóW reacreacji
    QVector<CRecreationBuilding*> allRecreationBuildings;

public:
    CMapOfStructures();
    CMapOfStructures(const CMapOfStructures& _M);
    virtual ~CMapOfStructures();

    ///Czyści zmienne pomocnicze
    void clearTemporaryForStructures();

    /**
     * @brief Dodaj strukturę
     *
     *Metoda pozwala na dodanie nowej struktury do listy budynków.
     *Sprawdzane jest czy ten budynek już nie istnieje w mieście.
     * @param _S - wskaźnik do struktury
     * @return Zwraca false jeśli struktura nie została dodana.
     */
    bool addStructureProperly(CStructure* _S);
    /**
     * @brief Usuń strukturę
     *
     *Metoda pozwala na usunięcie istniejącej struktury z listy budynków.
     *Sprawdzane jest czy ten budynek istnieje w mieście.
     * @param _S - wskaźnik do struktury
     * @return Zwraca false jeśli struktura nie została usunięta..
     */
    bool removeStructureProperly(CStructure* _S);
    /**
     * @brief Sprawdź czy budynek istnieje na listach
     *
     *Metoda sprawdza czy budynek istnieje na liście.
     * @param _S - wskaźnik do struktury
     * @return Zwraca true jeśli już istnieje.
     */
    bool checkIfBuildingExistsOnLists(CStructure* _S);
    /**
     * @brief Sprawdź czy można postawić
     *
     *Sprawdza czy budynek może zostać postawiony w danym miejscu.
     * @param _S - wskaźnik do struktury
     * @return Zwraca true jeśli można postawić.
     */
    bool checkIfCanBePlaced(CStructure* _S);
    /**
     * @brief Pobierz losowy\b budynek pracy.
     *
     *Z listy budynków pracy wybiera losowo jeden budynek i zwraca wskaźnik do niego.
     * @return Wskaźnik do wylosowanego budynku.
     */
    CWorking* getRandomWorkingBuilding();

    //setters
    void setMapSize(CCoordinates _C);
    bool setMakeMapOfTakenPlaces();

    //getters
    CCoordinates getMapSize() const;
    ///Zwraca wskaźnik do mapy zajętych miejsc.
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
