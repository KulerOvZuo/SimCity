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

    connect(parent,SIGNAL(newStructure(CStructure*)),this,SLOT(newStructureChosen(CStructure*)));
    connect(parent,SIGNAL(canBeBuiled(CStructure*, bool)),this,SLOT(buildStructure(CStructure*,bool)));
    connect(this,SIGNAL(removeStructure(CStructure*)),parent,SLOT(destroy(CStructure*)));

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
            connect(newTile,SIGNAL(mouseClicked(CGraphicGameTile*,QPointF,QGraphicsSceneMouseEvent*)),this,SLOT(emptyTileMouseClicked(CGraphicGameTile*,QPointF,QGraphicsSceneMouseEvent*)));
            scene->addItem(newTile);
        }
    scene->update();
}
QPixmap CGraphicMainView::findGraphicForBuilding(CStructure *_S)
{
    //qDebug()<<"picture finding..";
    if(dynamic_cast<CStructure*>(_S)==NULL)
    {   return QPixmap(noImagePixmapSource);
        qDebug()<<"no image";
    }
    if(dynamic_cast<CHouse*>(_S) !=NULL)
    {  // qDebug()<<"house";
        return QPixmap(housePixmapSource);
    }
    if(dynamic_cast<CBlocks*>(_S) !=NULL)
    {   return QPixmap(blocksPixmapSource);
    }
    if(dynamic_cast<CLawn*>(_S) !=NULL)
    {   return QPixmap(lawnPixmapSource);
    }
    if(dynamic_cast<CPark*>(_S) !=NULL)
    {   return QPixmap(parkPixmapSource);
    }
    if(dynamic_cast<COffice*>(_S) !=NULL)
    {   return QPixmap(officePixmapSource);
    }
    if(dynamic_cast<CSmallShop*>(_S) !=NULL)
    {   return QPixmap(shopPixmapSource);
    }
    if(dynamic_cast<CSchoolAllInOne*>(_S) !=NULL)
    {   return QPixmap(schoolPixmapSource);
    }
    if(dynamic_cast<CCinema*>(_S) !=NULL)
    {   return QPixmap(cinemaPixmapSource);
    }
    if(dynamic_cast<CFarm*>(_S) !=NULL)
    {   return QPixmap(farmPixmapSource);
    }
    if(dynamic_cast<CLightFactory*>(_S) !=NULL)
    {   return QPixmap(lightPixmapSource);
    }
    if(dynamic_cast<CHeavyFactory*>(_S) !=NULL)
    {   return QPixmap(heavyPixmapSource);
    }
    if(dynamic_cast<CPublicUtilityBuildingAllInOne*>(_S) !=NULL)
    {   return QPixmap(publicPixmapSource);
    }
    if(dynamic_cast<CRoadStraight*>(_S) !=NULL)
    {   return QPixmap(straightPixmapSource);
    }
    if(dynamic_cast<CRoadCross*>(_S) !=NULL)
    {   return QPixmap(crossPixmapSource);
    }
    if(dynamic_cast<CRoadTurning*>(_S) !=NULL)
    {   return QPixmap(turningPixmapSource);
    }
    qDebug()<<"no image";
    return QPixmap("://noimage.jpg");
}
#ifndef QT_NO_WHEELEVENT
void CGraphicMainView::wheelEvent(QWheelEvent *event)
{
    scaleView(pow((double)2,event->delta()/240.0),event);
}
#endif
void CGraphicMainView::scaleView(qreal scaleFactor, QWheelEvent *event)
{   qreal factor = this->transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
    if(factor <0.5 || factor >100)
        return;
    actualFactor = factor;
    this->scale(scaleFactor,scaleFactor);

    QPoint cursorPos;
    cursorPos = mapFromParent(event->pos());
    QPointF pointF = mapToScene(cursorPos);
    cursorPos.setX(pointF.x());
    cursorPos.setY(pointF.y());
    this->centerOn(cursorPos);
    //this->repaint();
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
            movingTile->setRotation(movingTile->rotation()+90);
            /*if(movingTile->rotation() == 90)
                movingTile->setRotation(0);
            else
                movingTile->setRotation(90);*/

            ///drawing new
            _x = curentHoldingStructure->getSizeOnGameMap().getX();
            _y = curentHoldingStructure->getSizeOnGameMap().getY();
           // qDebug()<<"x: "<<_x<<"y: "<<_y;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            brush.setColor(Qt::darkBlue);
            brush.setStyle(emptyTileHighlightStyle);
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
void CGraphicMainView::newStructureChosen(CStructure *structure)
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
    curentHoldingStructure = structure;
    QSize size;
    size.setWidth(curentHoldingStructure->getSizeOnGameMap().getX()*tileSize.width());
    size.setHeight(curentHoldingStructure->getSizeOnGameMap().getY()*tileSize.height());
    movingTile = new CGraphicGameTile(size,this);//CGraphicBuildingTile(curentHoldingStructure,tileSize,this);
    movingTile->setTransformOriginPoint(QPointF(size.width()/2,size.height()/2));
    movingTile->setMoving(true);
    QBrush brush;
    brush.setColor(Qt::darkBlue);
    brush.setStyle(emptyTileHighlightStyle);
    movingTile->setBrush(brush);
    movingTile->setPixmap(findGraphicForBuilding(curentHoldingStructure));
    scene->addItem(movingTile);
}
void CGraphicMainView::mouseMoveRepaint(QMouseEvent *event)
{
    ///if we are holding structure, change colors of backgroud tiles
    if(structureHolding)
    {   ///[1]
        QPoint cursorPos;
        cursorPos = event->pos();
        QPointF pointF = mapToScene(cursorPos);
        cursorPos.setX(pointF.x());
        cursorPos.setY(pointF.y());

        ///[/1]

        movingTile->setPos(cursorPos+QPoint(30/actualFactor,30/actualFactor));
        //if((abs(beforeCursorPoint.x()-cursorPos.x())*20>tileSize.width()/actualFactor) || (abs(beforeCursorPoint.y()-cursorPos.y())*20>tileSize.height()/actualFactor))
        if(1)
        {  // qDebug()<<"size";
            int _x = curentHoldingStructure->getSizeOnGameMap().getX();
            int _y = curentHoldingStructure->getSizeOnGameMap().getY();
            //qDebug()<<"repaint";
            QSize pos;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());

            QBrush brush;
            brush.setColor(Qt::NoPen);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));
           // scene->update();

            beforeCursorPoint = cursorPos;
            pos.setWidth(beforeCursorPoint.x()/tileSize.width());
            pos.setHeight(beforeCursorPoint.y()/tileSize.height());
            brush.setColor(Qt::darkBlue);
            brush.setStyle(emptyTileHighlightStyle);
            this->repaintAreaUnderBuilding(brush,pos,QSize(_x,_y));
        }

        }
    this->repaint();
}
void CGraphicMainView::emptyTileMouseClicked(CGraphicGameTile* tileClicked, QPointF pos, QGraphicsSceneMouseEvent *event)
{
    Q_UNUSED(pos);
    Q_UNUSED(event);
    if(structureHolding)
    {  // qDebug()<<"clicked";
        //qDebug()<<"second: "<<pos.x()<<" "<<pos.y();
        //CCoordinates _C = CCoordinates(pos.x()/tileSize.width(),pos.y()/tileSize.height());
        CCoordinates _C = CCoordinates(tileClicked->pos().x()/tileSize.width(),tileClicked->pos().y()/tileSize.height());
        //qDebug()<<"tile clicked pos: "<<tileClicked->pos().x()/tileSize.width()<<" "<<tileClicked->pos().y()/tileSize.height();
        curentHoldingStructure->setCoordinatesOfActualLUCorner(_C);
       // qDebug()<<"structure coordinates: "<<curentHoldingStructure->getCoordinatesOfActualLUCorner().getX()<<" "<<curentHoldingStructure->getCoordinatesOfActualLUCorner().getY();
        emit checkIfCanBeBuiled(curentHoldingStructure);
    }
}
void CGraphicMainView::buildStructure(CStructure *newStructure, bool good)
{
   // qDebug()<<"drowing...";
    ///graphical build
    if(curentHoldingStructure!=NULL && good == true)
    {  // qDebug()<<newStructure->getSizeOnGameMap().getX();
        CGraphicBuildingTile *newTile = new CGraphicBuildingTile(newStructure,tileSize,this);
       // qDebug()<<"new structure coordinates: "<<newStructure->getCoordinatesOfActualLUCorner().getX()<<" "<<newStructure->getCoordinatesOfActualLUCorner().getY();

        QBrush brush;
        brush.setColor(Qt::darkBlue);
        brush.setStyle(emptyTileHighlightStyle);
        newTile->setBrush(brush);
        newTile->setPixmap(findGraphicForBuilding(newStructure));
        scene->addItem(newTile);
    }
}
void CGraphicMainView::removeTile(CGraphicBuildingTile* item, CStructure *_structure)
{
    scene->removeItem(item);
    //qDebug()<<"remove tile";
    emit removeStructure(_structure);
}
