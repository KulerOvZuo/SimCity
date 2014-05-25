#ifndef CCOORDINATES_H
#define CCOORDINATES_H

#include <QDebug>

class CCoordinates
{
protected:
    double x;
    double y;
public:
    CCoordinates();
    CCoordinates(double _x, double _y);
    CCoordinates(const CCoordinates& _C);
    CCoordinates operator+ (CCoordinates _C);
    CCoordinates& operator+= (CCoordinates const &_C);
    CCoordinates& operator=(CCoordinates const &_C);
    virtual ~CCoordinates();

    double getX() const;
    double getY() const;
    bool setX(double _x);
    bool setY(double _y);
    bool setCoordinates(double _x, double _y);
};

#endif // CCOORDINATES_H
