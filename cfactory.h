#ifndef CFACTORY_H
#define CFACTORY_H

#include "cproductionbuilding.h"

class CFactory  : public CProductionBuilding
{
protected:
public:
    CFactory();
    CFactory(const CFactory& _F);
    virtual void sellProducts(CProducts _prod);
};

class CLightFactory  : public CFactory
{
protected:
public:
    CLightFactory();
    CLightFactory(const CLightFactory& _F);
    void sellProducts(CProducts _prod);
    virtual QList<QString> infoToDisplay();
};
class CHeavyFactory  : public CFactory
{
protected:
public:
    CHeavyFactory();
    CHeavyFactory(const CHeavyFactory& _F);
    void sellProducts(CProducts _prod);
    virtual QList<QString> infoToDisplay();
};
#endif // CFACTORY_H
