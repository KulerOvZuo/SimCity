#ifndef CDIRECTIONS_H
#define CDIRECTIONS_H

#include "enumerators.h"

class CDirections
{
protected:
    bool dirUp;
    bool dirRight;
    bool dirDown;
    bool dirLeft;

    bool rotateRight();
    bool rotateLeft();
public:
    CDirections();
    CDirections(bool _dirUp, bool _dirRight, bool _dirDown, bool _dirLeft );
    CDirections(const CDirections& _D);
    bool setDirections(bool _dirUp, bool _dirRight, bool _dirDown, bool _dirLeft);
    bool rotate(Erotation  rotateAngle);

    bool getDirUp() const;
    bool getDirRight() const;
    bool getDirDown() const;
    bool getDirLeft() const;
};

#endif // CDIRECTIONS_H
