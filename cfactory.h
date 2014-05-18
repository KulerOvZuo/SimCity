#ifndef CFACTORY_H
#define CFACTORY_H

#include "cproductionbuilding.h"

class CFactory  : public CProductionBuilding
{
protected:
public:
    CFactory();
    CFactory(const CFactory& _F);
};

class CLightFactory  : public CFactory
{
protected:
public:
    CLightFactory();
    CLightFactory(const CLightFactory& _F);
};
class CHeavyFactory  : public CFactory
{
protected:
public:
    CHeavyFactory();
    CHeavyFactory(const CHeavyFactory& _F);
};
#endif // CFACTORY_H
