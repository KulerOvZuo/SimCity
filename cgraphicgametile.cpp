#include "cgraphicgametile.h"
#include <QTranslator>
#include <QMimeData>
#include <QMoveEvent>
#include <QtWidgets>
#include <QObject>
#include <cgraphicmainview.h>

CGraphicGameTile::CGraphicGameTile(QSize size, QObject *sender) : QGraphicsObject()
{
    tileSize = size;
    brush.setColor(Qt::NoPen);
    moving=false;
    setAcceptDrops(true);
    setAcceptedMouseButtons(Qt::LeftButton);
    if(sender !=NULL)
    {   connect(sender,SIGNAL(repaintAreaUnderBuilding(QBrush,QSize,QSize)),this,SLOT(repaintTile(QBrush,QSize,QSize)));
        setParent(sender);}
}

void CGraphicGameTile::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //setCursor(Qt::ClosedHandCursor);
    Q_UNUSED(event);
}
void CGraphicGameTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QPointF pos =this->scenePos();
    emit mouseClicked(pos,event);
    //setCursor(Qt::ClosedHandCursor);
}
void CGraphicGameTile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //setCursor(Qt::OpenHandCursor);
    Q_UNUSED(event);
}

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
    if(moving==true)
        painter->setOpacity(0.5);
    else
        painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing,true);
    QRectF rect((this->boundingRect().width()*0.05),(this->boundingRect().height()*0.05),(this->boundingRect().width()*0.9),(this->boundingRect().height()*0.9));
    painter->drawRoundedRect(rect,20,20,Qt::RelativeSize);
}

void CGraphicGameTile::setTileSize(QSize _size)
{   tileSize=_size;}
void CGraphicGameTile::setBrush(QBrush brush)
{   this->brush=brush;}
void CGraphicGameTile::setMoving(bool _mov)
{   moving = _mov;}
void CGraphicGameTile::repaintTile(QBrush brush, QSize pos, QSize size)
{
    //qDebug()<<"repaint"<<this->pos().x();
   // this->scenePos();
    if(moving==false)
    {    if(((this->pos().x()/tileSize.width()) >= pos.width() && (this->pos().x()/tileSize.width()) <(pos+size).width()) )
        { // qDebug()<<"repaintx";
           if((this->pos().y()/tileSize.height()) >= pos.height() && (this->pos().y()/tileSize.height()) < (pos.height()+abs(size.height())))
           {   //qDebug()<<"repaintxy";
               //qDebug()<<this->pos().x();
               //qDebug()<<this->pos().y();
               this->brush = brush;
               this->update();}
        }}
}
