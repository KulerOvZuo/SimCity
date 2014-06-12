#ifndef CPEOPLENEEDS_H
#define CPEOPLENEEDS_H

#include <cmath>
#include "enumerators.h"

/**
 * @brief Klasa CProducts (produkty)
 *
 *Klasa jest kontenerem informacji o produktach.
 *Pozwala na proste operacje matematyczne.
 */
class CProducts
{
protected:
    ///Ilość produktów przemysłu Light
    double lightIndustry;
    ///Ilość produktów przemysłu Heavy
    double heavyIndustry;
    ///Ilość produktów przemysłu Food
    double food;
public:
    CProducts();
    CProducts(double _light, double _heavy, double _food);
    CProducts(const CProducts& _C);
    CProducts operator+ (CProducts _C);
    CProducts operator- (CProducts _C);
    CProducts& operator+= (CProducts const &_C);
    CProducts& operator=(CProducts const &_C);

    /**
     * @brief Napraw jeśli nie dodatnie.
     *
     *Jeśli wartości produktów są mniejsze od 0, powoduje ustawienie danego na 0.
     * @return Zwraca false jeśli potrzebna była naprawa.
     */
    bool restoreIfNotPossitiveNONeeds();

    double getLight() const;
    double getHeavy() const;
    double getFood() const;
    void setAll(double _light, double _heavy, double _food);
    void setLight(double _light);
    void setHeavy(double _heavy);
    void setFood(double _food);
};
/**
 * @brief Klasa CService (usługi)
 *
 *Klasa jest kontenerem informacji o usługach.
 *Pozwala na proste operacje matematyczne.
 */
class CService
{
protected:
    ///ilość usług
    double service1;
public:
    CService();
    CService(double _serv1);
    CService(const CService& _C);
    CService operator+ (CService _C);
    CService& operator+= (CService const &_C);
    CService& operator=(CService const &_C);

    bool restoreIfNotPossitiveNONeeds();

    double getService1() const;
    void setService1(double _serv);
};

/**
 * @brief Klasa CProducts (produkty)
 *
 *Klasa jest kontenerem informacji o produktach.
 *Pozwala na proste operacje matematyczne.
 */
class CRecreation
{
protected:
    double recreation1;
public:
    CRecreation();
    CRecreation(double _recr1);
    CRecreation(const CRecreation& _C);
    CRecreation operator+ (CRecreation _C);
    CRecreation& operator+= (CRecreation const &_C);
    CRecreation& operator=(CRecreation const &_C);

    bool restoreIfNotPossitiveNONeeds();

    double getRecreation1() const;
    void setRecreation1(double _rec);
};

/**
 * @brief Klasa CProducts (produkty)
 *
 *Klasa jest kontenerem informacji o produktach.
 *Pozwala na proste operacje matematyczne.
 */
class CPeopleNeeds
{
protected:
    CProducts productsNeed;
    CService serviceNeed;
    CRecreation recreationNeed;
    double disturbanceNeed;
    double traffic;
public:
    CPeopleNeeds();
    CPeopleNeeds(CProducts _prod, CService _serv, CRecreation _rec,
                 double _disturb, double _traffic);
    CPeopleNeeds(const CPeopleNeeds& _C);
    CPeopleNeeds operator+ (CPeopleNeeds _C);
    CPeopleNeeds& operator+= (CPeopleNeeds const &_C);
    CPeopleNeeds& operator=(CPeopleNeeds const &_C);
    CPeopleNeeds& operator+= (CProducts const &_C);
    CPeopleNeeds& operator+= (CService const &_C);
    CPeopleNeeds& operator+= (CRecreation const &_C);

    CPeopleNeeds countNewNeeds(double _lifeSatisfaction);
    CPeopleNeeds countSetNewNeeds(double _lifeSatisfaction);
    double countLifeSatisfation(double _income);
    double countLifeSatisfation(double _income, double _lifeSatPast);

    void setAll(CProducts _prod,CService _serv,CRecreation _rec,double _traf,double _dist);
    void setProductsNeed(CProducts _prod);
    void setServiceNeed(CService _serv);
    void setRecreationNeed(CRecreation _rec);
    void setTraffic(double _traf);
    void setDistrurbance(double _dist);
    void addTraffic(double _traf);
    void addDisturbance(double _dist);

    CProducts getProductsNeed() const;
    CService getServiceNeed() const;
    CRecreation getRecreationNeed() const;
    double getDisturbance() const;
    double getTraffic() const;

};

#endif // CPEOPLENEEDS_H
