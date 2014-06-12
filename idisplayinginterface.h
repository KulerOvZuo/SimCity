#ifndef IDISPLAYINGINTERFACE_H
#define IDISPLAYINGINTERFACE_H

#include <QList>
#include <QString>
#include <QPixmap>
#include "cstructure.h"

/**
 * @brief Klasa IDisplayingInterface (interfejs wyświetlajacy)
 *
 *Jest klasą abstrakcyjnąm, nadrzędną dla widoku.
 */
class IDisplayingInterface
{
public:
    IDisplayingInterface();
    virtual ~IDisplayingInterface();

    /**
     * @brief Informacje do Wyświetlenia.
     *
     *Metoda zwraca listę stringów, które należy wyświetlić.
     * @return  Lista stringów do wyświetlenia.
     */
    virtual QList<QString> infoToDisplay();
    /**
     * @brief Wyświetl.
     *
     *Metoda implementująca sposób wyświetlania danych przekazanych w argumencie.
     * @param _toDisplay - lista stringów do wyświetlenia.
     */
    virtual void display(QList<QString> _toDisplay);
    /**
     * @brief Znajdź odpowiednią grafikę.
     *
     *Metoda szuka odpowiedniej grafiki w zależności od rodzaju budynku.
     * @param _S - wskaźnik do budynku
     * @return Zwraca znalezioną pixmapę. Jesli nie znaleziono, zwraca grafikę "no image".
     */
    virtual QPixmap findGraphicForBuilding(CStructure *_S);
};

#endif // IDISPLAYINGINTERFACE_H
