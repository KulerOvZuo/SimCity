#include "cdirections.h"

CDirections::CDirections() : dirUp(true),dirRight(false), dirDown(false), dirLeft(false)
{
}
CDirections::CDirections(bool _dirUp, bool _dirRight, bool _dirDown, bool _dirLeft ) : dirUp(_dirUp),dirRight(_dirRight), dirDown(_dirDown), dirLeft(_dirLeft)
{
}

CDirections::CDirections(const CDirections& _D)
{
    dirUp=_D.getDirUp();
    dirDown=_D.getDirDown();
    dirRight=_D.getDirRight();;
    dirLeft=_D.getDirLeft();
}
bool CDirections::setDirections(bool _dirUp, bool _dirRight, bool _dirDown, bool _dirLeft)
{
    dirUp=_dirUp;
    dirDown=_dirDown;
    dirRight=_dirRight;
    dirLeft=_dirLeft;
    return true;
}
bool CDirections::rotateRight()
{   //rotate right - rewrite from left to right
    bool temp = dirUp;
    dirUp=dirLeft;
    dirLeft=dirDown;
    dirDown=dirRight;
    dirRight=temp;
    return true;
}
bool CDirections::rotateLeft()
{   //rotate right - rewrite from right to left
    bool temp = dirUp;
    dirUp=dirRight;
    dirRight=dirDown;
    dirDown=dirLeft;
    dirLeft=temp;
    return true;
}
bool CDirections::rotate(Erotation  rotateAngle)
{
    if(rotateAngle == rightRot)
        this->rotateRight();
    else
    {   if(rotateAngle == leftRot)
            this->rotateLeft();
        else
        {   if(rotateAngle == halfRoundRot)
            {   this->rotateRight();
                this->rotateRight();
            }
            else
                return false;
        }
    }
    return true;
}
bool CDirections::getDirUp() const
{ return dirUp;}
bool CDirections::getDirRight() const
{ return dirRight;}
bool CDirections::getDirDown() const
{ return dirDown;}
bool CDirections::getDirLeft() const
{ return dirLeft;}
