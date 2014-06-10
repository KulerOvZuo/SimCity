#include "cgraphicbuildingtile.h"
#include <QSize>
#include <QMenu>

CGraphicBuildingTile::CGraphicBuildingTile(CStructure* _structure,QSize tileSize, QObject *sender) : CGraphicGameTile(tileSize,sender)
{
    selected = false;
    fullyBuilded = false;
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
    if(selected==false)
        painter->setPen(QPen(Qt::green,1,Qt::DotLine,Qt::RoundCap,Qt::RoundJoin));
    if(fullyBuilded==false)
    {   painter->setOpacity(0.8);
        brush.setStyle(Qt::SolidPattern);
    }
    else
        painter->setOpacity(1);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing,true);
    QRectF rect(0,0,structure->getSizeOnGameMap().getX()*tileSize.width(),structure->getSizeOnGameMap().getY()*tileSize.height());
    //painter->drawRoundedRect(rect,tileSize.width()/10,tileSize.height()/10);
    QRectF pixMapRectF;
    pixMapRectF =QRectF(0,0,pixMap.size().width(),pixMap.size().height());
    painter->rotate(0);
    if(structure->getTurnedDirection().getDirUp() == false && structure->getTurnedDirection().getDirDown() == false)
    {   QPixmap temp(pixMap);
        painter->translate(rect.height(),0);
        painter->rotate(90);
        rect = QRectF(0,-tileSize.height()*(structure->getSizeOnGameMap().getX()-structure->getSizeOnGameMap().getY()),rect.height(),rect.width());
    }
    painter->drawPixmap(rect,pixMap,pixMapRectF);
}

void CGraphicBuildingTile::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{Q_UNUSED(event);}
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
