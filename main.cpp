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


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    //CStructure structure;
    //CCoordinates C(1,4);
    //structure.setSizeOnGameMap(C);
    //qDebug()<<structure.getSizeOnGameMap().getY();
   // structure.setSizeOnGameMap(CCoordinates(666,3));
    //qDebug()<<"po zmianie "<< (structure.getSizeOnGameMap()).getX();

    /*CDirections dir;
    dir = CDirections(true, true, false, false);
    qDebug()<<dir.getDirUp()<<dir.getDirRight()<<dir.getDirDown()<<dir.getDirLeft();
    dir.rotate(rightRot);
    qDebug()<<dir.getDirUp()<<dir.getDirRight()<<dir.getDirDown()<<dir.getDirLeft();
    dir.rotate(leftRot);
    qDebug()<<dir.getDirUp()<<dir.getDirRight()<<dir.getDirDown()<<dir.getDirLeft();
    dir.rotate(halfRoundRot);
    qDebug()<<dir.getDirUp()<<dir.getDirRight()<<dir.getDirDown()<<dir.getDirLeft();
*/
    /*CRoadsAndBridges road;
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    road.rotate(rightRot);
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    road.setDirections(CDirections(true,false,false,false));
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    */
    /*CRoadCross road;
    qDebug()<<(road.getTurnedDirection()).getDirUp()<<(road.getTurnedDirection()).getDirRight();
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    road.rotate(rightRot);
    qDebug()<<(road.getTurnedDirection()).getDirUp()<<(road.getTurnedDirection()).getDirRight();
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    road.rotate(rightRot);
    qDebug()<<(road.getTurnedDirection()).getDirUp()<<(road.getTurnedDirection()).getDirRight();
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    road.rotate(rightRot);
    qDebug()<<(road.getTurnedDirection()).getDirUp()<<(road.getTurnedDirection()).getDirRight();
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
    road.rotate(rightRot);
    qDebug()<<(road.getTurnedDirection()).getDirUp()<<(road.getTurnedDirection()).getDirRight();
    qDebug()<<(road.getDirections()).getDirUp()<<(road.getDirections()).getDirRight();
*/
    /*CBuilding bui(1000,CUtilitiesGlobal(20,1,1));
    double x=5;
    bui.setUtilities(bui.getUtilities()+CUtilitiesGlobal(-x,3,1));

    qDebug()<<(bui.getUtilities()).getElectricity();
    w.show();*/

    //CPeopleNeeds PN(CProducts(3,1,3),CService(),CRecreation(8),3,2);


    /*CPeopleNeeds PN;

    double life=1;
    PN.countNewNeeds(life);
    life=PN.countLifeSatisfation(0,life);
    PN.countNewNeeds(life);
    life = PN.countLifeSatisfation(100,life);
    PN.countNewNeeds(life);
    life = PN.countLifeSatisfation(1000,life);
    PN.countNewNeeds(life);
    //PN=CPeopleNeeds();
    life =PN.countLifeSatisfation(100,life);
    PN.countNewNeeds(life);
    //PN=CPeopleNeeds();
    life = PN.countLifeSatisfation(100,life);
    PN.countNewNeeds(life);
   // PN=CPeopleNeeds();
    life = PN.countLifeSatisfation(100,life);
    PN.countNewNeeds(life);
   // PN=CPeopleNeeds();
    life = PN.countLifeSatisfation(0,life);
    PN.countNewNeeds(life);
    life = PN.countLifeSatisfation(-1000,life);
    PN.countNewNeeds(life);
    life = PN.countLifeSatisfation(-1000,life);
    PN.countNewNeeds(life);
    life = PN.countLifeSatisfation(0,life);
    PN.countNewNeeds(life);
    life = PN.countLifeSatisfation(0,life);
    PN.countNewNeeds(life);*/

    /*CPeopleNeeds A(CProducts(3,1,5),CService(2),CRecreation(8),3,2);
    8//A += CPeopleNeeds(CProducts(),CService(2.1),CRecreation(),0,1);
    A.setProductsNeed(CProducts(1,2,3));
    A.addDisturbance(10);
    A += CService(666);
    A += CRecreation(-123);*/

    //CLearningPeople C(1,2,3,4,5);
   // C = CPeople(10,10,10,10,10);
    //CPeople* D = new CPeople(5,5,5,5,5);
   /* CLearningPeople C(*D,1,3,4,1,1);
    //CLearningPeople A(B);
    CPeople A(1,1,1,1,1);
    CPeople B(2,2,2,2,2);
    B +=A;
    B+=C;*/
    //CLiving A;
   // CLiving B;
    /*CLiving A;
    CPeople B;
    A.addNewLearningPeople(CPeople(0,0,2,0,1));
    A.educatePeople(5.6);
    B += A.extractEducatedPeople();
    A.optimizeListOfLearningPeople();
    A.addNewLearningPeople(CPeople(0,0,1,0,4));
    A.educatePeople(5.6);
    CLiving liv(A);
    B += A.extractEducatedPeople();
    A.optimizeListOfLearningPeople();
    A.educatePeople(5.6);
    B += A.extractEducatedPeople();
    A.optimizeListOfLearningPeople();
    A.educatePeople(10);
    B += A.extractEducatedPeople();
    A.optimizeListOfLearningPeople();
    A.educatePeople(10);
    B += A.extractEducatedPeople();
    A.optimizeListOfLearningPeople();*/

    //CPowerStation A;
    //A.setProperUtility(10);

    //qDebug()<<"0\n";
    /*CWorking A;
    A.setAge(10);
    A.setBuildCost(4);
    A.setNeededNumberOfWorkers(CPeople(1,3,4,1,1));
    A.setMoney(6666.66666);

    CWorking B(A);*/
    /*bool _if;
    CRecreationBuilding A;
    A.addMoney(1231231);
    _if=A.addWorkers(CPeople(1,3,2,0,2));
    _if=A.setNeededNumberOfWorkers(CPeople(1,4,2,0,2));
    _if=A.addWorkers(CPeople(1,3,2,0,2));
    _if=A.addWorkers(CPeople(0,0,-1,0,0));
    _if=A.setActualNumberOfWorkers(CPeople(1,4,1,0,1));
    A.setMaxNOCustomers(10);
    A.setBaseRecreation(CRecreation(10));
    _if=A.addWorkers(CPeople(-6,-3,-1,0,-1));
    _if=A.setActualNumberOfWorkers(CPeople(1,1,1,1,1));
    _if=A.setActualNumberOfWorkers(CPeople(-3,-1,1,1,1));

    A.setActualRecreation(CRecreation(4));
    A.countSetRecreationQuality();
    A.addCustomers(5);
    _if=A.addWorkers(CPeople(1,3,2,0,2));
    A.countSetRecreationQuality();
    CRecreationBuilding B(A);
    A.addWorkers(CPeople(0,1,0,0,0));
    A.countSetRecreationQuality();
    A.addCustomers(5);
    A.countSetRecreationQuality();
    A.addCustomers(5);
    A.countSetRecreationQuality();
    A.addCustomers(5);
    A.countSetRecreationQuality();
    _if=A.addWorkers(CPeople(-1,-3,-1,0,-1));
    A.countSetRecreationQuality();*/

    /*CSocietyIndicators A;
    A.setAllPeople(CPeople(30,30,50,80,100));
    A.setAllLivingWorkingPeople(CPeople(25,25,45,65,85));
    A.setAllLivingNotWorkingPeople(CPeople(0,0,0,5,5));
    A.setAllLearningPeople(CPeople(5,5,5,10,10));

    A.setBasePeopleEarnings(CPeopleEarnings(2000,1800,1600,1400,1000));
    A.setAllWorkForPeople(CPeople(25,30,50,75,100));
    A.setChildren(0);

    A.setPeopleEarnings(A.countPeopleEarnings());
    A.setAllProfessionsToEducate(A.countProffesionsToEducate());*/

   /* CLiving A;
    A.setMaxLivingPeople(120);
    A.setLivingWorkingPeople(CPeople(5,10,15,20,30));
    A.setLivingNotWorkingPeople(CPeople(0,0,0,5,5));
    A.setChildren(5);
    A.setIncome(1000*90);
    A.setLifeSatisfaction(1);
    A.setPeopleNeeds(A.countPeopleNeeds());
    A.setLifeSatisfaction(A.countLifeSatisfaction());
    A.setPeopleNeeds(A.countPeopleNeeds());
    A.setLifeSatisfaction(A.countLifeSatisfaction());
    A.setPeopleNeeds(A.countPeopleNeeds());
    A.setLifeSatisfaction(A.countLifeSatisfaction());*/


    CCity* city = new CCity;
    //city->setMapOfStructures(new CMapOfStructures());
    CCoordinates C;
    bool f;

    city->getMapOfStructures()->setMapSize(CCoordinates(40,50));
    city->getMapOfStructures()->setMakeMapOfTakenPlaces();
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
/*
    for(int blaa=0; blaa<4; blaa++)
    {
        for(int i=0; i< city->getMapOfStructures()->getAllProductionBuildings().count();i++)
        {   city->getMapOfStructures()->getAllProductionBuildings().at(i)->sendProductionInfoToMarket();
        }
        city->getMapOfStructures()->getAllShops().at(1)->sendProductsNeedToMarket();
        for(int i=0; i<city->getMapOfStructures()->getAllShops().count(); i++)
        {   city->getMapOfStructures()->getAllShops().at(i)->sendProductsNeedToMarket();
        }
        city->getMarket()->setBaseProductsCost(CProducts(5,2,1));
        city->getMarket()->countSetActualProductsCost();
        city->getMarket()->takeAndPayPBForProducts();
        city->getMarket()->splitAndSendProductsToShops();
        for(int i=0; i<city->getMapOfStructures()->getAllShops().count(); i++)
        {   city->getMapOfStructures()->getAllShops().at(i)->countSetProductsSellPrice();
            city->getMapOfStructures()->getAllShops().at(i)->sendProductsToLivings();
        }
    }*/
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
    /*for(int i=0; i<3;i++)
    {   House->searchForService();
        blocks->searchForService();
        office1->giveServiceToLivings();
        office2->giveServiceToLivings();
        House->countSetLifeSatAndPeopleNeeds();
        blocks->countSetLifeSatAndPeopleNeeds();
        House->countSetBirthRate();
        blocks->countSetBirthRate();
        House->changeLivingPlace();
        blocks->changeLivingPlace();
        House->makeDeadsAndBorns();
        blocks->makeDeadsAndBorns();
        House->searchAndGoToWork();
        blocks->searchAndGoToWork();
        office1->clearTemporary();
        office2->clearTemporary();
    }*/

    city->getTrafficEngine()->countTraffic();
    House->countSetInfluanceFromOthers();
    blocks->countSetInfluanceFromOthers();
    House->getSetTrafficInformation();
    blocks->getSetTrafficInformation();

    w.show();
    return a.exec();
}
