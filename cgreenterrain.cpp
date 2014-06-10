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
double CGreenTerrain::getDisturbance() const
{
    return disturbance;
}

CPark::CPark() : CGreenTerrain()
{
    disturbance = parkInf;
    sizeOnGameMap = CCoordinates(4,3);
}
CPark::CPark(const CPark& _P) : CGreenTerrain(_P)
{   sizeOnGameMap = _P.getSizeOnGameMap();}
CLawn::CLawn() : CGreenTerrain()
{
    disturbance = lawnInf;
    sizeOnGameMap = CCoordinates(1,1);
}
CLawn::CLawn(const CLawn& _L) : CGreenTerrain(_L)
{   sizeOnGameMap = _L.getSizeOnGameMap();}
