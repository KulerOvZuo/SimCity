#include "cstructureforpeople.h"

CStructureForPeople::CStructureForPeople() : CStructure(), isConnectedToRoad(false)
{
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
