#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QContextMenuEvent>
#include <QAction>
#include <QString>
#include <QLabel>
#include <QLayout>
#include <QToolBar>
#include <QtWidgets>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMenu>
#include <QTimer>
#include <QCloseEvent>
#include <QSize>
#include "ccity.h"
#include "cgraphictaxes.h"
#include "cgraphicmainview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    CStructure* makeNewStructureProperly(CStructure *checking);

public:
    explicit MainWindow(QString userName, QSize mapSize, QSize tileSize, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createToolBar();
    void createBuildingToolBar();
    void connectSignalsSlots();
    void createMap();
    void createCity();

    void closeEvent(QCloseEvent *);

    CCity* city;
    QString playerName;
    QSize mapSize; //in game squares
    QSize tileSize; //size of 1 game tile

    int tickTime; //ms
    bool autoTick;
    QTimer *tickTimer;
    static int turnNumber;

    QToolBar *mainToolBar;
        QPushButton *nextTurnButton;
        QLabel *name;
        QLabel *money;
        QLabel *income;
        QLabel *NOPeople;
        QLabel *turn;
        QCheckBox *autoTickBox;
        QLabel *tickTimeLabel;
        QSpinBox *tickTimeSpinBox;

    QToolBar *buildingToolBar;
        QAction *houseAct;
        QAction *blocksAct;

        QAction *lawnAct;
        QAction *parkAct;

        QAction *officeAct;
        QAction *shopAct;
        QAction *schoolAct;
        QAction *cinemaAct;

        QAction *farmAct;
        QAction *lightFactoryAct;
        QAction *heavyFactoryAct;

        QAction* publicUtilityBuildingAct;

        QAction *roadStraightAct;
        QAction *roadCrossAct;
        QAction* roadTurnAct;
        QAction* roadThreeWayAct;

    QWidget *mainWidget;
    CGraphicMainView *mainView;

    CGraphicTaxes *taxesWidget;

    QMenu *gameMenu;
        QAction *newGameAct;
        QAction *exitAct;
    QMenu *cityManagement;
        QAction *taxesAct;
        QAction *societyStatisticsAct;
        QAction *marketAct;
        QAction *publicUtilityAct;
    QLabel* infoLabel;


signals:
    void nextTurnEnded();
    void newStructure(CStructure *);
    void canBeBuiled(CStructure *,bool);

private slots:
    void newGame();
    void taxes();
    void societyStatistics();
    void market();
    void publicUtility();
    void destroy(CStructure*);
    void showInfo();
    void nextTurn();

    void autoTickChanged();
    void autoTickChangedValue();
    void autoTickTimeout();
    void nextTurnStart();
    void nextTurnEnd();

    void taxesWidgetChanged();
    void taxesWidgetRead();
    void basePeopleEarningsChangedLead(int);
    void basePeopleEarningsChangedService(int);
    void basePeopleEarningsChangedLight(int);
    void basePeopleEarningsChangedHeavy(int);
    void basePeopleEarningsChangedLow(int);
    void baseProductsCostChangedFood(int);
    void baseProductsCostChangedLight(int);
    void baseProductsCostChangedHeavy(int);

    void canBeBuiledStructure(CStructure *);

    void newHouse();
    void newBlocks();
    void newLawn();
    void newPark();
    void newOffice();
    void newShop();
    void newSchool();
    void newCinema();
    void newFarm();
    void newLightFactory();
    void newHeavyFactory();
    void newPublicBuilding();
    void newRoadStraight();
    void newRoadCross();
    void newRoadTurn();
    void newRoadThreeway();
};

#endif // MAINWINDOW_H
