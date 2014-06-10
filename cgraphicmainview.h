#ifndef CGRAPHICMAINVIEW_H
#define CGRAPHICMAINVIEW_H

#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsScene>
#include <cmath>
#include <cstructure.h>
#include <QTimer>
#include <QSize>
#include <QPoint>
#include <QObject>
#include "cgraphicbuildingtile.h"

class CGraphicMainView : public QGraphicsView
{
    Q_OBJECT
private:
    QPoint beforeCursorPoint;
    QPixmap* actualPixMap;
    CGraphicGameTile* movingTile;
    //QTimer* repaintTimer;

public:
    CGraphicMainView(QSize _gameMap = QSize(100,60), QSize _tileSize = QSize(50,50),QWidget *parent = 0);
    void setTileSize(QSize _size);
    void setGameMapSize(QSize _size);
    void initializeGameMap();
    QPixmap findGraphicForBuilding(CStructure *_S);

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
    void scaleView(qreal scaleFactor, QWheelEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

signals:
    void repaintAreaUnderBuilding(QBrush,QSize, QSize);
    void checkIfCanBeBuiled(CStructure *);
    void removeStructure(CStructure*);
private slots:
    void newStructureChosen(CStructure *);
    void mouseMoveRepaint(QMouseEvent *);
    void emptyTileMouseClicked(QPointF,QGraphicsSceneMouseEvent *);
    void buildStructure(CStructure*,bool);
    void removeTile(CGraphicBuildingTile*,CStructure *);
};

#endif // CGRAPHICMAINVIEW_H
