#include "ccoordinates.h"

CCoordinates::CCoordinates()
{
    x=0;
    y=0;
}
CCoordinates::CCoordinates(int _x, int _y)
{   x=_x;
    y=_y;}
CCoordinates::~CCoordinates()
{}
int CCoordinates::getX()
{return x;}
int CCoordinates::getY()
{return y;}
bool CCoordinates::setX(int _x)
{x=_x; return true;}
bool CCoordinates::setY(int _y)
{y=_y; return true;}
bool CCoordinates::setCoordinates(int _x, int _y)
{x=_x; y=_y;return true;}
