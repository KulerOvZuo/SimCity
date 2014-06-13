#ifndef CROAD_H
#define CROAD_H

#include "croadsandbridges.h"

/**
 * @brief Klasa CRoad (droga)
 *
 *Klasa nadrzędna dla wszystkich dróg lądowych (nie mostów) w mieście.
 */
class CRoad : public CRoadsAndBridges
{
protected:
public:
    CRoad();
    CRoad(const CRoad& _R);
};
/**
 * @brief Klasa CRoadTurning (skręt)
 */
class CRoadTurning : public CRoad
{
protected:
public:
    CRoadTurning();
    CRoadTurning(const CRoadTurning& _R);
};
/**
 * @brief Klasa CRoadStraight (prosta droga)
 */
class CRoadStraight : public CRoad
{
protected:
public:
    CRoadStraight();
    CRoadStraight(const CRoadStraight& _R);
};
/**
 * @brief Klasa CRoadThreeWay (drójrozjazd)
 */
class CRoadThreeWay : public CRoad
{
protected:
public:
    CRoadThreeWay();
    CRoadThreeWay(const CRoadThreeWay& _R);
};
/**
 * @brief Klasa CRoadCross (skrzyżowanie)
 */
class CRoadCross : public CRoad
{
protected:
public:
    CRoadCross();
    CRoadCross(const CRoadCross& _R);
};
#endif // CROAD_H
