#include "cgreenterrain.h"

CGreenTerrain::CGreenTerrain() : CStructureForPeople(), disturbance(0)
{
}
CGreenTerrain::CGreenTerrain(const CGreenTerrain& _G) : CStructureForPeople(_G)
{
    disturbance = _G.getDisturbance();
}
bool CGreenTerrain::setDisturbance(double _dist)
{disturbance=_dist;
    return true;
}
QList<QString> CGreenTerrain::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CStructure::infoToDisplay());
    info.append(QString("Keep cost: %1$").arg(costPerTick,1));
    info.append(QString("Peace: +%1").arg(disturbance,1));
    return info;
}

double CGreenTerrain::getDisturbance() const
{
    return disturbance;
}

CPark::CPark() : CGreenTerrain()
{
    disturbance = parkInf;
    sizeOnGameMap = CCoordinates(4,2);
    setRandomName(1);
}
CPark::CPark(const CPark& _P) : CGreenTerrain(_P)
{   sizeOnGameMap = _P.getSizeOnGameMap();}
bool CPark::setRandomName(int size)
{   Q_UNUSED(size);
    CStructure::setRandomName(1);
    name.append(QString(" Park"));
return true;}

CLawn::CLawn() : CGreenTerrain()
{
    disturbance = lawnInf;
    sizeOnGameMap = CCoordinates(1,1);
    name = QString("Lawn");
}
CLawn::CLawn(const CLawn& _L) : CGreenTerrain(_L)
{   sizeOnGameMap = _L.getSizeOnGameMap();}
bool CLawn::setRandomName(int size)
{   Q_UNUSED(size);
    name= QString("Lawn");
return true;}
