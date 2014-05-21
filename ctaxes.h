#ifndef CTAXES_H
#define CTAXES_H

class CTaxes
{
protected:
    double fromProductionInd;
    double fromPeopleInd;
    double fromOthersInd;
public:
    CTaxes();
    CTaxes(const CTaxes& _T);
    virtual ~CTaxes();

    double getFromProductionInd() const;
    double getFromPeopleInd() const;
    double getFromOthersInd() const;
    void setFromProductionInd(double _num);
    void setFromPeopleInd(double _num);
    void setFromOthersInd(double _num);
};

#endif // CTAXES_H
