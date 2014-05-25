#ifndef CROADSANDBRIDGES_H
#define CROADSANDBRIDGES_H

#include "cstructure.h"
#include "cdirections.h"

class CRoadsAndBridges : public CStructure
{
protected:
    double capacity;
    bool onWater;
    CDirections directions;
public:
    CRoadsAndBridges();
    CRoadsAndBridges(double _capacity,bool _water,CDirections _dir);
    CRoadsAndBridges(const CRoadsAndBridges& _R);

    bool rotate(Erotation rotateAngle);
    ///implement
    bool checkIfCanBeBuiled();

    void setAllRoadAndBridges(double _capacity,bool _water,CDirections _dir);
    bool setOnWater(bool _water);
    bool setCapacity(double _capacity);
    bool setDirections(CDirections _dir);

    double getCapacity() const;
    bool getOnWater() const;
    CDirections getDirections() const;
};

#endif // CROADSANDBRIDGES_H
