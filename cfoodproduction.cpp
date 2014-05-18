#include "cfoodproduction.h"

CFoodProduction::CFoodProduction() : CProductionBuilding()
{
}
CFoodProduction::CFoodProduction(const CFoodProduction& _F) : CProductionBuilding(_F)
{}

CFarm::CFarm() : CFoodProduction()
{}
CFarm::CFarm(const CFarm& _F) : CFoodProduction(_F)
{}
