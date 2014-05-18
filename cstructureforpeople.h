#ifndef CSTRUCTUREFORPEOPLE_H
#define CSTRUCTUREFORPEOPLE_H

#include "cstructure.h"

class CStructureForPeople : public CStructure
{
protected:
    bool isConnectedToRoad;
public:
    CStructureForPeople();
    CStructureForPeople(const CStructureForPeople& _S);

    ///implement
    bool checkIfConnectedToRoad();

    bool getIsConnectedToRoad() const;
    bool setIsConnectedToRoad(bool _connected);
};

#endif // CSTRUCTUREFORPEOPLE_H
