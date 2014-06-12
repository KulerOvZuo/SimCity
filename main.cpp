#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "cstructure.h"
#include "croadsandbridges.h"
#include "croad.h"
#include "cutilitiesglobal.h"
#include "cgreenterrain.h"
#include "cbuilding.h"
#include "cpeople.h"
#include "cpeopleneeds.h"
#include "clearningpeople.h"
#include "cpeopleearnings.h"
#include "cliving.h"
#include "cworking.h"
#include "cproductionbuilding.h"
#include "cpublicutilitybuilding.h"
#include "cservicebuilding.h"
#include "crecreationbuilding.h"
#include "csocietyindicators.h"
#include "ccity.h"
#include "enumerators.h"
#include "cstartingwindow.h"

int MainWindow::turnNumber = 1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());
    CStartingWindow startingWindow;
    startingWindow.show();

    /*
    CCity* city = new CCity;
    CCoordinates C;
    bool f;

    city->getMapOfStructures()->setMapSize(CCoordinates(23,13));
    city->getMapOfStructures()->setMakeMapOfTakenPlaces();
    qDebug()<<(city->getMapOfStructures()->getMapOfTakenPlaces())[2][3];*/


    /*
    CHouse* House = new CHouse();
    CShop* shop = new CShop();
    f=city->getMapOfStructures()->addStructureProperly(House);
    f=city->getMapOfStructures()->addStructureProperly(shop);
    (city->getMapOfStructures()->getAllLivings()).at(0)->setCity(city);
    (city->getMapOfStructures()->getAllLivings()).at(0)->setCoordinatesOfActualLUCorner(CCoordinates(1,4));
    (city->getMapOfStructures()->getAllLivings()).at(0)->setSizeOnGameMap(CCoordinates(5,-2));
    C=(city->getMapOfStructures()->getAllLivings()).at(0)->countCoordinatesOfCentre();
    shop->setCoordinatesOfActualLUCorner(CCoordinates(1,1));
    shop->setSizeOnGameMap(CCoordinates(3,-1));
    C=(city->getMapOfStructures()->getAllShops()).at(0)->countCoordinatesOfCentre();
    (city->getMapOfStructures()->getAllShops()).at(0)->setCity(city);

    f=(city->getMapOfStructures()->getAllShops()).at(0)->checkIfCanBeBuiled();
    if((city->getMapOfStructures()->getAllLivings()).at(0)->checkIfCanBeBuiled())
        (city->getMapOfStructures()->getAllLivings()).at(0)->build();
    f=(city->getMapOfStructures()->getAllShops()).at(0)->checkIfCanBeBuiled();
    shop->setCoordinatesOfActualLUCorner(CCoordinates(10,0));
    f=(city->getMapOfStructures()->getAllShops()).at(0)->checkIfCanBeBuiled();
    shop->rotate(leftRot);
    f=(city->getMapOfStructures()->getAllShops()).at(0)->checkIfCanBeBuiled();

    CRoadCross* cross = new CRoadCross;
    CRoadStraight* straight = new CRoadStraight;
    cross->setSizeOnGameMap(CCoordinates(1,1));
    cross->setCapacity(10);
    straight->setSizeOnGameMap(CCoordinates(1,1));
    straight->setCapacity(10);
    cross->setCity(city);
    straight->setCity(city);
    city->getMapOfStructures()->addStructureProperly(cross);
    city->getMapOfStructures()->addStructureProperly(straight);
    cross->setCoordinatesOfActualLUCorner(CCoordinates(2,8));
    if(cross->checkIfCanBeBuiled())
        cross->build();
    straight->setCoordinatesOfActualLUCorner(CCoordinates(3,8));
    if(straight->checkIfCanBeBuiled())
        straight->build();
    straight->rotate(rightRot);
    straight->setCoordinatesOfActualLUCorner(CCoordinates(2,13));
    if(straight->checkIfCanBeBuiled())
        straight->build();
    straight->setCoordinatesOfActualLUCorner(CCoordinates(3,13));
    if(straight->checkIfCanBeBuiled())
        straight->build();

    shop->setNeededNumberOfWorkers(CPeople(0,1,1,5,5));
    House->addNewLearningPeople(CPeople(1,2,0,5,2));
    CSchool* school1 = new CSchool;
    school1->setCity(city);
    school1->setBaseEducationIndicator(10);
    city->getMapOfStructures()->addStructureProperly(school1);
    school1->setSizeOnGameMap(CCoordinates(2,2));
    school1->setCoordinatesOfActualLUCorner(CCoordinates(10,11));
    school1->setNeededNumberOfWorkers(CPeople(5,0,0,0,1));
    school1->addWorkers(CPeople(4,0,0,0,1));
    school1->setMaxNOChildren(11);
    school1->setActualNOChildren(6);
    school1->setNeededNumberOfWorkers(CPeople(4,3,0,1,2));
    CSchool* school2 = new CSchool(*school1);
    city->getMapOfStructures()->addStructureProperly(school2);
    school2->setCoordinatesOfActualLUCorner(CCoordinates(14,11));
    school2->setActualNumberOfWorkers(CPeople(5,0,0,0,1));
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();


    House->searchSetForBetterSchool();
    House->educatePeople();
    House->extractEducatedPeople();
    school2->addWorkers(CPeople(-1,0,0,0,0));
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();
    House->searchSetForBetterSchool();
    House->educatePeople();
    House->extractEducatedPeople();
    House->searchSetForBetterSchool();
    House->educatePeople();
    House->extractEducatedPeople();
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();
    House->educatePeople();
    House->extractEducatedPeople();
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();
    House->educatePeople();
    House->extractEducatedPeople();
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();
    House->educatePeople();
    House->extractEducatedPeople();
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();
    House->optimizeListOfLearningPeople();
    House->educatePeople();
    House->extractEducatedPeople();
    school1->countSetEducationQuality();
    school2->countSetEducationQuality();
    House->optimizeListOfLearningPeople();

    CShop* shop1 = new CShop;
    shop1->setProductsSellPrice(CProducts(8,5,2));
    shop->setProductsSellPrice(CProducts(8,5,2));
    shop1->setCity(city);
    shop1->setSizeOnGameMap(CCoordinates(1,1));
    shop1->setNeededNumberOfWorkers(CPeople(0,1,1,5,5));
    city->getMapOfStructures()->addStructureProperly(shop1);
    CShop* shop2 = new CShop(*shop1);
    shop1->setCoordinatesOfActualLUCorner(CCoordinates(15,15));
    shop2->setCoordinatesOfActualLUCorner(CCoordinates(20,15));
    city->getMapOfStructures()->addStructureProperly(shop2);
    House->setPeopleNeeds(CPeopleNeeds(CProducts(5,10,30),CService(),CRecreation(),2,2));
    House->searchAndSendNeedsToShops();
    CFarm* farm1 = new CFarm;
    CLightFactory* light = new CLightFactory;
    CHeavyFactory* heavy = new CHeavyFactory;
    city->addStructureProperly(farm1);
    city->addStructureProperly(light);
    city->addStructureProperly(heavy);
    farm1->setStackedProducts(CProducts(0,0,5));
    farm1->setActualProductionPerTick(CProducts(0,0,20));
    light->setStackedProducts(CProducts(10,0,0));
    light->setActualProductionPerTick(CProducts(8,0,0));
        city->addStructureProperly(heavy);
    heavy->setStackedProducts(CProducts(0,20,0));
    heavy->setActualProductionPerTick(CProducts(0,15,0));

    farm1->setNeededNumberOfWorkers(CPeople(1,1,1,2,7));
    light->setNeededNumberOfWorkers(CPeople(1,1,7,2,3));
    heavy->setNeededNumberOfWorkers(CPeople(1,1,1,8,3));
    farm1->setMaxStackedProducts(CProducts(0,0,30));
    light->setMaxStackedProducts(CProducts(10,0,0));
    heavy->setMaxStackedProducts(CProducts(0,20,0));

    CBlocks* blocks = new CBlocks;
    blocks->setSizeOnGameMap(CCoordinates(1,1));
    blocks->setCoordinatesOfActualLUCorner(CCoordinates(23,14));
    blocks->setPeopleNeeds(CPeopleNeeds());
    blocks->setServiceNeed(CService(40));
    city->addStructureProperly(blocks);
    House->setServiceNeed(CService(10));
    House->setMaxLivingPeople(15);
    House->addNewLearningPeople(CPeople(1,1,0,0,0));
    blocks->addNewLearningPeople(CPeople(1,2,4,3,1));
    blocks->setLivingWorkingPeople(CPeople(2,3,8,10,10));
    blocks->setMaxLivingPeople(50);
    House->searchSetForBetterSchool();
    blocks->searchSetForBetterSchool();
    COffice* office1 = new COffice;
    office1->setSizeOnGameMap(CCoordinates(1,1));
    office1->setCoordinatesOfActualLUCorner(CCoordinates(18,14));
    office1->setNeededNumberOfWorkers(CPeople(2,5,3,0,2));
    office1->setActualNumberOfWorkers(CPeople(1,5,2,0,2));
    office1->setBaseService(CService(20));
    office1->setBaseServiceCost(CService(20));
    COffice* office2 = new COffice(*office1);
    office2->setCoordinatesOfActualLUCorner(CCoordinates(20,23));
    office2->setActualNumberOfWorkers(CPeople(2,5,2,0,2));
    city->addStructureProperly(office1);
    city->addStructureProperly(office2);
    blocks->setLivingWorkingPeople(CPeople(1,3,5,7,10));

    office1->countSetServiceQuality();
    office1->countSetActualServiceCost();
    office2->countSetServiceQuality();
    office2->countSetActualServiceCost();
    city->getSocietyIndicators()->setBasePeopleEarnings(CPeopleEarnings(30,20,16,13,10));
    city->getMarket()->setBaseProductsCost(CProducts(lightCost,heavyCost,foodCost));
    city->getTrafficEngine()->createMapOfTraffic();
   // city->getTaxes()->setFromPeopleInd();
    for(int i=0; i<5;i++)
        city->makeTick();
*/

    return a.exec();
}

