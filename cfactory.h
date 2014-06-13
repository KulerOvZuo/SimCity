#ifndef CFACTORY_H
#define CFACTORY_H

#include "cproductionbuilding.h"

/**
 * @brief Klasa CFactory (fabryki)
 *
 *Klasa nadrzędna dla wszystkich budynków produkujących z przemysłu ciężkiego i lekkiego.
 */
class CFactory  : public CProductionBuilding
{
protected:
public:
    CFactory();
    CFactory(const CFactory& _F);
    virtual void sellProducts(CProducts _prod);
};
/**
 * @brief Klasa CLightFactory (fabryka przemysłu lekkiego)
 */
class CLightFactory  : public CFactory
{
protected:
public:
    CLightFactory();
    CLightFactory(const CLightFactory& _F);
    void sellProducts(CProducts _prod);
    virtual QList<QString> infoToDisplay();
};
/**
 * @brief Klasa CHeavyFactory (fabryka przemysłu ciężkiego)
 */
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
