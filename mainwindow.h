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
    //void contextMenuEvent(QContextMenuEvent *event);

public:
    explicit MainWindow(QSize mapSize, QSize tileSize, QWidget *parent = 0);
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

    QWidget *mainWidget;
    CGraphicMainView *mainView;

    CGraphicTaxes *taxesWidget;

    QMenu *gameMenu;
        QAction *newGameAct;
        QAction *exitAct;
    QMenu *cityManagement;
        QAction *taxesAct;
    QMenu *statistics;
        QAction *trafficAct;
        QAction *peopleStatisticsAct;
        QAction *publicUtilityAct;
    QLabel* infoLabel;


signals:
    void nextTurnEnded();
    void newStructure(CStructure);
    void canBeBuiled(bool);

private slots:
    void newGame();
    void taxes();
    void traffic();
    void peopleStatistics();
    void publicUtility();
    void destroy();
    void showInfo();
    void nextTurn();

    void autoTickChanged();
    void autoTickChangedValue();
    void autoTickTimeout();
    void nextTurnStart();
    void nextTurnEnd();

    void taxesWidgetChanged();
    void taxesWidgetRead();

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
};

#endif // MAINWINDOW_H
