#ifndef ENUMERATORS_H
#define ENUMERATORS_H


//satisfaction
#define foodInd 1
#define lightInd 1
#define heavyInd 1
#define serviceInd 1
#define recreationInd 1
#define disturbanceInd 1
#define trafficInd 1
#define incomeInd 1

//education
#define minLeadEdu 50
#define minServiceEdu 30
#define minLightEdu 25
#define minHeavyEdu 20
#define minLowEdu 15

//working efficiency
#define leadWorkerEff 1.2
#define serviceWorkerEff 1.1
#define lightWorkerEff 1
#define heavyWorkerEff 1
#define lowWorkerEff 1

//earnings
#define leadWorkerEarning 2000
#define serviceWorkerEarning 1700
#define lightWorkerEarning 1500
#define heavyWorkerEarning  1300
#define lowWorkerEarning 1000

//base products cost
#define foodCost 1
#define lightCost 2
#define heavyCost 2
#define serviceCost 2


enum Edirection {directionUp = 1, directionRight = 2, directionDown = 4, directionLeft = 8};
enum Erotation {noRot = 0, rightRot = 90, halfRoundRot = 180, leftRot = 270};
#endif // ENUMERATORS_H
