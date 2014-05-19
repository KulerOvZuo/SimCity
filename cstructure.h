#ifndef CSTRUCTURE_H
#define CSTRUCTURE_H

#include <QString>
#include "ccoordinates.h"
#include "enumerators.h"
#include "ccity.h"
#include "cgraphic.h"
#include "cdirections.h"
#include <QDebug>

class CStructure
{
protected:
    int age;
    QString name;
    double buildCost;
    double destroyCost;
    double costPerTick;
    CCoordinates sizeOnGameMap;
    CCoordinates coordinatesOfCentre;
    CDirections turnedDirection;

    CGraphic graphic;
    CCity *city;

public:
    CStructure();
    CStructure(int age, QString name, double buildCost,double destroyCost,
               double costPerTick, CCoordinates sizeOnGameMap, CCoordinates coordinatesOfCentre,
               CDirections turnedDirection);
    CStructure(const CStructure &_S);
    virtual ~CStructure();

    ///implement
    virtual bool build();
    virtual bool checkIfCanBeBuiled();
    bool destroy();

    bool rotate(Erotation  rotateAngle);

    bool setAge(int _age);
    bool setName(QString _name);
    bool setBuildCost(double _cost);
    bool setDestroyCost(double _cost);
    bool setCostPerTick(double _cost);
    bool setSizeOnGameMap(const CCoordinates& _C);
    bool setCoordinatesOfCentre(const CCoordinates& _C);
    bool setTurnedDirection(CDirections _dir);
    bool setGraphic(CGraphic _graphic);
    bool setCity(CCity* _city);

    int getAge() const;
    QString getName() const;
    double getBuildCost() const;
    double getDestroyCost() const;
    double getCostPerTick() const;
    CCoordinates getSizeOnGameMap() const;
    CCoordinates getCoordinatesOfCentre() const;
    CDirections getTurnedDirection() const;
    CGraphic getGraphic() const;
    CCity* getCity() const;
};

#endif // CSTRUCTURE_H
