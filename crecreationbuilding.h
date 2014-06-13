#ifndef CRECREATIONBUILDING_H
#define CRECREATIONBUILDING_H

#include "cworking.h"
#include "cpeopleneeds.h"
/**
 * @brief Klasa CRecreationBuilding (budynki recreacji)
 *
 *Nadrzędna klasa dla wszystkich budynków udzielających rozrywkę.
 */
class CRecreationBuilding : public CWorking
{
protected:
    ///Bazowy współczynnik rekreacji.
    CRecreation baseRecreation;
    ///Aktualny współczynnik rekreacji.
    CRecreation actualRecreation;
public:
    CRecreationBuilding();
    CRecreationBuilding(const CRecreationBuilding& _R);
    virtual ~CRecreationBuilding();
    virtual QList<QString> infoToDisplay();
    virtual bool setRandomName(int size);

    ///Oblicz i ustaw aktualny współczynnik rekreacji.
    void countSetRecreationQuality();

    double countBuildingEfficiency();

    CRecreation getBaseRecreation() const;
    CRecreation getActualRecreation() const;

    void setBaseRecreation(CRecreation _base);
    void setActualRecreation(CRecreation _actual);
};

/**
 * @brief Klasa CCinema (kino)
 */
class CCinema : public CRecreationBuilding
{
protected:
public:
    CCinema();
    CCinema(const CCinema& _C);
    virtual ~CCinema();
};
#endif // CRECREATIONBUILDING_H
