#ifndef CWORKING_H
#define CWORKING_H

#include "cbuilding.h"
#include "cpeople.h"

class CWorking : public CBuilding
{
protected:
    CPeople neededNumberOfWorkers;
    CPeople actualNumberOfWorkers;
public:
    CWorking();
    CWorking(const CWorking& _W);
    CWorking(const CWorking& _W, CPeople _need, CPeople _actual);

    bool addWorkers(CPeople _P); //if number of people to add is too high
    double countEfficiency(); ///linear efficiency

    CPeople getNeededNumberOfWorkers() const;
    CPeople getActualNumberOfWorkers() const;
    void setActualNumberOfWorkers(CPeople _P);
    void setNeededNumberOfWorkers(CPeople _P);
};

#endif // CWORKING_H
