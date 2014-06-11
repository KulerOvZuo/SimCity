#ifndef ENUMERATORS_H
#define ENUMERATORS_H

//graphic
#define emptyTileHighlightStyle Qt::Dense3Pattern

#define housePixmapSource "://house.png"
#define blocksPixmapSource "://blocks.png"
#define lawnPixmapSource "://lawn.png"
#define parkPixmapSource "://park.png"
#define officePixmapSource "://office.png"
#define shopPixmapSource "://shop.png"
#define schoolPixmapSource "://School.png"
#define cinemaPixmapSource "://cinema.png"
#define farmPixmapSource "://food.png"
#define lightPixmapSource "://light.png"
#define heavyPixmapSource "://heavy.png"
#define publicPixmapSource "://public.png"
#define straightPixmapSource "://straight.jpg"
#define crossPixmapSource "://cross.jpg"
#define turningPixmapSource "://turning.jpg"
#define noImagePixmapSource "://noimage.jpg"

//map
#define trafficSquare 10
#define roadTrafficCapacity 10

//satisfaction
#define foodInd 1
#define lightInd 1
#define heavyInd 1
#define serviceInd 1
#define recreationInd 1
#define disturbanceInd 1
#define trafficInd 1
#define incomeInd 1

//influance
#define parkInf 1
#define lawnInf 0.1
#define livingInf 0.1
#define lightInf 0.6
#define heavyInf 1.3
#define foodInf 0.8
#define utilityInf 1.3

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
