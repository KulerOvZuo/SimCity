#ifndef CGRAPHICMAINVIEW_H
#define CGRAPHICMAINVIEW_H

#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsView>
#include <QPainter>
#include <QGraphicsScene>
#include <cmath>

class CGraphicMainView : public QGraphicsView
{
public:
    CGraphicMainView(int _w = 600, int _x = 400,QWidget *parent = 0);

protected:
    QGraphicsScene* scene;

#ifndef QT_NO_WHEELEVENT
    void wheelEvent(QWheelEvent *);
#endif
    void scaleView(qreal scaleFactor);
};

#endif // CGRAPHICMAINVIEW_H
