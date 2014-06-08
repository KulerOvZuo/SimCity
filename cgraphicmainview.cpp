#include "cgraphicmainview.h"
#include <QPalette>
#include <QPixmap>
#include <QtCore>
#include <QCursor>

CGraphicMainView::CGraphicMainView(QSize _gameMap, QSize _tileSize,QWidget *parent) :
    QGraphicsView(parent), tileSize(_tileSize),gameMapSize(_gameMap)
{
    curentHoldingStructure = NULL;
    structureSelected=false;
    structureHolding=false;

    int _w = gameMapSize.width()*tileSize.width();
    int _h = gameMapSize.height()*tileSize.height();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,_w,_h);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setBackgroundBrush(QPixmap("://textureFlip.jpg"));
    scene->update();
    QPen pen;
    pen.setWidth(10);
    scene->addRect(scene->sceneRect(),pen);

    this->setScene(scene);
    this->initializeGameMap();
    actualFactor = 1;

    this->setCacheMode(QGraphicsView::CacheBackground);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->setRenderHint(QPainter::Antialiasing);
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setMinimumSize(200,150);
    this->resize(_w,_h);
    this->setMouseTracking(true);
    this->update();
    this->show();
}
void CGraphicMainView::setTileSize(QSize _size)
{   tileSize =_size;}
void CGraphicMainView::setGameMapSize(QSize _size)
{   gameMapSize = _size;}
void CGraphicMainView::initializeGameMap()
{
    qDebug()<<"map initialize";
    /*CGraphicGameTile *newTile = new CGraphicGameTile(tileSize);
                newTile->setPos(0*tileSize.width(),0*tileSize.height());
                scene->addItem(newTile);*/
    for(int x=0; x<gameMapSize.width(); x++)
        for(int y=0; y<gameMapSize.height();y++)
        {   CGraphicGameTile *newTile = new CGraphicGameTile(tileSize);
            newTile->setPos(x*(tileSize.width()),y*(tileSize.height()));
            scene->addItem(newTile);
        }
    scene->update();
}

#ifndef QT_NO_WHEELEVENT
void CGraphicMainView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2,event->delta()/240.0));
}
#endif
void CGraphicMainView::scaleView(qreal scaleFactor)
{   qreal factor = this->transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor <0.5 || factor >100)
        return;
    actualFactor = factor;
    this->scale(scaleFactor,scaleFactor);
    this->translate(50,50);
    this->repaint();
}
void CGraphicMainView::mouseMoveEvent(QMouseEvent *event)
{
    ///if we are holding structure, change colors of backgroud tiles
    if(structureHolding)
    {

        //int _x = curentHoldingStructure->getSizeOnGameMap().getX();
       // int _y = curentHoldingStructure->getSizeOnGameMap().getY();
        //emit repaintAreaUnderBuilding(QSize(_x,_y),QSize(_x,_y));
    }
}
