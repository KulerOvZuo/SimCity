#ifndef CUTILITIESGLOBAL_H
#define CUTILITIESGLOBAL_H

/**
 * @brief Klasa CUtilitiesGlobal (usługi komunalne)
 *
 *Klasa służąca jako konter danych o usługach komunalnych.
 */
class CUtilitiesGlobal
{
protected:
    ///Elektrycznośc.
    double electricity;
    ///Woda.
    double water;
    ///Odpady.
    double dump;
public:
    CUtilitiesGlobal();
    /**
     * @brief CUtilitiesGlobal - konstruktor
     *
     *Konstruktor kopiujący.
     */
    CUtilitiesGlobal(const CUtilitiesGlobal& _U);
    /**
     * @brief CUtilitiesGlobal - konstruktor
     *
     *Konstruktor z parametrami.
     *Inicjalizuje wartości atrybutów parametrami.
     */
    CUtilitiesGlobal(double _electricity,double _water,double _dump);
    ///Operator dodawania.
    CUtilitiesGlobal operator+ (CUtilitiesGlobal _U);
    ///Operator dodawania z przypisaniem.
    CUtilitiesGlobal& operator+= (CUtilitiesGlobal const &_U);
    ///Operator odejmowania z przypisaniem.
    CUtilitiesGlobal& operator-= (CUtilitiesGlobal const &_U);

    ///Ustaw wartość elektryczności.
    void setElectricity(double _electr);
    ///Ustaw wartość wody.
    void setWater(double _water);
    ///Ustaw wartość odpadów.
    void setDump(double _dump);

    ///Pobierz wartość elektryczności.
    double getElectricity() const;
    ///Pobierz wartość wody.
    double getWater() const;
    ///Pobierz wartość odpadów.
    double getDump() const;
};

#endif // CUTILITIESGLOBAL_H
