#include "cstructureforpeople.h"

CStructureForPeople::CStructureForPeople() : CStructure(), isConnectedToRoad(false)
{
    isConnectedToRoad = true;
}
CStructureForPeople::CStructureForPeople(const CStructureForPeople& _S) : CStructure(_S)
{
    isConnectedToRoad=_S.getIsConnectedToRoad();
}
CStructureForPeople::~CStructureForPeople()
{}
bool CStructureForPeople::checkIfConnectedToRoad()
{ return true;}

bool CStructureForPeople::getIsConnectedToRoad() const
{return isConnectedToRoad;}
bool CStructureForPeople::setIsConnectedToRoad(bool _connected)
{
    isConnectedToRoad=_connected;
    return true;
}
