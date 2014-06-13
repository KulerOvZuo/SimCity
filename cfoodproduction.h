#ifndef CFOODPRODUCTION_H
#define CFOODPRODUCTION_H

#include "cproductionbuilding.h"

/**
 * @brief Klasa CFoodProduction (budynek produkujący żywność)
 *
 *Klasa nadrzędna dla wszystkich budynkóW produkujących żywność.
 */
class CFoodProduction : public CProductionBuilding
{
protected:
public:
    CFoodProduction();
    CFoodProduction(const CFoodProduction& _F);
    void sellProducts(CProducts _prod);
    virtual QList<QString> infoToDisplay();
};
/**
 * @brief Klasa CFarm (farma)
 */
class CFarm : public CFoodProduction
{
protected:
public:
    CFarm();
    CFarm(const CFarm& _F);
};

#endif // CFOODPRODUCTION_H
