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
    void contextMenuEvent(QContextMenuEvent *event);

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    void createToolBar();
    void connectSignalsSlots();
    void createMap(int _w, int _h);
    void closeEvent(QCloseEvent *);

    CCity* city;
    QString playerName;
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
        QCheckBox *autoTickBox;
        QLabel *tickTimeLabel;
        QSpinBox *tickTimeSpinBox;

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
    QMenu *contextMenu;
        QAction *destroyAct;
        QAction *showInfoAct;
    QLabel* infoLabel;

signals:
    void nextTurnEnded();

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
};

#endif // MAINWINDOW_H
