#include "mainwindow.h"
#include <QApplication>

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

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

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

    CPowerStation A;
    A.setProperUtility(10);




    //CRoad B(A);

    w.show();
    return a.exec();
}
