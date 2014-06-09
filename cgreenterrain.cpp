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
}
CPark::CPark(const CPark& _P) : CGreenTerrain(_P)
{}
CLawn::CLawn() : CGreenTerrain()
{
    disturbance = lawnInf;
}
CLawn::CLawn(const CLawn& _L) : CGreenTerrain(_L)
{}
