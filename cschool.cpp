#include "cschool.h"

CSchool::CSchool() : CWorking()
{
    maxNOChildren=0;
    actualNOChildren=0;
    baseEducationIndicator=0;
    actualEducationIndicator=0;
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

double CSchool::countBuildingEfficiency()
{
    if(maxNOChildren<=0)
        return 0;
    double ratio = actualNOChildren/maxNOChildren;
    double multiply;
    if(ratio < 0.8) ///0-0.8 ratio
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
    actualEducationIndicator = baseEducationIndicator*countBuildingEfficiency();
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


///CSchoolALLin1
CSchoolAllInOne::CSchoolAllInOne() : CSchool()
{}
CSchoolAllInOne::CSchoolAllInOne(const CSchoolAllInOne& _S) : CSchool(_S)
{}
CSchoolAllInOne::~CSchoolAllInOne()
{}
