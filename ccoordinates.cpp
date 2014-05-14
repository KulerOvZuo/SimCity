#include "ccoordinates.h"

CCoordinates::CCoordinates()
{
    x=0;
    y=0;
}
CCoordinates::CCoordinates(int _x, int _y)
{   x=_x;
    y=_y;
}
CCoordinates::CCoordinates(const CCoordinates &_C)
{
   x=_C.getX();
   y=_C.getY();
}

CCoordinates CCoordinates::operator+ (CCoordinates _C)
{
    return CCoordinates(x+_C.getX(),y+_C.getY());
}
CCoordinates& CCoordinates::operator+= (CCoordinates const & _C)
{
    this->x += _C.getX();
    this->y += _C.getY();
    return *this;
}
CCoordinates& CCoordinates::operator=(CCoordinates const &_C)
{
    if(this != &_C)
        {   x=_C.getX();
            y=_C.getY();
        }
    return *this;
}
CCoordinates::~CCoordinates()
{}
int CCoordinates::getX() const
{return x;
}
int CCoordinates::getY() const
{return y;
}
bool CCoordinates::setX(int _x)
{x=_x; return true;
}
bool CCoordinates::setY(int _y)
{y=_y; return true;
}
bool CCoordinates::setCoordinates(int _x, int _y)
{x=_x; y=_y;return true;
}
