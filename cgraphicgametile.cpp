#include "cgraphicgametile.h"
#include <QTranslator>
#include <QMimeData>
#include <QMoveEvent>
#include <QtWidgets>
#include <QObject>
#include <QPixmap>
#include "cgraphicmainview.h"

CGraphicGameTile::CGraphicGameTile(QSize tileSize, QObject *sender) : QGraphicsObject(), IDisplayingInterface()
{
    this->tileSize = tileSize;
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
     //QPointF pos =this->scenePos();
    // emit mouseClicked(pos,event);
    Q_UNUSED(event);
}
void CGraphicGameTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //Q_UNUSED(event);
    QPointF pos =this->scenePos();
   // qDebug()<<pos.x()<<" "<<pos.y();
    //qDebug()<<"clicked";
    emit mouseClicked(this,pos,event);
    //setCursor(Qt::ClosedHandCursor);
}
void CGraphicGameTile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //setCursor(Qt::OpenHandCursor);
    Q_UNUSED(event);
}

QRectF CGraphicGameTile::boundingRect() const
{  
    return QRectF(tileSize.width()*0,tileSize.height()*0,tileSize.width()*1,tileSize.height()*1);
}
void CGraphicGameTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //this->setToolTip(QString("Empty field\nPos(%1,%2)").arg(this->pos().x()/tileSize.width(),1).arg(this->pos().y()/tileSize.height(),1));
    painter->setPen(QPen(Qt::black,1,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));
    if(moving==true)
    {   painter->setOpacity(0.8);    }
    else
        painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing,true);
    QRectF rect((tileSize.width()*0.01),(tileSize.height()*0.01),
                (tileSize.width()-tileSize.width()*0.02),
                (tileSize.height()-tileSize.height()*0.02));
    if(moving==true)
    {   //painter->drawRoundedRect(rect,5,5);
        QRectF pixMapRectF(0,0,pixMap.size().width(),pixMap.size().height());
        brush.setStyle(Qt::NoBrush);
        painter->setPen(QPen(Qt::blue,2,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));
        painter->drawRect(rect);
        painter->drawPixmap(rect,pixMap,pixMapRectF);
       // painter->drawPixmap(rect,px);
    }
    else
    {   painter->drawRoundedRect(rect,tileSize.width()*0.2,tileSize.height()*0.2);
    }
}

void CGraphicGameTile::setTileSize(QSize _size)
{   tileSize=_size;}
void CGraphicGameTile::setBrush(QBrush brush)
{   this->brush=brush;}
void CGraphicGameTile::setMoving(bool _mov)
{   moving = _mov;}
void CGraphicGameTile::setPixmap(QPixmap _map)
{   pixMap = _map;}
void CGraphicGameTile::repaintTile(QBrush brush, QSize pos, QSize size)
{
    pos += QSize(-0.1,-0.1);
    if(moving==false)
    {   if(((this->pos().x()/tileSize.width()) >= pos.width() && (this->pos().x()/tileSize.width()) <(pos+size).width()) )
        { // qDebug()<<"repaintx";
           if((this->pos().y()/tileSize.height()) >= pos.height() && (this->pos().y()/tileSize.height()) < (pos.height()+abs(size.height())))
           {   //qDebug()<<"repaintxy";
               //qDebug()<<"tilex: "<<this->pos().x()/50;
              // qDebug()<<"tiley: "<<this->pos().y()/50;
               this->brush = brush;
               //this->show();
               this->update();
           }
        }}
}

