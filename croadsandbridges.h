#ifndef CROADSANDBRIDGES_H
#define CROADSANDBRIDGES_H

#include "cstructure.h"
#include "cdirections.h"

/**
 * @brief Klasa CRoadsAndBridges (drogi i mosty)
 *
 *Klasa będąca nadrzędna dla wszystkich dróg i mostów istniejących w mieście.
 *Pozwala dodatkowo m.in na określenie kierunków z którymi łączy się dany rodzaj drogi.
 */
class CRoadsAndBridges : public CStructure
{
protected:
    ///Przepustowość.
    double capacity;
    ///Czy może być postawiony na wodzie.
    bool onWater;
    ///Kierunki na które wychodzi dana droga.
    CDirections directions;
public:
    CRoadsAndBridges();
    /**
     * @brief CRoadsAndBridges - konstruktor
     *
     *Konstruktor inicjalizuje atrybuty wartościami z parametrów.
     */
    CRoadsAndBridges(double _capacity,bool _water,CDirections _dir);
    CRoadsAndBridges(const CRoadsAndBridges& _R);

    /**
     * @brief Obróć
     *
     *Reimplementacja metody z CStructure, Dodatkowo obraca kierunki na które wychodzi droga.
     * @param rotateAngle - kąt rotacji
     */
    bool rotate(Erotation rotateAngle);
    /**
     * @brief Sprawdź czy można wybudować
     *
     *Reimplementacja metody z CStructure. Sprawdza dodatkowo warunki połączenia z drogami dookoła.
     * @return Zwraca true, jesli można postawić.
     */
    virtual bool checkIfCanBeBuiled() const;
    virtual QList<QString> infoToDisplay();
    /**
     * @brief Ustaw losową nazwę
     *
     *Reimplementuje metodę tak, że ustawia zawsze nazwę "Road".
     */
    virtual bool setRandomName(int size);

    void setAllRoadAndBridges(double _capacity,bool _water,CDirections _dir);
    bool setOnWater(bool _water);
    bool setCapacity(double _capacity);
    bool setDirections(CDirections _dir);

    double getCapacity() const;
    bool getOnWater() const;
    CDirections getDirections() const;
};

#endif // CROADSANDBRIDGES_H
