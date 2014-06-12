#include "cschool.h"

CSchool::CSchool() : CWorking()
{
    maxNOChildren=0;
    actualNOChildren=0;
    baseEducationIndicator=0;
    actualEducationIndicator=0;
    setRandomName(3);
}
CSchool::CSchool(const CSchool& _S) : CWorking(_S)
{
    maxNOChildren=_S.getMaxNOChildren();
    actualNOChildren=_S.getActualNOChildren();
    baseEducationIndicator=_S.getBaseEducationIndicator();
    actualEducationIndicator=_S.getActualEducationIndicator();
}
CSchool::~CSchool()
{}
QList<QString> CSchool::infoToDisplay()
{   QList<QString> info;
    info.clear();
    info.append(CWorking::infoToDisplay());
    info.append(QString("Base education indicator: %1\nActual education indicator: %2").
                arg(baseEducationIndicator,1).
                arg(actualEducationIndicator,1,'f',2));
    info.append(QString("Maximum number of children: %1\nActual number of children: %2").
                arg(maxNOChildren,1).
                arg(actualNOChildren,1));
    return info;

}
bool CSchool::setRandomName(int size)
{  Q_UNUSED(size);
    CStructure::setRandomName(3);
    name.append(QString(" School"));
return true;}

double CSchool::countBuildingEfficiency()
{
    if(maxNOChildren<=0)
        return 0;
    double ratio = actualNOChildren/maxNOChildren;
    double multiply;
    if(ratio < 0.8) //0-0.8 ratio
    {   multiply=1;}
    else
    {   if(ratio < 1.5)
            multiply = 1-(ratio-0.8);
        else
            multiply = 0.3;}

    return multiply*countPeopleEfficiency();
}
void CSchool::countSetEducationQuality()
{
    actualEducationIndicator = (baseEducationIndicator*countBuildingEfficiency()+actualEducationIndicator)/2;
}
bool CSchool::addNOChildren(int _number)
{   actualNOChildren += _number;
    if(actualNOChildren<0)
    {   actualNOChildren=0;
        return false;}
    return true;
}

int CSchool::getMaxNOChildren() const
{   return maxNOChildren; }
int CSchool::getActualNOChildren() const
{   return actualNOChildren;}
double CSchool::getBaseEducationIndicator() const
{   return baseEducationIndicator;}
double CSchool::getActualEducationIndicator() const
{   return actualEducationIndicator;}

void CSchool::setMaxNOChildren(int _max)
{   maxNOChildren = _max;}
void CSchool::setActualNOChildren(int _actual)
{   actualNOChildren =_actual;}
void CSchool::setBaseEducationIndicator(double _base)
{   baseEducationIndicator = _base;}
void CSchool::setActualEducationIndicator(double _actual)
{   actualEducationIndicator = _actual;}


//CSchoolALLin1
CSchoolAllInOne::CSchoolAllInOne() : CSchool()
{   sizeOnGameMap = CCoordinates(4,3);}
CSchoolAllInOne::CSchoolAllInOne(const CSchoolAllInOne& _S) : CSchool(_S)
{   sizeOnGameMap = _S.getSizeOnGameMap();}
CSchoolAllInOne::~CSchoolAllInOne()
{}
