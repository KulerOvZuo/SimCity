#ifndef CGREENTERRAIN_H
#define CGREENTERRAIN_H

#include "cstructureforpeople.h"

/**
 * @brief Klasa CGreenTerrain (tereny zielone)
 *
 *Klasa będąca nadrzędna dla wszytkich obiektów zielonych w mieście.
 *Obiekty te pozytywnie wpływają na otoczenie i zwiększają ciszę i spokój w obrębie.
 */
class CGreenTerrain : public CStructureForPeople
{
protected:
    ///Współczynnik zmniejszający hałas
    double disturbance;
public:
    CGreenTerrain();
    CGreenTerrain(const CGreenTerrain& _G);
    virtual QList<QString> infoToDisplay();

    bool setDisturbance(double _dist);
    double getDisturbance() const;
};
/**
 * @brief Klasa CPark (park)
 */
class CPark : public CGreenTerrain
{
public:
    CPark();
    CPark(const CPark& _P);
    virtual bool setRandomName(int size);
};
/**
 * @brief Klasa CLawn (trawnik)
 */
class CLawn : public CGreenTerrain
{
public:
    CLawn();
    CLawn(const CLawn& _L);
    virtual bool setRandomName(int size);
};
#endif // CGREENTERRAIN_H
