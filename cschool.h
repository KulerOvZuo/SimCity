#ifndef CSCHOOL_H
#define CSCHOOL_H

#include "cworking.h"

class CSchool : public CWorking
{
protected:
    int maxNOChildren;
    int actualNOChildren;
    double baseEducationIndicator;
    double actualEducationIndicator;
public:
    CSchool();
    CSchool(const CSchool& _S);
    virtual ~CSchool();
    virtual QList<QString> infoToDisplay();

    void countSetEducationQuality();

    double countBuildingEfficiency();    
    bool addNOChildren(int _number);

    int getMaxNOChildren() const;
    int getActualNOChildren() const;
    double getBaseEducationIndicator() const;
    double getActualEducationIndicator() const;

    void setMaxNOChildren(int _max);
    void setActualNOChildren(int _actual);
    void setBaseEducationIndicator(double _base);
    void setActualEducationIndicator(double _actual);
};

class CSchoolAllInOne : public CSchool
{
protected:
public:
    CSchoolAllInOne();
    CSchoolAllInOne(const CSchoolAllInOne& _S);
    virtual ~CSchoolAllInOne();
};
#endif // CSCHOOL_H
