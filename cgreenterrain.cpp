#include "cgreenterrain.h"

CGreenTerrain::CGreenTerrain() : CStructureForPeople(), disturbance(0)
{
}

bool CGreenTerrain::setDisturbance(double _dist)
{disturbance=_dist;
    return true;
}
double CGreenTerrain::getDisturbance() const
{return disturbance;
}

CPark::CPark() : CGreenTerrain()
{
    disturbance = -10;
}
CLawn::CLawn() : CGreenTerrain()
{
}
