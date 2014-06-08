#ifndef CGRAPHIC_H
#define CGRAPHIC_H

#include <QPixmap>
#include "ccoordinates.h"

//Class that stores some part of information about image
class CStructure;
class CGraphic
{

protected:
    QPixmap image;
    CCoordinates size;
    CStructure* structure;

    QPoint position;
    QColor color;
    QPainterPath path;
    QString toolTip;

public:
    CGraphic();
    CGraphic(CCoordinates _size);
    CGraphic(QPixmap _image, CCoordinates _size);
    CGraphic(const CGraphic& _G);
    virtual ~CGraphic();

    CCoordinates getSize() const;
    QPixmap getImage() const;
    bool setSize(CCoordinates _C);
    bool setImage(QPixmap _image);
};

#endif // CGRAPHIC_H
