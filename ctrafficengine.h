#ifndef CTRAFFICENGINE_H
#define CTRAFFICENGINE_H

#include "ccoordinates.h"

class CCity;
/**
 * @brief Klasa CTrafficEngine (silnik korków)
 *
 *Klasa zawiera uproszczona mapę korków.
 *Pozwala na wyliczenie korków w danych obszarach miasta oraz udostępnienie informacji.
 */
class CTrafficEngine
{
protected:
    /**
     * @brief Uproszczona mapa korków.
     *
     *Uproszcozna mapa korków, wielkości 10-krotnie mniejszej niż wielkość miasta.
     *Składa się z dużych kwadratów.
     */
    double** simplifiedMapOfTraffic;
    ///Rozmiar uproszczonej mapy.
    CCoordinates sizeofSimplifiedMap;
    ///Wskaźnik do miasta.
    CCity *city;
public:
    CTrafficEngine();
    ///Konstruktor kopiujący.
    CTrafficEngine(const CTrafficEngine& _T);
    virtual ~CTrafficEngine();

    ///Ustaw miasto.
    void setCity(CCity* _city);
    /**
     * @brief Utwórz mapę korków.
     *
     *Metoda inizjalizuje wszystkie potrzebne zmienne.
     * @return
     */
    bool createMapOfTraffic();

    /**
     * @brief Przekaż informacje o korkach.
     *
     *Metoda pobiera jako parametr koordynaty w których ma sprawdzić wartość korków, a następnie zwraca daną wartość.
     * @param _C - koordynaty środka budynku.
     * @return Wartość korków w obszarze lub jeśli koordynaty sa niepoprawne zwraca -1;
     */
    double giveTrafficInfo(CCoordinates _C) const;
    /**
     * @brief Policz korki.
     *
     *Metoda pozwala ana policzneie korków w danych obszarach. Następnie wpisuje informacje do uproszczonej mapy korków.
     */
    void countTraffic();
    ///Wyczyść tymczasowe zmienne.
    void clearTemporary();
};

#endif // CTRAFFICENGINE_H
