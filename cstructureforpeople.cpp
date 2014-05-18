#include "cstructureforpeople.h"

CStructureForPeople::CStructureForPeople() : CStructure(), isConnectedToRoad(false)
{
}
CStructureForPeople::CStructureForPeople(const CStructureForPeople& _S) : CStructure(_S)
{
    isConnectedToRoad=_S.getIsConnectedToRoad();
}

bool CStructureForPeople::checkIfConnectedToRoad()
{ return true;}

bool CStructureForPeople::getIsConnectedToRoad() const
{return isConnectedToRoad;}
bool CStructureForPeople::setIsConnectedToRoad(bool _connected)
{
    isConnectedToRoad=_connected;
    return true;
}
