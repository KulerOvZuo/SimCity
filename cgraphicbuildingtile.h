#ifndef CGRAPHICBUILDINGTILE_H
#define CGRAPHICBUILDINGTILE_H

#include "cgraphicgametile.h"
#include "cstructure.h"
#include <QGraphicsSceneContextMenuEvent>
#include <QWidget>
#include <QPixmap>
#include <QString>

class CGraphicBuildingTile : public CGraphicGameTile
{
    Q_OBJECT
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void contextMenuEvent(QGraphicsSceneContextMenuEvent *event);
    void connectAll(QObject *sender);
protected:
    CStructure* structure;
    bool selected;
    bool fullyBuilded;

    QAction *showInfoAct;
    QAction *destroyAct;
public:
    CGraphicBuildingTile(CStructure* _structure, QSize tileSize, QObject *sender = 0);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    CStructure* getStructure();
signals:
    void destroySignal(CGraphicBuildingTile *);
    void destroySignal(CGraphicBuildingTile *,CStructure *);
    void showInfoSignal(CGraphicBuildingTile *);
private slots:
    void destroy();
    void showInfo();
};

#endif // CGRAPHICBUILDINGTILE_H
