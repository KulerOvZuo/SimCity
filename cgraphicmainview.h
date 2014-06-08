#ifndef CGRAPHICMAINVIEW_H
#define CGRAPHICMAINVIEW_H

#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsScene>
#include <cmath>
#include <cstructure.h>
#include <QSize>
#include <QObject>
#include "cgraphicgametile.h"

class CGraphicMainView : public QGraphicsView
{
    //Q_OBJECT
public:
    CGraphicMainView(QSize _gameMap = QSize(100,60), QSize _tileSize = QSize(50,50),QWidget *parent = 0);
    void setTileSize(QSize _size);
    void setGameMapSize(QSize _size);
    void initializeGameMap();

protected:
    QGraphicsScene* scene;
    QSize tileSize;
    QSize gameMapSize;

    CStructure *curentHoldingStructure;
    qreal actualFactor;
    bool structureSelected;
    bool structureHolding;

#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *);
#endif
    void scaleView(qreal scaleFactor);
    void mouseMoveEvent(QMouseEvent *event);

/*signals:
    void repaintAreaUnderBuilding(QSize _pos, QSize _size);*/
};

#endif // CGRAPHICMAINVIEW_H
