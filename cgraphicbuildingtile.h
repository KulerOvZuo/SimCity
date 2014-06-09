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
    void connectAll();
protected:
    CStructure* structure;
    bool selected;
    QPixmap pixMap;

    QAction *showInfoAct;
    QAction *destroyAct;
public:
    CGraphicBuildingTile(CStructure* _structure, QSize size, QObject *sender = 0);

private slots:
    void destroy();
    void showInfo();
};

#endif // CGRAPHICBUILDINGTILE_H
