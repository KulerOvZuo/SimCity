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

class CGraphicGameTile : public QGraphicsObject
{
    Q_OBJECT
private:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

protected:
    QSize tileSize;
    QBrush brush;
    bool moving;
    QPixmap pixMap;

public:
    CGraphicGameTile(QSize tileSize, QObject *sender = 0);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    void setTileSize(QSize _size);
    void setBrush(QBrush brush);
    void setMoving(bool _mov);
    void setPixmap(QPixmap _map);

signals:
    void mouseClicked(QPointF,QGraphicsSceneMouseEvent *);
private slots:
    void repaintTile(QBrush,QSize,QSize);  
};

#endif // CGRAPHICGAMETILE_H
