#ifndef CGRAPHICBUILDINGTILE_H
#define CGRAPHICBUILDINGTILE_H

#include "cgraphicgametile.h"
#include "cstructure.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QString>

/**
 * @brief Klasa CGraphicBuildingTile (żeton budynku)
 *
 *Klasa jest graficznym przedstawieniem żetonu budynku na mapie.
 *Implementuje m.in. menu kontekstowe, sposób wyświetlania żetonu oraz informacji.
 */
class CGraphicBuildingTile : public CGraphicGameTile
{
    Q_OBJECT
private:
    /**
     * @brief Menu kontekstowe.
     *
     *Metoda reimplementuje event menu kontekstowego.
     *Po kliknięciu jest możliwość wywołania dwóch metod, \b showInfo \c lub \b destroy \c;
     * @param event
     */
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    ///Połącz wszystkie sygnały.
    void connectAll(QObject *sender);
protected:
    ///Wskaźnik do powiązanej struktury.
    CStructure* structure;

    ///Akcja pokaż informacje o obiekcie.
    QAction *showInfoAct;
    ///Akcja zniszcz obiekt.
    QAction *destroyAct;
public:
    /**
     * @brief CGraphicBuildingTile - konstruktor
     *
     *Konstruktor z parametrami.
     *Inicjalizuje obiekt podanymi parametrami.
     * @param _structure - wskaźnik do powiązanej struktury
     * @param tileSize - rozmiar bazowy żetonu w grze
     * @param sender
     */
    CGraphicBuildingTile(CStructure* _structure, QSize tileSize, QObject *sender = 0);
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
     *Metoda implementuje sposób w jaki zostanie wyświetlona płytka w zależności od jej atrybutów m.in:
     *rozmiaru budynku, kąta obrotu budynku
     * @param painter - "malarz"
     * @param option (nie użyte)
     * @param widget (nie użyte)
     */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    /**
     * @brief Wyświetl.
     *
     *Implementacja metody inteface'u.
     *Określa w jaki sposób mają być wyświetlone informacje o obiekcie pobrane z modelu.
     *Wyświetla okno dialogowe.
     * @param _toDisplay
     */
    virtual void display(QList<QString> _toDisplay);

    ///Zwraca wskaźnik do powiązanej struktury.
    CStructure* getStructure();
signals:
    ///Sygnał emitowany przy kliknięciu niszczenia budynku.
    void destroySignal(CGraphicBuildingTile *);
    ///Sygnał emitowany przy kliknięciu niszczenia budynku.
    void destroySignal(CGraphicBuildingTile *,CStructure *);
private slots:
    void destroy();
    void showInfo();
};

#endif // CGRAPHICBUILDINGTILE_H
