#ifndef CDIRECTIONS_H
#define CDIRECTIONS_H

#include "enumerators.h"
/**
 * @brief Klasa CDirections (kierunki).
 *
 *Klasa pozwala na przechowywanie bool'owskich informacji o 4 podstawowych kierunkach.
 *Implementuje możliwość obrotu.
 */
class CDirections
{
protected:
    ///Zmienna kierunku GÓRA
    bool dirUp;
    ///Zmienna kierunku PRAWO
    bool dirRight;
    ///Zmienna kierunku DÓŁ
    bool dirDown;
    ///Zmienna kierunku LEWO
    bool dirLeft;

    /**
     * @brief Rotuj w prawo.
     *
     *Metoda rotuje zmienne kierunków w prawo o 1 zmienną.
     * @return Prawda jeśli poprawnie.
     */
    bool rotateRight();
    /**
     * @brief Rotuj w lewo.
     *
     *Metoda rotuje zmienne kierunków w lewo o 1 zmienną.
     * @return Prawda jeśli poprawnie.
     */
    bool rotateLeft();
public:
    CDirections();
    /**
     * @brief Konstruktor z parametrami.
     *
     *Inicjalizuje obiekt z atrybutami zależnymi od parametrów
     * @param _dirUp - kierunek GÓRA
     * @param _dirRight - kierunek PRAWO
     * @param _dirDown - kierunek DÓŁ
     * @param _dirLeft - kierunek LEWO
     */
    CDirections(bool _dirUp, bool _dirRight=false, bool _dirDown=false, bool _dirLeft=false);
    ///Konstruktor kopiujący
    CDirections(const CDirections& _D);
    /**
     * @brief Ustaw kierunki.
     * @param _dirUp - kierunek GÓRA
     * @param _dirRight - kierunek PRAWO
     * @param _dirDown - kierunek DÓŁ
     * @param _dirLeft - kierunek LEWO
     * @return
     */
    void setDirections(bool _dirUp=true, bool _dirRight=false, bool _dirDown=false, bool _dirLeft=false);
    /**
     * @brief Rotuj o kąt.
     *
     *Metoda pozwalająca na obrót o wybrany kąt zgodny z enum Erotation.
     * @param rotateAngle - kąt obrotu
     * @return Prawda jeśli poprawnie.
     */
    bool rotate(Erotation  rotateAngle);

    ///Pobierz wartość kierunku GÓRA
    bool getDirUp() const;
    ///Pobierz wartość kierunku PRAWO
    bool getDirRight() const;
    ///Pobierz wartość kierunku DÓŁ
    bool getDirDown() const;
    ///Pobierz wartość kierunku LEWO
    bool getDirLeft() const;
};

#endif // CDIRECTIONS_H
