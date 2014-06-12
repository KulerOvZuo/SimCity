#include "ccoordinates.h"

CCoordinates::CCoordinates()
{
    x=0;
    y=0;
}
CCoordinates::CCoordinates(double _x, double _y)
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
double CCoordinates::getX() const
{return x;
}
double CCoordinates::getY() const
{return y;
}
void CCoordinates::setX(double _x)
{x=_x;
}
void CCoordinates::setY(double _y)
{y=_y;
}
void CCoordinates::setCoordinates(double _x, double _y)
{x=_x; y=_y;
}
