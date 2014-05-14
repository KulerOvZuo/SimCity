#ifndef CCOORDINATES_H
#define CCOORDINATES_H

#include <QDebug>

class CCoordinates
{
protected:
    int x;
    int y;
public:
    CCoordinates();
    CCoordinates(int _x, int _y);
    CCoordinates(const CCoordinates& _C);
    CCoordinates operator+ (CCoordinates _C);
    CCoordinates& operator+= (CCoordinates const &_C);
    CCoordinates& operator=(CCoordinates const &_C);
    virtual ~CCoordinates();

    int getX() const;
    int getY() const;
    bool setX(int _x);
    bool setY(int _y);
    bool setCoordinates(int _x, int _y);
};

#endif // CCOORDINATES_H
