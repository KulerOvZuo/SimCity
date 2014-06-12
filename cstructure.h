#ifndef CSTRUCTURE_H
#define CSTRUCTURE_H

#include <QString>
#include "ccoordinates.h"
#include "enumerators.h"
#include "idisplayinginterface.h"
#include "cdirections.h"

class CCity;
class CStructure : public IDisplayingInterface
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
    CCity* city;

public:
    CStructure();
    CStructure(int age, QString name, double buildCost,double destroyCost,
               double costPerTick, CCoordinates sizeOnGameMap, CCoordinates coordinatesOfLUCorner,
               CDirections turnedDirection);
    CStructure(const CStructure &_S);
    virtual ~CStructure();

    virtual bool build();
    virtual bool destroy();
    virtual bool checkIfCanBeBuiled() const;
    virtual QList<QString> infoToDisplay();
    double distanceToOther(CStructure* other) const;

    virtual bool rotate(Erotation  rotateAngle); //changes turn direction and model turn direction
    CCoordinates countCoordinatesOfCentre() const;

    void addAge(int _age);
    bool setAge(int _age);
    bool setName(QString _name);
    bool setRandomName(int size);
    bool setBuildCost(double _cost);
    bool setDestroyCost(double _cost);
    bool setCostPerTick(double _cost);
    bool setSizeOnGameMap(const CCoordinates& _C);
    bool setCoordinatesOfActualLUCorner(const CCoordinates& _C);
    bool setTurnedDirection(CDirections _dir);
    bool setCity(CCity* _city);

    int getAge() const;
    QString getName() const;
    double getBuildCost() const;
    double getDestroyCost() const;
    double getCostPerTick() const;
    CCoordinates getSizeOnGameMap() const;
    CCoordinates getCoordinatesOfActualLUCorner() const;
    CDirections getTurnedDirection() const;
    CCity* getCity() const;
};

#endif // CSTRUCTURE_H
