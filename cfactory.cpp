#include "cfactory.h"

CFactory::CFactory()
{
}
CFactory::CFactory(const CFactory& _F) : CProductionBuilding(_F)
{}

CLightFactory::CLightFactory()
{}
CLightFactory::CLightFactory(const CLightFactory& _F) : CFactory(_F)
{}

CHeavyFactory::CHeavyFactory()
{}
CHeavyFactory::CHeavyFactory(const CHeavyFactory& _F) : CFactory(_F)
{}
