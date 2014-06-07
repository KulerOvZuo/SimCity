#ifndef CTAXES_H
#define CTAXES_H

class CTaxes
{
protected:
    int fromProductionInd;
    int fromPeopleInd;
    int fromOthersInd;
public:
    CTaxes();
    CTaxes(const CTaxes& _T);
    virtual ~CTaxes();

    int getFromProductionInd() const;
    int getFromPeopleInd() const;
    int getFromOthersInd() const;
    void setFromProductionInd(int _num);
    void setFromPeopleInd(int _num);
    void setFromOthersInd(int _num);
};

#endif // CTAXES_H
