#ifndef CSTRUCTURE_H
#define CSTRUCTURE_H

#include <QString>
#include "ccoordinates.h"
#include "enumerators.h"
#include "cdirections.h"

class CCity;
/**
 * @brief Klasa CStructure (struktura)
 *
 *Klasa nadrzędna dla wszystkich budynków w modelu.
 */
class CStructure
{
protected:
    ///Wiek struktury
    int age;
    ///Nazwa danej struktury
    QString name;
    ///Koszt budowy struktury
    double buildCost;
    ///Koszt zniszczenia struktury
    double destroyCost;
    /**
     *@brief Koszt utrzymania struktury na turę
     *
     *Koszt utrzymania danej struktury publicznej. Nie jest w to wlicznay koszt pracowników, a raczej opłata za miejsce
     */
    double costPerTick;
    ///Rozmiar na mapie
    CCoordinates sizeOnGameMap; //is being changed during rotation (x>0; y<0)
    ///Koordynaty lewego górnego rogu budynku na mapie
    CCoordinates coordinatesOfActualLUCorner; //actual left-up corner
    /**
     * @brief Kierunek obrócenia struktury
     *
     *Jest istotny z punktu widzenia możliwości zbudowania, zmiany zajmowanego miejsca w modelu,
     *poprawnego ukierunkowania elementów graficznych.
     */
    CDirections turnedDirection; //on creating set to UP; used for properly expose and turning model
    ///Wskaźnik do miasta w którym znajduje sie struktura
    CCity* city;

public:
    CStructure();
    /**
     * @brief CStructure - konstruktor
     *
     *Konstruktor z wieloma parametrami inicjalizującymi atrybuty obiektu.
     */
    CStructure(int age, QString name, double buildCost,double destroyCost,
               double costPerTick, CCoordinates sizeOnGameMap, CCoordinates coordinatesOfLUCorner,
               CDirections turnedDirection);
    CStructure(const CStructure &_S);
    virtual ~CStructure();

    /**
     * @brief Buduj
     *
     *Metoda odpowiadająca za fizyczne zajęcie miejsca na mapie.
     * @return Zwraca true jeśli się powiedzie.
     */
    virtual bool build();
    /**
     * @brief Zniszcz.
     *
     *Metoda odpowiadająca za fizyczne zwolnienie miejsca na mapie.
     * @return Zwraca true jeśli się powiedzie
     */
    virtual bool destroy();
    /**
     * @brief Sprawdź czy można zbudować.
     *
     *Metoda sprawdzajaca czy budynek jest możliwy do wybudowania w danym miejscu.
     * @return Zwraca true jeślimożna zbudować.
     */
    virtual bool checkIfCanBeBuiled() const;
    /**
     * @brief Informacje do wyświetlenia
     *
     *Metoda zwraca listę stringów jako grup danych, które należy wyświetlić.
     *Wysyłane mają być wszystkie najistotniejsze informacje dla gracza.
     * @return Lista stringów fo wyświetlenia.
     */
    virtual QList<QString> infoToDisplay();
    /**
     * @brief Dystans do innego
     *
     *Metoda liczy dystans do innego budynku i zwraca wartość.
     * @param other - wskaźnik do struktury do któRej chcemy zmierzyć odległość
     * @return wartość odległości
     */
    double distanceToOther(CStructure* other) const;

    /**
     * @brief Obróć
     *
     *Metoda obracająca model budynku o zadany kąt.
     * @param rotateAngle - zadany kąt
     * @return Jeśli sie powiedzie, zwraca true
     */
    virtual bool rotate(Erotation  rotateAngle); //changes turn direction and model turn direction
    /**
     * @brief Oblicz koordynaty środka budynku.
     *
     *Oblicza koordynaty środka budynku i zwraca je w formie koordynatów.
     */
    CCoordinates countCoordinatesOfCentre() const;

    void addAge(int _age);
    bool setAge(int _age);
    bool setName(QString _name);
    /**
     * @brief Ustaw losową nazwę.
     *
     *Metoda pozwalana na nadanie losowej nazwy strukturze.
     *Nazwa ma długość\b _size\c członów. Składana jest z losowych słów ze zbioru.
     * @param size - długość nazwy
     */
    virtual bool setRandomName(int size);
    void setBuildCost(double _cost);
    void setDestroyCost(double _cost);
    void setCostPerTick(double _cost);
    void setSizeOnGameMap(const CCoordinates& _C);
    void setCoordinatesOfActualLUCorner(const CCoordinates& _C);
    void setTurnedDirection(CDirections _dir);
    bool setCity(CCity* _city);

    int getAge() const;
    QString getName() const;
    double getBuildCost() const;
    double getDestroyCost() const;
    double getCostPerTick() const;
    CCoordinates getSizeOnGameMap() const;
    CCoordinates getCoordinatesOfActualLUCorner() const;
    CDirections getTurnedDirection() const;
    CCity* getCity() const;
};

#endif // CSTRUCTURE_H
