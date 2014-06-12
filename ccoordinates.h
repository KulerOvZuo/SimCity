#ifndef CCOORDINATES_H
#define CCOORDINATES_H

#include <QDebug>

/**
 * @brief Klasa CCoordinates. (koordynaty)
 *
 *Klasa będąca kontenerem informacji o położeniu w dwuwymiarowej przestrzeni.
 */
class CCoordinates
{
protected:
    ///Wartość x.
    double x;
    ///Wartość y.
    double y;
public:
    CCoordinates();
    /**
     * @brief Konstruktor
     *
     *Tworzy obiekt z zainicjalizowanymi atrybutami takimi jak w argumentach.
     * @param _x - wartośc x
     * @param _y - wartość y
     */
    CCoordinates(double _x, double _y);
    /**
     * @brief Konstruktor kopiujący
     * @param _C - obiekt kopiowany
     */
    CCoordinates(const CCoordinates& _C);
    /**
     * @brief operator +
     *
     *Implementuje możliwość dodawania do siebie obiektów tej klasy.
     * @param _C - obiekt dodawany
     * @return x+_C.x, y+_C.y
     */
    CCoordinates operator+ (CCoordinates _C);
    /**
     * @brief operator +=
     *
     *Implementuje możliwość przypisania z dodawaniem.
     */
    CCoordinates& operator+= (CCoordinates const &_C);
    /**
     * @brief operator =
     *
     *Implementuje operator przypisania.
     * @param _C - obiekt od którego zostaną przepisane dane.
     * @return Zwraca referencję do obiektu.
     */
    CCoordinates& operator=(CCoordinates const &_C);
    virtual ~CCoordinates();

    ///Pobierz wartość X.
    double getX() const;
    ///Pobierz wartość Y.
    double getY() const;
    ///Ustaw wartość X.
    void setX(double _x);
    ///Ustaw wartość Y.
    void setY(double _y);
    /**
     * @brief Ustaw koordynaty.
     * @param _x - wartość X
     * @param _y - wartość Y
     */
    void setCoordinates(double _x, double _y);
};

#endif // CCOORDINATES_H
