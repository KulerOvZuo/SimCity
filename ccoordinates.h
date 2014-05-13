#ifndef CCOORDINATES_H
#define CCOORDINATES_H

class CCoordinates
{
protected:
    int x;
    int y;
public:
    CCoordinates();
    CCoordinates(int _x, int _y);


    ~CCoordinates();
    int getX();
    int getY();
    bool setX(int _x);
    bool setY(int _y);
    bool setCoordinates(int _x, int _y);
};

#endif // CCOORDINATES_H
