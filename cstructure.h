#ifndef CSTRUCTURE_H
#define CSTRUCTURE_H

#include <QString>
#include "ccoordinates.h"
#include "enumerators.h"
#include "ccity.h"
#include "cgraphic.h"
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
    direction turnedDirection;

    //CGraphic graphic;
    CCity *city;

public:
    CStructure();
    ~CStructure();


};

#endif // CSTRUCTURE_H
