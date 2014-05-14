#ifndef CROADSANDBRIDGES_H
#define CROADSANDBRIDGES_H

#include "cstructure.h"

class CRoadsAndBridges : public CStructure
{
protected:
    double capacity;
    bool onWater;
    CDirections directions; //from enum Edirections {directionUp = 1, directionRight = 2,
                    //directionDown = 4, directionLeft = 8}; it's simple sum of directions
public:
    CRoadsAndBridges();
    bool rotate(Erotation rotateAngle);
    ///implement
    bool checkIfCanBeBuiled();

    bool setOnWater(bool _water);
    bool setCapacity(double _capacity);
    bool setDirections(CDirections _dir);

    double getCapacity() const;
    bool getOnWater() const;
    CDirections getDirections() const;


};

#endif // CROADSANDBRIDGES_H
