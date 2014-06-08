#ifndef CGRAPHICGAMETILE_H
#define CGRAPHICGAMETILE_H

#include <QGraphicsItem>
#include <QSize>
#include <QAction>
#include <QToolTip>
#include <QPainter>
#include <QMouseEvent>
#include <QString>

class CGraphicGameTile : public QGraphicsItem
{
protected:
    QSize tileSize;

    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

public:
    CGraphicGameTile(QSize size);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setTileSize(QSize _size);
private slots:

};

#endif // CGRAPHICGAMETILE_H
