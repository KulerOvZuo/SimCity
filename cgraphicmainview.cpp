#include "cgraphicmainview.h"
#include <QPalette>
#include <QPixmap>
#include <QtCore>
#include <QCursor>

CGraphicMainView::CGraphicMainView(int _w, int _h, QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(-_w/2,-_h/2,_w,_h);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-_w/2,-_h/2,_w,_h);
    scene->setBackgroundBrush(QPixmap("://textureFlip.jpg"));
    scene->update();
    QPen pen;
    pen.setWidth(10);
    scene->addRect(scene->sceneRect(),pen);

    this->setScene(scene);
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
#ifndef QT_NO_WHEELEVENT
void CGraphicMainView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2,event->delta()/240.0));
}
#endif
void CGraphicMainView::scaleView(qreal scaleFactor)
{   qreal factor = this->transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor <0.9 || factor >100)
        return;
    this->scale(scaleFactor,scaleFactor);
    this->translate(50,50);
    this->repaint();
}
