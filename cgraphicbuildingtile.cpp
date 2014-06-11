#include "cgraphicbuildingtile.h"
#include <QSize>
#include <QMenu>
#include "croad.h"
#include "cgreenterrain.h"

CGraphicBuildingTile::CGraphicBuildingTile(CStructure* _structure,QSize tileSize, QObject *sender) : CGraphicGameTile(tileSize,sender)
{
    selected = false;
    structure=_structure;
    connectAll(sender);
    //setBrush(Qt::black);
    if(_structure!=NULL)
    {   this->setPos(structure->getCoordinatesOfActualLUCorner().getX()*tileSize.width(),structure->getCoordinatesOfActualLUCorner().getY()*tileSize.height());
    }
}
QRectF CGraphicBuildingTile::boundingRect() const
{   return QRectF(0,0,tileSize.width()*structure->getSizeOnGameMap().getX(),tileSize.height()*structure->getSizeOnGameMap().getY());}

void CGraphicBuildingTile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    //this->setToolTip(QString("Empty field\nPos(%1,%2)").arg(this->pos().x()/tileSize.width(),1).arg(this->pos().y()/tileSize.height(),1));
    if(selected==true)
        painter->setPen(QPen(Qt::green,3,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));

    painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing,true);
    QRectF rect(0,0,structure->getSizeOnGameMap().getX()*tileSize.width(),structure->getSizeOnGameMap().getY()*tileSize.height());
    //painter->drawRoundedRect(rect,tileSize.width()/10,tileSize.height()/10);
    QRectF pixMapRectF;
    pixMapRectF =QRectF(0,0,pixMap.size().width(),pixMap.size().height());
    painter->rotate(0);
    ///[1]
    QPixmap temp(pixMap);

    if(structure->getTurnedDirection().getDirRight())
    {   painter->translate(rect.height(),0);
        painter->rotate(90);
        rect = QRectF(0,-tileSize.height()*(structure->getSizeOnGameMap().getX()-structure->getSizeOnGameMap().getY()),rect.height(),rect.width());
    }
    if(structure->getTurnedDirection().getDirDown())
    {   painter->rotate(180);
        painter->translate(-rect.width(),-rect.height());
    }
    if(structure->getTurnedDirection().getDirLeft())
    {   painter->translate(rect.width(),rect.height());
        painter->rotate(-90);
        rect = QRectF(0,-tileSize.height()*(structure->getSizeOnGameMap().getX()-structure->getSizeOnGameMap().getY()),rect.height(),rect.width());
        painter->translate(0,-rect.width());
    }

    ///[/1]
    if(dynamic_cast<CRoad*>(structure)==NULL && dynamic_cast<CLawn*>(structure)==NULL)
    {   painter->setPen(QPen(QColor(50,110,155),2,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));
        painter->drawRect(rect);}
    QPixmap _lawn = QPixmap(lawnPixmapSource);
    painter->drawPixmap(rect,_lawn,QRectF(0,0,_lawn.width(),_lawn.height()));
    painter->drawPixmap(rect,pixMap,pixMapRectF);
}

void CGraphicBuildingTile::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{   Q_UNUSED(event);

}
void CGraphicBuildingTile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{Q_UNUSED(event);}
void CGraphicBuildingTile::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{Q_UNUSED(event);}
void CGraphicBuildingTile::contextMenuEvent(QGraphicsSceneContextMenuEvent *event)
{
    QMenu menu;
    menu.addAction(showInfoAct);
    menu.addAction(destroyAct);
    menu.exec(event->screenPos());
}
void CGraphicBuildingTile::connectAll(QObject* sender)
{
    showInfoAct = new QAction(QString("Show info"),this);
    showInfoAct->setStatusTip(tr("Show information about object"));
    connect(showInfoAct,SIGNAL(triggered()),this,SLOT(showInfo()));

    destroyAct = new QAction(tr("&Destoy"),this);
    destroyAct->setStatusTip(tr("Destroy object"));
    connect(destroyAct,SIGNAL(triggered()),this,SLOT(destroy()));

    connect(this,SIGNAL(destroySignal(CGraphicBuildingTile *,CStructure *)),sender,SLOT(removeTile(CGraphicBuildingTile *,CStructure *)));
}
void CGraphicBuildingTile::destroy()
{   emit destroySignal(this,structure);}
void CGraphicBuildingTile::showInfo()
{}
CStructure* CGraphicBuildingTile::getStructure()
{   return structure;}
