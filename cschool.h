#ifndef CSCHOOL_H
#define CSCHOOL_H

#include "cworking.h"

/**
 * @brief Klasa CSchool (szkoła)
 *
 *Klasa nadrzędna dla wszystkich budynków dających edukację.
 */
class CSchool : public CWorking
{
protected:
    ///Maksymalna ilość dzieci uczących się
    int maxNOChildren;
    ///Aktualna ilość dzieci uczących się
    int actualNOChildren;
    ///Bazowy współczynnik edukacji
    double baseEducationIndicator;
    ///Aktualny współczynnik edukacji
    double actualEducationIndicator;
public:
    CSchool();
    CSchool(const CSchool& _S);
    virtual ~CSchool();
    virtual QList<QString> infoToDisplay();
    virtual bool setRandomName(int size);

    /**
     * @brief Oblicz jakość edukacji
     *
     *Oblicza wartość wpółczynika edukacji w zależności od ilości dzieci w szkole oraz wydajności kadry.
     */
    void countSetEducationQuality();

    double countBuildingEfficiency();
    /**
     * @brief Dodaj dizeci do szkoły.
     *
     *@param _number - liczba dzieci do dodania
     * @return zwraca false jeśli jest próba zejścia poniżej 0 z ilością dzieci w szkole.
     */
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
/**
 * @brief Klasa CSchoolAllInOne (szkoła zintegrowana)
 */
class CSchoolAllInOne : public CSchool
{
protected:
public:
    CSchoolAllInOne();
    CSchoolAllInOne(const CSchoolAllInOne& _S);
    virtual ~CSchoolAllInOne();
};
#endif // CSCHOOL_H
