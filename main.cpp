#include "mainwindow.h"
#include <QApplication>

#include "cstructure.h"
#include "croadsandbridges.h"
#include "croad.h"
#include "cutilitiesglobal.h"
#include "cgreenterrain.h"
#include "cbuilding.h"
#include "cpeopleneeds.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    CStructure structure;
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



    w.show();
    return a.exec();
}
