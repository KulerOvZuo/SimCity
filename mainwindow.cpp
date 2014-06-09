#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <cmath>

MainWindow::MainWindow(QSize mapSize, QSize tileSize, QWidget *parent) :
    QMainWindow(parent)
   // ui(new Ui::MainWindow)
{
    //ui->setupUi(this);
    this->mapSize = QSize(mapSize);
    this->tileSize = QSize(tileSize);

    createCity();

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
    createBuildingToolBar();
    createMap();
    connectSignalsSlots();

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
    setWindowTitle(tr("Si(M)City"));
    setMinimumSize(tileSize.width()*mapSize.width()+50,tileSize.height()*mapSize.height()+200);
   // this->setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    //delete ui;
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
    money->setFixedWidth(140);

    QLabel *incomeText = new QLabel(this);
    incomeText->setText(tr("+"));
    incomeText->setPalette(pal);
    incomeText->setAutoFillBackground(true);
    income = new QLabel(this);
    income->setText(QString::number(city->getIncome())+" $/turn");
    income->setPalette(pal);
    income->setAutoFillBackground(true);
    income->setAlignment(Qt::AlignCenter);
    income->setFixedWidth(140);

    QLabel *NOPeopleText = new QLabel(this);
    NOPeopleText->setText(tr("Number of people: "));
    NOPeopleText->setPalette(pal);
    NOPeopleText->setAutoFillBackground(true);
    NOPeople = new QLabel(this);
    NOPeople->setPalette(pal);
    NOPeople->setAutoFillBackground(true);
    NOPeople->setText(QString::number(city->getSocietyIndicators()->getAllPeople().getAllPeople()));
    NOPeople->setAlignment(Qt::AlignCenter);
    NOPeople->setFixedWidth(140);

    turn = new QLabel(this);
    turn->setFixedSize(200,40);
    turn->setAutoFillBackground(true);
    turn->setPalette(pal);
    turn->setStyleSheet("*{qproperty-alignment: AlignCenter; }");
    turn->setText(tr("Turn number: ")+QString::number(turnNumber));

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
    mainToolBar->addWidget(turn);
    mainToolBar->addWidget(nextTurnButton);
    mainToolBar->addSeparator();
    mainToolBar->addWidget(autoTickBox);
    mainToolBar->addWidget(tickTimeLabel);
    mainToolBar->addWidget(tickTimeSpinBox);

    mainToolBar->setMovable(false);
    this->addToolBar(mainToolBar);
}
void MainWindow::createBuildingToolBar()
{
    buildingToolBar = new QToolBar;

    houseAct = new QAction(QIcon("://copy.png"),tr("House"),this);
    houseAct->setStatusTip(tr("Creates new house"));
    connect(houseAct,SIGNAL(triggered()),this,SLOT(newHouse()));

    blocksAct = new QAction(QIcon("://copy.png"),tr("Blocks"),this);
    blocksAct->setStatusTip(tr("Creates new blocks"));
    connect(blocksAct,SIGNAL(triggered()),this,SLOT(newBlocks()));

    lawnAct = new QAction(QIcon("://copy.png"),tr("Lawn"),this);
    lawnAct->setStatusTip(tr("Creates new lawn"));
    connect(lawnAct,SIGNAL(triggered()),this,SLOT(newLawn()));

    parkAct = new QAction(QIcon("://copy.png"),tr("Park"),this);
    parkAct->setStatusTip(tr("Creates new park"));
    connect(parkAct,SIGNAL(triggered()),this,SLOT(newPark()));

    officeAct = new QAction(QIcon("://copy.png"),tr("Office"),this);
    officeAct->setStatusTip(tr("Creates new office"));
    connect(officeAct,SIGNAL(triggered()),this,SLOT(newOffice()));

    shopAct = new QAction(QIcon("://copy.png"),tr("Shop"),this);
    shopAct->setStatusTip(tr("Creates new shop"));
    connect(shopAct,SIGNAL(triggered()),this,SLOT(newShop()));

    schoolAct = new QAction(QIcon("://copy.png"),tr("School"),this);
    schoolAct->setStatusTip(tr("Creates new school"));
    connect(schoolAct,SIGNAL(triggered()),this,SLOT(newSchool()));

    cinemaAct = new QAction(QIcon("://copy.png"),tr("Cinema"),this);
    cinemaAct->setStatusTip(tr("Creates new cinema"));
    connect(cinemaAct,SIGNAL(triggered()),this,SLOT(newCinema()));

    farmAct = new QAction(QIcon("://copy.png"),tr("Farm"),this);
    farmAct->setStatusTip(tr("Creates new farm"));
    connect(farmAct,SIGNAL(triggered()),this,SLOT(newFarm()));

    lightFactoryAct = new QAction(QIcon("://copy.png"),tr("Light Industry Factory"),this);
    lightFactoryAct->setStatusTip(tr("Creates new Light Industry Factory"));
    connect(lightFactoryAct,SIGNAL(triggered()),this,SLOT(newLightFactory()));

    heavyFactoryAct = new QAction(QIcon("://copy.png"),tr("Heavy Industry Factory"),this);
    heavyFactoryAct->setStatusTip(tr("Creates new Heavy Industry Factory"));
    connect(heavyFactoryAct,SIGNAL(triggered()),this,SLOT(newHeavyFactory()));

    publicUtilityBuildingAct = new QAction(QIcon("://copy.png"),tr("Public Utility Building"),this);
    publicUtilityBuildingAct->setStatusTip(tr("Creates new Public Utility Building"));
    connect(publicUtilityBuildingAct,SIGNAL(triggered()),this,SLOT(newPublicBuilding()));

    roadStraightAct = new QAction(QIcon("://copy.png"),tr("Straight Road"),this);
    roadStraightAct->setStatusTip(tr("Creates new Straight Road"));
    connect(roadStraightAct,SIGNAL(triggered()),this,SLOT(newRoadStraight()));

    roadCrossAct = new QAction(QIcon("://copy.png"),tr("Cross Road"),this);
    roadCrossAct->setStatusTip(tr("Creates new Cross Road"));
    connect(roadCrossAct,SIGNAL(triggered()),this,SLOT(newRoadCross()));

    roadTurnAct = new QAction(QIcon("://copy.png"),tr("Turning"),this);
    roadTurnAct->setStatusTip(tr("Creates new Turning"));
    connect(roadTurnAct,SIGNAL(triggered()),this,SLOT(newRoadTurn()));

    buildingToolBar->addAction(lawnAct);
    buildingToolBar->addAction(parkAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(houseAct);
    buildingToolBar->addAction(blocksAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(schoolAct);
    buildingToolBar->addAction(shopAct);
    buildingToolBar->addAction(officeAct);
    buildingToolBar->addAction(cinemaAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(farmAct);
    buildingToolBar->addAction(lightFactoryAct);
    buildingToolBar->addAction(heavyFactoryAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(publicUtilityBuildingAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(roadStraightAct);
    buildingToolBar->addAction(roadCrossAct);
    buildingToolBar->addAction(roadTurnAct);

    buildingToolBar->setMovable(false);
    this->addToolBarBreak();
    this->addToolBar(buildingToolBar);
}

void MainWindow::createMap()
{
    mainView = new CGraphicMainView(mapSize,tileSize,this);
}
void MainWindow::createCity()
{
    city = new CCity;
    city->initializeCity(mapSize);
}
void MainWindow::connectSignalsSlots()
{   connect(taxesWidget,SIGNAL(taxesChanged()),this,SLOT(taxesWidgetChanged()));
    connect(taxesWidget,SIGNAL(taxesRead()),this,SLOT(taxesWidgetRead()));
    connect(mainView,SIGNAL(checkIfCanBeBuiled(CStructure*)),this,SLOT(canBeBuiledStructure(CStructure*)));
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
void MainWindow::canBeBuiledStructure(CStructure *structure)
{
    structure->setCity(city);
    qDebug()<<"checking...";
    if(structure->checkIfCanBeBuiled())
    {   ///model build
        /*CStructure *_newS = new CStructure(*structure);
        _newS->setCoordinatesOfActualLUCorner(structure->getCoordinatesOfActualLUCorner());
        _newS->setCity(city);
        city->addStructureProperly(_newS);*/
        emit canBeBuiled(true);
    }
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
   // qDebug()<<"turn: "<<turnNumber;
    turnNumber++;
    this->update();
    for(int i=0; i<100000000;i++)
    {   int x=1000000;
        x=i*x*x;}
    turn->setText(tr("Turn number: ")+QString::number(turnNumber));
    emit nextTurnEnded();
}
void MainWindow::autoTickChanged()
{
    autoTick = autoTickBox->isChecked();
    //qDebug()<<"autoTick: "<<autoTick;
    if(autoTick)
    {   tickTimer->start(tickTime);}
}
void MainWindow::autoTickChangedValue()
{   tickTime = tickTimeSpinBox->value();
    tickTimeLabel->setText(QString::number((double)tickTime/1000,'f',1)+tr(" s"));
   // qDebug()<<"tick time: "<<(double)tickTime/1000;
}

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
void MainWindow::newHouse()
{   CHouse house;
    emit newStructure(house);}
void MainWindow::newBlocks()
{   CBlocks house;
    emit newStructure(house);}
void MainWindow::newLawn()
{   CLawn house;
    emit newStructure(house);}
void MainWindow::newPark()
{   CPark house;
    emit newStructure(house);}
void MainWindow::newOffice()
{   COffice house;
    emit newStructure(house);}
void MainWindow::newShop()
{   CSmallShop house;
    emit newStructure(house);}
void MainWindow::newSchool()
{   CSchoolAllInOne house;
    emit newStructure(house);}
void MainWindow::newCinema()
{   CCinema house;
    emit newStructure(house);}
void MainWindow::newFarm()
{   CFarm house;
    emit newStructure(house);}
void MainWindow::newLightFactory()
{   CLightFactory house;
    emit newStructure(house);}
void MainWindow::newHeavyFactory()
{   CHeavyFactory house;
    emit newStructure(house);}
void MainWindow::newPublicBuilding()
{   CPublicUtilityBuildingAllInOne house;
    emit newStructure(house);}
void MainWindow::newRoadStraight()
{   CRoadStraight house;
    emit newStructure(house);}
void MainWindow::newRoadCross()
{   CRoadCross house;
    emit newStructure(house);}
void MainWindow::newRoadTurn()
{   CRoadTurning house;
    emit newStructure(house);}
