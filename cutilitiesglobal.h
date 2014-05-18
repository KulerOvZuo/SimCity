#ifndef CUTILITIESGLOBAL_H
#define CUTILITIESGLOBAL_H

class CUtilitiesGlobal
{
protected:
    double electricity;
    double water;
    double dump;
public:
    CUtilitiesGlobal();
    CUtilitiesGlobal(const CUtilitiesGlobal& _U);
    CUtilitiesGlobal(double _electricity,double _water,double _dump);
    CUtilitiesGlobal operator+ (CUtilitiesGlobal _U);
    CUtilitiesGlobal& operator+= (CUtilitiesGlobal const &_U);
    CUtilitiesGlobal& operator-= (CUtilitiesGlobal const &_U);

    bool setElectricity(double _electr);
    bool setWater(double _water);
    bool setDump(double _dump);

    double getElectricity() const;
    double getWater() const;
    double getDump() const;
};

#endif // CUTILITIESGLOBAL_H
