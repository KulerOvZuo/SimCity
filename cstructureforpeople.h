#ifndef CSTRUCTUREFORPEOPLE_H
#define CSTRUCTUREFORPEOPLE_H

#include "cstructure.h"
/**
 * @brief Klasa CStructureForPeople (struktury dla ludzi)
 *
 *Klasa będąca nadrzędną dla wszystkich struktur będących w silnej interakcji z ludźmi.
 *Udostępnia czy budynek jest podłączony do drogi.
 */
class CStructureForPeople : public CStructure
{
protected:
    ///Czy jest podłaczony do drogi
    bool isConnectedToRoad;
public:
    CStructureForPeople();
    CStructureForPeople(const CStructureForPeople& _S);
    virtual ~CStructureForPeople();

    ///Sprawdź czy podłaczony do drogi
    bool checkIfConnectedToRoad();

    bool getIsConnectedToRoad() const;
    bool setIsConnectedToRoad(bool _connected);
};

#endif // CSTRUCTUREFORPEOPLE_H
