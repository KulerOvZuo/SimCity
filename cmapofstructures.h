#ifndef CMAPOFSTRUCTURES_H
#define CMAPOFSTRUCTURES_H

#include "cstructure.h"
#include "croadsandbridges.h"
#include "croad.h"
#include "cutilitiesglobal.h"
#include "cgreenterrain.h"
#include "cbuilding.h"
#include "cpeople.h"
#include "cpeopleneeds.h"
#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "cliving.h"
#include "cworking.h"
#include "cproductionbuilding.h"
#include "cpublicutilitybuilding.h"
#include "cservicebuilding.h"
#include "crecreationbuilding.h"

class CMapOfStructures
{
protected:
    CCoordinates mapSize;
    bool** mapOfTakenPlaces;
public:
    CMapOfStructures();
};

#endif // CMAPOFSTRUCTURES_H
