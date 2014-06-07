#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    city = new CCity;
    city->initializeCity();

    playerName = "Fuhrer";
    ///[1]timer
    autoTick = false;
    tickTime = 5000;
    tickTimer = new QTimer(this);
    tickTimer->setSingleShot(true);
    connect(tickTimer,SIGNAL(timeout()),this,SLOT(autoTickTimeout()));
    ///[/1]

    mainWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout();
   // setCentralWidget(mainWidget);

    createActions();
    createMenus();
    createToolBar();
    connectSignalsSlots();
    createMap(1600,900);

    mainLayout->addWidget(mainView);
    mainView->show();
    mainWidget->setLayout(mainLayout);

    ///[2] creating backgroud map
    QPixmap bgPix("://Time-For-Lunch-2.jpg");
    QPalette pal(palette());
    pal.setBrush(QPalette::Background,bgPix);
    mainWidget->setAutoFillBackground(true);
    mainWidget->setPalette(pal);
    ///[/2]

    //mainWidget->setBackgroundRole(QPalette::Background,QColor(30,130,66));
   // this->setCentralWidget(buildingView);
    this->setCentralWidget(mainWidget);

    QString message = tr("Welcome in SimCity");
    statusBar()->showMessage(message);
    setWindowTitle(tr("SimCity"));
    setMinimumSize(800,600);
    this->setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::closeEvent(QCloseEvent *event)
{   if(QMessageBox::Yes == QMessageBox::question(this,"Confirm exit",
            "Are you sure you want to exit the game?",
            QMessageBox::Yes|QMessageBox::No))
    {   taxesWidget->close();
        event->accept();}
    else
        event->ignore();
}

void MainWindow::createActions()
{
    newGameAct = new QAction(tr("&New"),this);
    newGameAct->setStatusTip(tr("Start new game"));
    connect(newGameAct,SIGNAL(triggered()),this,SLOT(newGame()));

    exitAct = new QAction(tr("&Exit"),this);
    exitAct->setStatusTip(tr("Exit game"));
    connect(exitAct,SIGNAL(triggered()),this,SLOT(close()));

    taxesAct = new QAction(tr("&Taxes"),this);
    taxesAct->setStatusTip(tr("Change taxes"));
    connect(taxesAct,SIGNAL(triggered()),this,SLOT(taxes()));

    trafficAct = new QAction(tr("&Traffic"),this);
    trafficAct->setStatusTip(tr("Global traffic information"));
    connect(trafficAct,SIGNAL(triggered()),this,SLOT(traffic()));

    peopleStatisticsAct = new QAction(tr("&People"),this);
    peopleStatisticsAct->setStatusTip(tr("Statistics about people"));
    connect(peopleStatisticsAct,SIGNAL(triggered()),this,SLOT(peopleStatistics()));

    publicUtilityAct = new QAction(tr("&Utilities"),this);
    publicUtilityAct->setStatusTip(tr("Public utilites: dump, electricity, water"));
    connect(publicUtilityAct,SIGNAL(triggered()),this,SLOT(publicUtility()));

    showInfoAct = new QAction(tr("&Show info"),this);
    showInfoAct->setStatusTip(tr("Show information about object"));
    connect(showInfoAct,SIGNAL(triggered()),this,SLOT(showInfo()));

    destroyAct = new QAction(tr("&Destoy"),this);
    destroyAct->setStatusTip(tr("Destroy object"));
    connect(destroyAct,SIGNAL(triggered()),this,SLOT(destroy()));
}
void MainWindow::createMenus()
{
    gameMenu = menuBar()->addMenu(tr("&Game"));
        gameMenu->addAction(newGameAct);
        gameMenu->addSeparator();
        gameMenu->addAction(exitAct);
    cityManagement = menuBar()->addMenu(tr("Management"));
        cityManagement->addAction(taxesAct);
    statistics = menuBar()->addMenu(tr("Statistics"));
        statistics->addAction(trafficAct);
        statistics->addAction(peopleStatisticsAct);
        statistics->addAction(publicUtilityAct);

    taxesWidget = new CGraphicTaxes;
}
void MainWindow::createToolBar()
{
    mainToolBar = new QToolBar(this);

    QPalette pal(palette());
    pal.setColor(QPalette::Button,Qt::white);
    name = new QLabel(this);
    name->setText(playerName);
    name->setPalette(pal);
    name->setAutoFillBackground(true);
    name->setFixedWidth(100);

    QLabel *moneyText = new QLabel(this);
    moneyText->setText(tr("Money: "));
    moneyText->setPalette(pal);
    moneyText->setAutoFillBackground(true);
    money = new QLabel(this);
    money->setText(QString::number(city->getMoney())+" $");
    money->setPalette(pal);
    money->setAutoFillBackground(true);
    money->setAlignment(Qt::AlignCenter);
    money->setFixedWidth(100);

    QLabel *incomeText = new QLabel(this);
    incomeText->setText(tr("+"));
    incomeText->setPalette(pal);
    incomeText->setAutoFillBackground(true);
    income = new QLabel(this);
    income->setText(QString::number(city->getIncome())+" $/turn");
    income->setPalette(pal);
    income->setAutoFillBackground(true);
    income->setAlignment(Qt::AlignCenter);
    income->setFixedWidth(100);

    QLabel *NOPeopleText = new QLabel(this);
    NOPeopleText->setText(tr("Number of people: "));
    NOPeopleText->setPalette(pal);
    NOPeopleText->setAutoFillBackground(true);
    NOPeople = new QLabel(this);
    NOPeople->setPalette(pal);
    NOPeople->setAutoFillBackground(true);
    NOPeople->setText(QString::number(city->getSocietyIndicators()->getAllPeople().getAllPeople()));
    NOPeople->setAlignment(Qt::AlignCenter);
    NOPeople->setFixedWidth(100);

    nextTurnButton = new QPushButton(this);
    nextTurnButton->setText(tr("&Next turn"));
    pal.setColor(QPalette::Button,QColor(230,200,167));
    nextTurnButton->setFocusPolicy(Qt::StrongFocus);
    nextTurnButton->setStyleSheet("*{background-color: rgb(100,235,167)}");
    nextTurnButton->setAutoFillBackground(true);
    nextTurnButton->setPalette(pal);
    nextTurnButton->setFixedSize(160,40);
    connect(nextTurnButton,SIGNAL(clicked()),this,SLOT(nextTurnStart()));
    connect(this,SIGNAL(nextTurnEnded()),this,SLOT(nextTurnEnd()));

    autoTickBox = new QCheckBox(this);
    autoTickBox->setText(tr("Auto\nnext turn"));
    autoTickBox->setToolTip(tr("Check if u want program\nto make NEXT TURN\nafter specified time [ms]"));
    autoTickBox->setAutoFillBackground(true);
    autoTickBox->setPalette(pal);
    autoTickBox->setFixedSize(90,35);
    connect(autoTickBox,SIGNAL(stateChanged(int)),this,SLOT(autoTickChanged()));

    tickTimeLabel = new QLabel(this);
    tickTimeLabel->setText(QString::number((double)tickTime/1000,'f',1)+tr(" s"));
    tickTimeLabel->setFixedSize(40,35);
    tickTimeLabel->setStyleSheet("*{qproperty-alignment: AlignCenter; }");
    tickTimeLabel->setDisabled(true);
    tickTimeLabel->setPalette(pal);
    tickTimeLabel->setAutoFillBackground(true);

    tickTimeSpinBox = new QSpinBox(this);
    tickTimeSpinBox->setAutoFillBackground(true);
    tickTimeSpinBox->setPalette(pal);
    tickTimeSpinBox->setFixedSize(15,35);
    tickTimeSpinBox->setMinimum(500);
    tickTimeSpinBox->setMaximum(60000);
    tickTimeSpinBox->setValue(tickTime);
    tickTimeSpinBox->setSingleStep(500);
    connect(tickTimeSpinBox,SIGNAL(valueChanged(int)),this,SLOT(autoTickChangedValue()));

    mainToolBar->addWidget(name);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(moneyText);
    mainToolBar->addWidget(money);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(incomeText);
    mainToolBar->addWidget(income);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(NOPeopleText);
    mainToolBar->addWidget(NOPeople);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(nextTurnButton);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(autoTickBox);
    mainToolBar->addWidget(tickTimeLabel);
    mainToolBar->addWidget(tickTimeSpinBox);

    mainToolBar->setMovable(false);
    this->addToolBar(mainToolBar);
}
void MainWindow::createMap(int _w, int _h)
{
    mainView = new CGraphicMainView(_w,_h,this);
}

void MainWindow::connectSignalsSlots()
{   connect(taxesWidget,SIGNAL(taxesChanged()),this,SLOT(taxesWidgetChanged()));
    connect(taxesWidget,SIGNAL(taxesRead()),this,SLOT(taxesWidgetRead()));
}
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(showInfoAct);
    menu.addAction(destroyAct);
    menu.exec(event->globalPos());
}
void MainWindow::newGame()
{}
void MainWindow::taxes()
{
    taxesWidget->show();
}
void MainWindow::taxesWidgetChanged()
{   city->getTaxes()->setFromProductionInd(taxesWidget->getFromProductionInd());
    city->getTaxes()->setFromPeopleInd(taxesWidget->getFromPeopleInd());
    city->getTaxes()->setFromOthersInd(taxesWidget->getFromOthersInd());
    this->setDisabled(false);
}
void MainWindow::taxesWidgetRead()
{
    taxesWidget->setValues(city->getTaxes()->getFromProductionInd(),city->getTaxes()->getFromPeopleInd(),city->getTaxes()->getFromOthersInd());
}
void MainWindow::traffic()
{}
void MainWindow::peopleStatistics()
{}
void MainWindow::publicUtility()
{}
void MainWindow::destroy()
{}
void MainWindow::showInfo()
{}
void MainWindow::nextTurn()
{
    qDebug()<<"turn: "<<turnNumber;
    turnNumber++;
    this->update();
    for(int i=0; i<100000000;i++)
    {   int x=1000000;
        x=i*x*x;}
    emit nextTurnEnded();
}
void MainWindow::autoTickChanged()
{
    autoTick = autoTickBox->isChecked();
    qDebug()<<"autoTick: "<<autoTick;
    if(autoTick)
    {   tickTimer->start(tickTime);}
}
void MainWindow::autoTickChangedValue()
{   tickTime = tickTimeSpinBox->value();
    tickTimeLabel->setText(QString::number((double)tickTime/1000,'f',1)+tr(" s"));
    qDebug()<<"tick time: "<<(double)tickTime/1000;}

void MainWindow::autoTickTimeout()
{
    if(autoTick)
    {   this->nextTurn();
    tickTimer->start(tickTime);}
}
void MainWindow::nextTurnStart()
{   nextTurnButton->setStyleSheet("*{background-color: rgb(240,90,10)}");
    nextTurnButton->blockSignals(true);
    nextTurnButton->setDisabled(true);
    nextTurnButton->update();
    nextTurnButton->repaint();
    this->repaint();
    MainWindow::nextTurn();
}
void MainWindow::nextTurnEnd()
{   nextTurnButton->setStyleSheet("*{background-color: rgb(100,235,167)}");
    nextTurnButton->blockSignals(false);
    nextTurnButton->setDisabled(false);
    nextTurnButton->update();
    nextTurnButton->repaint();
    this->repaint();
}

