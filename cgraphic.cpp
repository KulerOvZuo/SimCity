#include "cgraphic.h"

CGraphic::CGraphic() : image(), size()
{
}
CGraphic::CGraphic(CCoordinates _size) : size(_size)
{
}
CGraphic::CGraphic(QPixmap _image, CCoordinates _size) : image(_image), size(_size)
{
}
CGraphic::CGraphic(const CGraphic& _G)
{
    size = _G.getSize();
    image = _G.getImage();
}
CGraphic::~CGraphic()
{}

CCoordinates CGraphic::getSize() const
{return size;
}
QPixmap CGraphic::getImage() const
{return image;
}
bool CGraphic::setSize(CCoordinates _C)
{   size = _C;
    return true;
}
bool CGraphic::setImage(QPixmap _image)
{   image = _image;
    return true;
}
