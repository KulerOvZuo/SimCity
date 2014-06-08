#include "cgraphicgametile.h"
#include <QTranslator>
#include <QMimeData>
#include <QMoveEvent>
#include <QtWidgets>

CGraphicGameTile::CGraphicGameTile(QSize size) : QGraphicsItem()
{
    tileSize = size;
    setAcceptDrops(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}

void CGraphicGameTile::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    setCursor(Qt::ClosedHandCursor);
}
void CGraphicGameTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    event->DragEnter;
    setCursor(Qt::ClosedHandCursor);
}
void CGraphicGameTile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{   setCursor(Qt::ArrowCursor);}


QRectF CGraphicGameTile::boundingRect() const
{
    return QRectF(0,0,tileSize.width(),tileSize.height());
}
void CGraphicGameTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    this->setToolTip(QString("Empty field\nPos(%1,%2)").arg(this->pos().x()/tileSize.width(),1).arg(this->pos().y()/tileSize.height(),1));
    painter->setPen(QPen(Qt::black,2,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));
    painter->setBrush(Qt::NoBrush);
    painter->setRenderHint(QPainter::Antialiasing,true);
   // QRectF rect(this->boundingRect());
    QRectF rect((this->boundingRect().width()*0.05),(this->boundingRect().height()*0.05),(this->boundingRect().width()*0.9),(this->boundingRect().height()*0.9));
    painter->drawRoundedRect(rect,20,20,Qt::RelativeSize);
}

void CGraphicGameTile::setTileSize(QSize _size)
{   tileSize=_size;}
