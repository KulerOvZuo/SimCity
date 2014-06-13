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
/**
 * @brief Klasa MainWindow (główne okno gry)
 *
 *Klasa odpowiada za połączenie elementów graficznych w całość. Jest także głównym interfejsem użytkownika.
 *Przechowuje model graficzny gry. Pośredniczy w przesyłaniu informacji pomiędzy grafiką a modelem.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    /**
     * @brief Utwórz nową strukturę
     *
     *Metoda powoduje utworzenie nowej struktury jako kopii struktury \b checking\c schodząc niżej w hierarchii dziedziczenia.
     * @param checking - wskaźnik do struktury kopiowanej
     * @return Zwraca nową strukturę albo NULL jeśli utworzenie się nie powiodło.
     */
    CStructure* makeNewStructureProperly(CStructure *checking);

public:
    explicit MainWindow(QString userName, QSize mapSize, QSize tileSize, QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ///Łączy akcje okna
    void createActions();
    ///Tworzy menu okna
    void createMenus();
    ///Tworzy toolbar wyświelajaćy informacje o mieście
    void createToolBar();
    ///Tworzy toolbar ikon budynków
    void createBuildingToolBar();
    ///Łączy sygnały i sloty
    void connectSignalsSlots();
    ///Inicjalizuje utworzenie mapy gry
    void createMap();
    ///Inicjalizuje utworzenie miasta
    void createCity();

    void closeEvent(QCloseEvent *);

    ///Wskaźnik do miasta
    CCity* city;
    ///Imię gracza
    QString playerName;
    ///Wielkość mapy w żetonach
    QSize mapSize; //in game squares
    ///Wielkość żetonu w pixelach
    QSize tileSize; //size of 1 game tile
    QWidget *mainWidget;
    ///Wskaźnik do obiektu mapy
    CGraphicMainView *mainView;
    ///Wskaźnik do menadżera podatków
    CGraphicTaxes *taxesWidget;

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
    ///Sygnał emitowany jest wtedy, gdy wystąpiło wydarzenie w którym należy utworzyć nową strukturę
    void newStructure(CStructure *);
    ///Sygnał jest emitowany po sprawdzeniu czy struktura możę być wybudowana.
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

    /**
     * @brief Struktura może być wybudowana
     *
     *Metoda sprawdza czy struktura może być wybudowana w mieście.
     *Jeśli tak to poprawnie go inicjalizuje, dodaje do miasta i buduje.
     */
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
