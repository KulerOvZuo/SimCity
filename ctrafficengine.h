#ifndef CTRAFFICENGINE_H
#define CTRAFFICENGINE_H

#include "ccoordinates.h"

class CCity;
class CTrafficEngine
{
protected:
    double** simplifiedMapOfTraffic;
    CCoordinates sizeofSimplifiedMap;
    CCity *city;
public:
    CTrafficEngine();
    CTrafficEngine(const CTrafficEngine& _T);
    virtual ~CTrafficEngine();

    void setCity(CCity* _city);
    bool createMapOfTraffic();

    double giveTrafficInfo(CCoordinates _C) const;
    void countTraffic();
    void clearTemporary();
};

#endif // CTRAFFICENGINE_H
