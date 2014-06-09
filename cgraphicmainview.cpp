#include "cgraphicmainview.h"
#include <QPalette>
#include <QPixmap>
#include <QtCore>
#include <QCursor>
#include "mainwindow.h"

CGraphicMainView::CGraphicMainView(QSize _gameMap, QSize _tileSize,QWidget *parent) :
    QGraphicsView(parent), tileSize(_tileSize),gameMapSize(_gameMap)
{
    curentHoldingStructure = NULL;
    movingTile=NULL;
    structureSelected=false;
    structureHolding=false;
    beforeCursorPoint=QPoint(0,0);
    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    /*///[3] repaint timer
    repaintTimer = new QTimer(this);
    repaintTimer->setInterval(300);
    repaintTimer->setSingleShot(true);
    connect(repaintTimer,SIGNAL(timeout()),this,SLOT());
    ///[/3]*/

    connect(parent,SIGNAL(newStructure(CStructure)),this,SLOT(newStructureChosen(CStructure)));
    connect(parent,SIGNAL(canBeBuiled(bool)),this,SLOT(buildStructure(bool)));

    int _w = gameMapSize.width()*tileSize.width();
    int _h = gameMapSize.height()*tileSize.height();

    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,_w,_h);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setBackgroundBrush(QPixmap("://textureFlip.jpg"));
    scene->update();
    QPen pen;
    pen.setWidth(10);
    scene->addRect(scene->sceneRect(),pen);

    this->setScene(scene);
    this->initializeGameMap();
    actualFactor = 1;

    this->setCacheMode(QGraphicsView::CacheBackground);
    this->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    this->setRenderHint(QPainter::Antialiasing);
    this->setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    this->setMinimumSize(200,150);
    //this->setMaximumSize(_w,_h);
    this->resize(_w,_h);
    this->setMouseTracking(true);
    this->update();
    this->show();
}
void CGraphicMainView::setTileSize(QSize _size)
{   tileSize =_size;}
void CGraphicMainView::setGameMapSize(QSize _size)
{   gameMapSize = _size;}

void CGraphicMainView::initializeGameMap()
{
    for(int x=0; x<gameMapSize.width(); x++)
        for(int y=0; y<gameMapSize.height();y++)
        {   CGraphicGameTile *newTile = new CGraphicGameTile(tileSize,this);
            newTile->setPos(x*(tileSize.width()),y*(tileSize.height()));
            connect(newTile,SIGNAL(mouseClicked(QPointF,QGraphicsSceneMouseEvent*)),this,SLOT(emptyTileMouseClicked(QPointF,QGraphicsSceneMouseEvent*)));
            scene->addItem(newTile);
        }
    scene->update();
}

#ifndef QT_NO_WHEELEVENT
void CGraphicMainView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2,event->delta()/240.0));
}
#endif
void CGraphicMainView::scaleView(qreal scaleFactor)
{   qreal factor = this->transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor <0.5 || factor >100)
        return;
    actualFactor = factor;
    this->scale(scaleFactor,scaleFactor);
    //this->repaint();
}
QSize CGraphicMainView::itemPosition(const QPoint &pos)
{
    Q_UNUSED(pos);
    scene->items();
    return QSize();
}

void CGraphicMainView::mouseMoveEvent(QMouseEvent *event)
{
    mouseMoveRepaint(event);
}
void CGraphicMainView::keyPressEvent(QKeyEvent *event)
{
    ///rotate
    if(event->key()==Qt::Key_R)
    {   if(curentHoldingStructure!=NULL && structureHolding==true)
        {
            //qDebug()<<"R";
            QSize pos;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            int _x = curentHoldingStructure->getSizeOnGameMap().getX();
            int _y = curentHoldingStructure->getSizeOnGameMap().getY();
            ///cleaning before
            QBrush brush;
            brush.setColor(Qt::NoPen);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));

            curentHoldingStructure->rotate(rightRot);
            ///drawing new
            _x = curentHoldingStructure->getSizeOnGameMap().getX();
            _y = curentHoldingStructure->getSizeOnGameMap().getY();
           // qDebug()<<"x: "<<_x<<"y: "<<_y;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            brush.setColor(Qt::darkBlue);
            brush.setStyle(Qt::SolidPattern);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));
        }
    }
    ///stop handling structure
    if(event->key()==Qt::Key_Escape)
    {  // qDebug()<<"esc";
        structureHolding=false;
        if(movingTile!=NULL)
        {
            QSize pos;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            int _x = curentHoldingStructure->getSizeOnGameMap().getX();
            int _y = curentHoldingStructure->getSizeOnGameMap().getY();
            QBrush brush;
            brush.setColor(Qt::NoPen);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));

            scene->removeItem(movingTile);
            delete movingTile;
            movingTile=NULL;

            //scene->update();
        }
        if(curentHoldingStructure!=NULL)
        {   delete curentHoldingStructure;
            curentHoldingStructure=NULL;}
        setCursor(Qt::ArrowCursor);
    }
}
void CGraphicMainView::newStructureChosen(CStructure structure)
{
    if(movingTile!=NULL)
    {   delete movingTile;

        int _x = curentHoldingStructure->getSizeOnGameMap().getX();
        int _y = curentHoldingStructure->getSizeOnGameMap().getY();
        //qDebug()<<"repaint";
        QSize pos;
        pos.setWidth(beforeCursorPoint.x()/tileSize.width());
        pos.setHeight(beforeCursorPoint.y()/tileSize.height());
        //qDebug()<<beforeCursorPoint.x()<<" "<<beforeCursorPoint.y();

        QBrush brush;
        brush.setColor(Qt::NoPen);
        this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));
        scene->update();
    }

    structureHolding=true;
    curentHoldingStructure = new CStructure(structure);
    ///[erase]
    curentHoldingStructure->setSizeOnGameMap(CCoordinates(2,1));
    ///[]
    movingTile = new CGraphicGameTile(tileSize);
    movingTile->setMoving(true);
    QBrush brush;
    brush.setColor(Qt::darkBlue);
    brush.setStyle(Qt::SolidPattern);
    movingTile->setBrush(brush);
    scene->addItem(movingTile);
}
void CGraphicMainView::mouseMoveRepaint(QMouseEvent *event)
{
    ///if we are holding structure, change colors of backgroud tiles
    if(structureHolding)
    {   QPoint cursorPos;
        cursorPos = mapFromParent(event->pos());
        movingTile->setPos(event->pos()-QPoint(1,1));

        if((abs(beforeCursorPoint.x()-cursorPos.x())>tileSize.width()/3) || (abs(beforeCursorPoint.y()-cursorPos.y())>tileSize.height()/3))
        {  // qDebug()<<"size";
            int _x = curentHoldingStructure->getSizeOnGameMap().getX();
            int _y = curentHoldingStructure->getSizeOnGameMap().getY();
            //qDebug()<<"repaint";
            QSize pos;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            //qDebug()<<beforeCursorPoint.x()<<" "<<beforeCursorPoint.y();

            QBrush brush;
            brush.setColor(Qt::NoPen);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));
           // scene->update();

            beforeCursorPoint = cursorPos;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            brush.setColor(Qt::darkBlue);
            brush.setStyle(Qt::SolidPattern);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));
        }
        }
}
void CGraphicMainView::emptyTileMouseClicked(QPointF pos, QGraphicsSceneMouseEvent *event)
{
    if(structureHolding)
    {  // qDebug()<<"clicked";
       // qDebug()<<pos.x()<<" "<<pos.y();
        CCoordinates _C = CCoordinates(pos.x()/tileSize.width(),pos.y()/tileSize.height());
        curentHoldingStructure->setCoordinatesOfActualLUCorner(_C);
        emit checkIfCanBeBuiled(curentHoldingStructure);
    }
}
void CGraphicMainView::buildStructure(bool)
{
    qDebug()<<"building...";
    ///graphical build
    /*QSize size = tileSize;
    size.setWidth(size.width()*2);
    CGraphicBuildingTile *newTile = new CGraphicBuildingTile(curentHoldingStructure,size);
    scene->addItem(newTile);*/
}
