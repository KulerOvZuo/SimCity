#ifndef CGRAPHICGAMETILE_H
#define CGRAPHICGAMETILE_H

#include <QGraphicsItem>
#include <QGraphicsObject>
#include <QSize>
#include <QAction>
#include <QToolTip>
#include <QPainter>
#include <QMouseEvent>
#include <QString>
#include "idisplayinginterface.h"

/**
 * @brief Klasa CGraphicGameTile (żeton gry)
 *
 *Klasa jest graficznym przedstawieniem żetonu na mapie. Jest nadrzędna wobec wszystkich żetonów.
 *Implementuje event kliknięcia oraz sposób wyświetlania zależny od atrybutów.
 */
class CGraphicGameTile : public QGraphicsObject, public IDisplayingInterface
{
    Q_OBJECT
private:
    /**
     * @brief Kliknięcie myszą.
     *
     *Reimplementacja metody kliknięcia myszą.
     *Wywołuje wyemitowanie sygnału\b mouseCLicked()\c z parametrami wskaźnika do siebie, punktu kliknięcia względem sceny oraz event.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent *event);

protected:
    ///Rozmiar żetonu w pixelach.
    QSize tileSize;
    ///Brush.
    QBrush brush;
    /**
     * @brief Ruchomy.
     *
     *Określa czy żeton jest ruchomym elementem planszy czy statycznym.
     */
    bool moving;
    /**
     * @brief Pixmapa
     *
     *Określa pixmapę, która jest wyświetlana na żetonie.
     */
    QPixmap pixMap;

public:
    /**
     * @brief CGraphicGameTile  - konstruktor
     *
     *Konstruktor z parametrami.
     *Ustawia wymiary żetonu równe \b tileSize \c oraz łączy sygnał z obiektu \b sender\c z wywołaniem metody \b repaintTile();
     * @param tileSize - rozmiar żetonu
     * @param sender
     */
    CGraphicGameTile(QSize tileSize, QObject *sender = 0);

    /**
     * @brief "Prostokąt znaczący".
     *
     *Zwraca wymiar żetonu w formie prostokątu.
     */
    QRectF boundingRect() const;
    /**
     * @brief Rysuj.
     *
     *Reimlementacja metody rysuj.
     *Metoda implementuje sposób w jaki zostanie wyświetlona płytka w zależności od jej atrybutów:
     *Ruchoma będzie półprzezroczysta.
     * @param painter - "malarz"
     * @param option (nie użyte)
     * @param widget (nie użyte)
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    ///Ustaw rozmiar żetonu w pixelach.
    void setTileSize(QSize _size);
    void setBrush(QBrush brush);
    ///Ustaw ruchomy.
    void setMoving(bool _mov);
    ///Ustaw pixmapę obiektu.
    void setPixmap(QPixmap _map);

signals:
    /**
     * @brief Kliknięty myszką.
     *
     *Sygnał emitowany, kiedy obiekt został kliknięty myszką.
     */
    void mouseClicked(CGraphicGameTile*, QPointF, QGraphicsSceneMouseEvent *);
private slots:
    /**
     * @brief Pomaluj ponownie żeton.
     *
     *Metoda wywołuje ponowne pomalowanie żetonu jeśli znajduje się w obrębie prostokata.
     * @param QBrush - "pędzel"
     * @param QSize - pozycja lewe górnego rogu prostokąta
     * @param QSize - wymiary prostokąta
     */
    void repaintTile(QBrush,QSize,QSize);
};

#endif // CGRAPHICGAMETILE_H
