#ifndef CTAXES_H
#define CTAXES_H

class CTaxes
{
protected:
    ///Wartość podatków od produkcji.
    int fromProductionInd;
    ///Wartość podatków od ludzi.
    int fromPeopleInd;
    ///Wartość podatków od innych.
    int fromOthersInd;
public:
    CTaxes();
    ///Konstruktor kopiujący.
    CTaxes(const CTaxes& _T);
    virtual ~CTaxes();

    ///Pobierz wartość podatków od produkcji.
    int getFromProductionInd() const;
    ///Pobierz wartość podatków od ludzi.
    int getFromPeopleInd() const;
    ///Pobierz wartość podatków od innych.
    int getFromOthersInd() const;\
    ///Ustaw wartość podatków od produkcji
    void setFromProductionInd(int _num);
    ///Ustaw wartość podatków od ludzi
    void setFromPeopleInd(int _num);
    ///Ustaw wartość podatków od innych
    void setFromOthersInd(int _num);
};

#endif // CTAXES_H
