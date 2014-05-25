#ifndef CSTRUCTURE_H
#define CSTRUCTURE_H

#include <QString>
#include "ccoordinates.h"
#include "enumerators.h"
#include "cgraphic.h"
#include "cdirections.h"

class CCity;
class CStructure
{
protected:
    int age;
    QString name;
    double buildCost;
    double destroyCost;
    double costPerTick;
    CCoordinates sizeOnGameMap; //is being changed during rotation (x>0; y<0)
    CCoordinates coordinatesOfActualLUCorner; //actual left-up corner
    CDirections turnedDirection; //on creating set to UP; used for properly expose and turning model
    CGraphic* graphic;
    CCity* city;

public:
    CStructure();
    CStructure(int age, QString name, double buildCost,double destroyCost,
               double costPerTick, CCoordinates sizeOnGameMap, CCoordinates coordinatesOfLUCorner,
               CDirections turnedDirection);
    CStructure(const CStructure &_S);
    virtual ~CStructure();

    ///implement
    virtual bool build();
    virtual bool checkIfCanBeBuiled() const;
    double distanceToOther(CStructure* other) const;
    bool destroy();

    virtual bool rotate(Erotation  rotateAngle); //changes turn direction and model turn direction
    CCoordinates countCoordinatesOfCentre() const;

    bool setAge(int _age);
    bool setName(QString _name);
    bool setBuildCost(double _cost);
    bool setDestroyCost(double _cost);
    bool setCostPerTick(double _cost);
    bool setSizeOnGameMap(const CCoordinates& _C);
    bool setCoordinatesOfActualLUCorner(const CCoordinates& _C);
    bool setTurnedDirection(CDirections _dir);
    bool setGraphic(CGraphic* _graphic);
    bool setCity(CCity* _city);

    int getAge() const;
    QString getName() const;
    double getBuildCost() const;
    double getDestroyCost() const;
    double getCostPerTick() const;
    CCoordinates getSizeOnGameMap() const;
    CCoordinates getCoordinatesOfActualLUCorner() const;
    CDirections getTurnedDirection() const;
    CGraphic* getGraphic() const;
    CCity* getCity() const;
};

#endif // CSTRUCTURE_H
