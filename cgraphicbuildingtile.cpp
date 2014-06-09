#include "cgraphicbuildingtile.h"
#include <QMenu>

CGraphicBuildingTile::CGraphicBuildingTile(CStructure* _structure,QSize size, QObject *sender) : CGraphicGameTile (size,sender)
{
    selected = false;
    structure=_structure;
    connectAll();
    setBrush(Qt::black);
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
void CGraphicBuildingTile::connectAll()
{
    showInfoAct = new QAction(QString("Show info"),this);
    showInfoAct->setStatusTip(tr("Show information about object"));
    connect(showInfoAct,SIGNAL(triggered()),this,SLOT(showInfo()));

    destroyAct = new QAction(tr("&Destoy"),this);
    destroyAct->setStatusTip(tr("Destroy object"));
    connect(destroyAct,SIGNAL(triggered()),this,SLOT(destroy()));
}
void CGraphicBuildingTile::destroy()
{}
void CGraphicBuildingTile::showInfo()
{}
