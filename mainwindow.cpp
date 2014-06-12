#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QPixmap>
#include <QGridLayout>
#include <cmath>
#include <QSpacerItem>
#include <QToolBox>
#include <QFrame>
#include "cstartingwindow.h"

MainWindow::MainWindow(QString userName,QSize mapSize, QSize tileSize, QWidget *parent) :
    QMainWindow(parent)
{
    this->mapSize = QSize(mapSize);
    this->tileSize = QSize(tileSize);

    createCity();

    playerName = userName;
    //[1]timer
    autoTick = false;
    tickTime = 5000;
    tickTimer = new QTimer(this);
    tickTimer->setSingleShot(true);
    connect(tickTimer,SIGNAL(timeout()),this,SLOT(autoTickTimeout()));
    //[/1]

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

    //[2] creating backgroud map
    QPixmap bgPix("://Time-For-Lunch-2.jpg");
    QPalette pal(palette());
    pal.setBrush(QPalette::Background,bgPix);
    mainWidget->setAutoFillBackground(true);
    mainWidget->setPalette(pal);
    //[/2]

    this->setCentralWidget(mainWidget);

    QString message = tr("Welcome in SimCity");
    statusBar()->showMessage(message);
    setWindowTitle(tr("Si(M)City"));
    setMinimumSize(900,600);
    resize(1250,600);
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

    marketAct = new QAction(tr("&Market"),this);
    marketAct->setStatusTip(tr("Market information"));
    connect(marketAct,SIGNAL(triggered()),this,SLOT(market()));

    societyStatisticsAct = new QAction(tr("&Society"),this);
    societyStatisticsAct->setStatusTip(tr("Statistics about society"));
    connect(societyStatisticsAct,SIGNAL(triggered()),this,SLOT(societyStatistics()));

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
        cityManagement->addAction(marketAct);
        cityManagement->addAction(societyStatisticsAct);
        cityManagement->addAction(publicUtilityAct);
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
    name->setFixedWidth(200);

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

    mainToolBar->addSeparator();
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

    CHouse house;
    houseAct = new QAction(QIcon(housePixmapSource),
                           (QString("\bHouse\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4\nMax living people: %5").
                           arg(house.getBuildCost(),1).
                           arg(house.getUtilities().getDump(),2).
                           arg(house.getUtilities().getWater(),2).
                           arg(house.getUtilities().getElectricity(),2).
                           arg(house.getMaxLivingPeople(),2)),
                           this);
    houseAct->setStatusTip(tr("Creates new house"));
    connect(houseAct,SIGNAL(triggered()),this,SLOT(newHouse()));

    CBlocks blocks;
    blocksAct = new QAction(QIcon(blocksPixmapSource),
                            (QString("\bBlocks\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4\nMax living people: %5").
                            arg(blocks.getBuildCost(),1).
                            arg(blocks.getUtilities().getDump(),2).
                            arg(blocks.getUtilities().getWater(),2).
                            arg(blocks.getUtilities().getElectricity(),2).
                            arg(blocks.getMaxLivingPeople(),2)),
                            this);
    blocksAct->setStatusTip(tr("Creates new blocks"));
    connect(blocksAct,SIGNAL(triggered()),this,SLOT(newBlocks()));

    CLawn lawn;
    lawnAct = new QAction(QIcon(lawnPixmapSource),
                          (QString("\bLawn\nBuild cost: %1$\nKeep cost: %2$\nPeace: +%3").
                           arg(lawn.getBuildCost(),1).
                           arg(lawn.getCostPerTick(),1).
                           arg(lawn.getDisturbance(),1)),
                           this);
    lawnAct->setStatusTip(tr("Creates new lawn"));
    connect(lawnAct,SIGNAL(triggered()),this,SLOT(newLawn()));

    CPark park;
    parkAct = new QAction(QIcon(parkPixmapSource),
                          (QString("\bPark\nBuild cost: %1$\nKeep cost: %2$\nPeace: +%3").
                           arg(park.getBuildCost(),1).
                           arg(park.getCostPerTick(),1).
                           arg(park.getDisturbance(),1)),
                           this);
    parkAct->setStatusTip(tr("Creates new park"));
    connect(parkAct,SIGNAL(triggered()),this,SLOT(newPark()));

    COffice office;
    officeAct = new QAction(QIcon(officePixmapSource),
                            (QString("\bOffice\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4\nBase service: %5").
                            arg(office.getBuildCost(),1).
                            arg(office.getUtilities().getDump(),2).
                            arg(office.getUtilities().getWater(),2).
                            arg(office.getUtilities().getElectricity(),2).
                            arg(office.getBaseService().getService1(),2)),
                            this);
    officeAct->setStatusTip(tr("Creates new office"));
    connect(officeAct,SIGNAL(triggered()),this,SLOT(newOffice()));

    CShop shop;
    shopAct = new QAction(QIcon(shopPixmapSource),
                          (QString("\bShop\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4").
                          arg(shop.getBuildCost(),1).
                          arg(shop.getUtilities().getDump(),2).
                          arg(shop.getUtilities().getWater(),2).
                          arg(shop.getUtilities().getElectricity(),2)),
                          this);
    shopAct->setStatusTip(tr("Creates new shop"));
    connect(shopAct,SIGNAL(triggered()),this,SLOT(newShop()));

    CSchool school;
    schoolAct = new QAction(QIcon(schoolPixmapSource),
                            (QString("\bSchool\nBuild cost: %1$\nBuilding keep cost: %2$\nUtilities: dump: %3,water: %4,electricity: %5\nBase education indicator: %6").
                            arg(school.getBuildCost(),1).
                            arg(school.getCostPerTick(),1).
                            arg(school.getUtilities().getDump(),2).
                            arg(school.getUtilities().getWater(),2).
                            arg(school.getUtilities().getElectricity(),2).
                            arg(school.getBaseEducationIndicator(),1)),
                            this);
    schoolAct->setStatusTip(tr("Creates new school"));
    connect(schoolAct,SIGNAL(triggered()),this,SLOT(newSchool()));

    CCinema cinema;
    cinemaAct = new QAction(QIcon(cinemaPixmapSource),
                            (QString("\bCinema\nBuild cost: %1$\nBuilding keep cost: %2$\nUtilities: dump: %3,water: %4,electricity: %5\nBase recreation: %6").
                            arg(cinema.getBuildCost(),1).
                            arg(cinema.getCostPerTick(),1).
                            arg(cinema.getUtilities().getDump(),2).
                            arg(cinema.getUtilities().getWater(),2).
                            arg(cinema.getUtilities().getElectricity(),2).
                            arg(cinema.getBaseRecreation().getRecreation1(),1)),
                            this);
    cinemaAct->setStatusTip(tr("Creates new cinema"));
    connect(cinemaAct,SIGNAL(triggered()),this,SLOT(newCinema()));

    CFarm farm;
    farmAct = new QAction(QIcon(farmPixmapSource),
                          (QString("\bFarm\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4\nBase production: %5\nMax stacked food: %6").
                          arg(farm.getBuildCost(),1).
                          arg(farm.getUtilities().getDump(),2).
                          arg(farm.getUtilities().getWater(),2).
                          arg(farm.getUtilities().getElectricity(),2).
                          arg(farm.getMaxProductionPerTick().getFood(),2).
                          arg(farm.getMaxStackedProducts().getFood(),2)),
                          this);
    farmAct->setStatusTip(tr("Creates new farm"));
    connect(farmAct,SIGNAL(triggered()),this,SLOT(newFarm()));

    CLightFactory light;
    lightFactoryAct = new QAction(QIcon(lightPixmapSource),
                                  (QString("\bLight Industry Factory\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4\nBase production: %5\nMax stacked products: %6").
                                  arg(light.getBuildCost(),1).
                                  arg(light.getUtilities().getDump(),2).
                                  arg(light.getUtilities().getWater(),2).
                                  arg(light.getUtilities().getElectricity(),2).
                                  arg(light.getMaxProductionPerTick().getLight(),2).
                                  arg(light.getMaxStackedProducts().getLight(),2)),
                                  this);
    lightFactoryAct->setStatusTip(tr("Creates new Light Industry Factory"));
    connect(lightFactoryAct,SIGNAL(triggered()),this,SLOT(newLightFactory()));

    CHeavyFactory heavy;
    heavyFactoryAct = new QAction(QIcon(heavyPixmapSource),
                                  (QString("\bHeavy Industry Factory\nBuild cost: %1$\nUtilities: dump: %2,water: %3,electricity: %4\nBase production: %5\nMax stacked products: %6").
                                  arg(heavy.getBuildCost(),1).
                                  arg(heavy.getUtilities().getDump(),2).
                                  arg(heavy.getUtilities().getWater(),2).
                                  arg(heavy.getUtilities().getElectricity(),2).
                                  arg(heavy.getMaxProductionPerTick().getHeavy(),2).
                                  arg(heavy.getMaxStackedProducts().getHeavy(),2)),
                                  this);
    heavyFactoryAct->setStatusTip(tr("Creates new Heavy Industry Factory"));
    connect(heavyFactoryAct,SIGNAL(triggered()),this,SLOT(newHeavyFactory()));

    CPublicUtilityBuilding publicBuilding;
    publicUtilityBuildingAct = new QAction(QIcon(publicPixmapSource),
                                           (QString("\bPublic Resources Production Building\nBuild cost: %1$\nBuilding keep cost: %2$\nUtilities production: dump: %3,water: %4,electricity: %5").
                                           arg(publicBuilding.getBuildCost(),1).
                                           arg(publicBuilding.getCostPerTick(),1).
                                           arg(publicBuilding.getUtilities().getDump(),2).
                                           arg(publicBuilding.getUtilities().getWater(),2).
                                           arg(publicBuilding.getUtilities().getElectricity(),2)),
                                           this);
    publicUtilityBuildingAct->setStatusTip(tr("Creates new Public Utility Building"));
    connect(publicUtilityBuildingAct,SIGNAL(triggered()),this,SLOT(newPublicBuilding()));

    CRoadStraight straight;
    roadStraightAct = new QAction(QIcon(straightPixmapSource),
                                  (QString("\bStraight road\nBuild cost: %1$\nBuilding keep cost: %2$\nCapacity: %3").
                                   arg(straight.getBuildCost(),1).
                                   arg(straight.getCostPerTick(),1).
                                   arg(straight.getCapacity(),1)),
                                  this);
    roadStraightAct->setStatusTip(tr("Creates new Straight Road"));
    connect(roadStraightAct,SIGNAL(triggered()),this,SLOT(newRoadStraight())); 

    CRoadTurning turning;
    roadTurnAct = new QAction(QIcon(turningPixmapSource),
                              (QString("\bTurning road\nBuild cost: %1$\nBuilding keep cost: %2$\nCapacity: %3").
                               arg(turning.getBuildCost(),1).
                               arg(turning.getCostPerTick(),1).
                               arg(turning.getCapacity(),1)),
                              this);
    roadTurnAct->setStatusTip(tr("Creates new Turning"));
    connect(roadTurnAct,SIGNAL(triggered()),this,SLOT(newRoadTurn()));

    CRoadThreeWay threeway;
    roadThreeWayAct = new QAction(QIcon(threeWayPixmapSource),
                                  (QString("\bThreeway road\nBuild cost: %1$\nBuilding keep cost: %2$\nCapacity: %3").
                                   arg(threeway.getBuildCost(),1).
                                   arg(threeway.getCostPerTick(),1).
                                   arg(threeway.getCapacity(),1)),
                                  this);
    roadThreeWayAct->setStatusTip(tr("Creates new Threeway"));
    connect(roadThreeWayAct,SIGNAL(triggered()),this,SLOT(newRoadThreeway()));

    CRoadCross roadCross;
    roadCrossAct = new QAction(QIcon(crossPixmapSource),
                               (QString("\bCrossroad\nBuild cost: %1$\nBuilding keep cost: %2$\nCapacity: %3").
                                arg(roadCross.getBuildCost(),1).
                                arg(roadCross.getCostPerTick(),1).
                                arg(roadCross.getCapacity(),1)),
                               this);
    roadCrossAct->setStatusTip(tr("Creates new Crossroad"));
    connect(roadCrossAct,SIGNAL(triggered()),this,SLOT(newRoadCross()));

    buildingToolBar->addSeparator();
    buildingToolBar->addAction(lawnAct);
    buildingToolBar->addAction(parkAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(houseAct);
    buildingToolBar->addAction(blocksAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(schoolAct);
    buildingToolBar->addAction(shopAct);
    buildingToolBar->addAction(officeAct);
    buildingToolBar->addAction(cinemaAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(farmAct);
    buildingToolBar->addAction(lightFactoryAct);
    buildingToolBar->addAction(heavyFactoryAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(publicUtilityBuildingAct);
    buildingToolBar->addSeparator();
    buildingToolBar->addSeparator();
    buildingToolBar->addAction(roadStraightAct);    
    buildingToolBar->addAction(roadTurnAct);
    buildingToolBar->addAction(roadThreeWayAct);
    buildingToolBar->addAction(roadCrossAct);

    buildingToolBar->setIconSize(QSize(60,60));
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
{
    if(this->close())
    {   CStartingWindow* starting = new CStartingWindow;
        starting->show();}
}
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
void MainWindow::basePeopleEarningsChangedLead(int value)
{   city->getSocietyIndicators()->setBasePeopleEarningsLead(value);}
void MainWindow::basePeopleEarningsChangedService(int value)
{   city->getSocietyIndicators()->setBasePeopleEarningsService(value);}
void MainWindow::basePeopleEarningsChangedLight(int value)
{   city->getSocietyIndicators()->setBasePeopleEarningsLight(value);}
void MainWindow::MainWindow::basePeopleEarningsChangedHeavy(int value)
{   city->getSocietyIndicators()->setBasePeopleEarningsHeavy(value);}
void MainWindow::basePeopleEarningsChangedLow(int value)
{   city->getSocietyIndicators()->setBasePeopleEarningsLow(value);}
void MainWindow::baseProductsCostChangedFood(int value)
{   city->getMarket()->setBaseProductsCostFood(value);}
void MainWindow::baseProductsCostChangedLight(int value)
{   city->getMarket()->setBaseProductsCostLight(value);}
void MainWindow::baseProductsCostChangedHeavy(int value)
{   city->getMarket()->setBaseProductsCostHeavy(value);}

void MainWindow::canBeBuiledStructure(CStructure *structure)
{
    structure->setCity(city);
   // qDebug()<<"checking...";
    if(structure->checkIfCanBeBuiled())
    {   //model build
       // qDebug()<<structure->getCoordinatesOfActualLUCorner().getX();
        //CStructure *_newS = new CBlocks(*(dynamic_cast<CBlocks*>(structure)));
        CStructure* _newS = makeNewStructureProperly(structure);
        //qDebug()<<_newS->getCoordinatesOfActualLUCorner().getX();
        if(_newS!=NULL)
        {   //_newS->setCity(city);
           // _newS->setCoordinatesOfActualLUCorner(structure->getCoordinatesOfActualLUCorner());
            if(_newS->checkIfCanBeBuiled())
            {
            //_newS->setCoordinatesOfActualLUCorner(structure->getCoordinatesOfActualLUCorner());
           // _newS->setCity(city);
               // qDebug()<<"can be builed?";
                if(city->addStructureProperly(_newS))
                {   //qDebug()<<"building added";
                    _newS->build();
                    _newS->setRandomName(0);
                    money->setText(QString::number(city->getMoney())+" $");
                   // this->update();
                    //qDebug()<<" newS: "<<_newS->getCoordinatesOfActualLUCorner().getX()<<" "<<_newS->getCoordinatesOfActualLUCorner().getY();
                    statusBar()->showMessage("Builded.");
                    emit canBeBuiled(_newS,true);}
                else
                    statusBar()->showMessage("Cannot be builed.");}
        }
        else
            statusBar()->showMessage("Cannot be builed.");
    }
    else
        statusBar()->showMessage("Cannot be builed.");
}
CStructure* MainWindow::makeNewStructureProperly(CStructure *checking)
{
    CStructure* temp = NULL;
    if(dynamic_cast<CStructure*>(checking)==NULL)
        return temp;
    if(dynamic_cast<CHouse*>(checking)!=NULL)
    {   temp = new CHouse(*(dynamic_cast<CHouse*>(checking)));
        return temp;}
    if(dynamic_cast<CBlocks*>(checking)!=NULL)
    {  // qDebug()<<"blocks";
        temp = new CBlocks(*(dynamic_cast<CBlocks*>(checking)));return temp;}
    if(dynamic_cast<CLawn*>(checking)!=NULL)
    {   temp = new CLawn(*(dynamic_cast<CLawn*>(checking)));return temp;}
    if(dynamic_cast<CPark*>(checking)!=NULL)
    {   temp = new CPark(*(dynamic_cast<CPark*>(checking)));return temp;}
    if(dynamic_cast<COffice*>(checking)!=NULL)
    {   temp = new COffice(*(dynamic_cast<COffice*>(checking)));return temp;}
    if(dynamic_cast<CSmallShop*>(checking)!=NULL)
    {   temp = new CSmallShop(*(dynamic_cast<CSmallShop*>(checking)));return temp;}
    if(dynamic_cast<CSchoolAllInOne*>(checking)!=NULL)
    {   temp = new CSchoolAllInOne(*(dynamic_cast<CSchoolAllInOne*>(checking)));return temp;}
    if(dynamic_cast<CCinema*>(checking)!=NULL)
    {   temp = new CCinema(*(dynamic_cast<CCinema*>(checking)));return temp;}
    if(dynamic_cast<CFarm*>(checking)!=NULL)
    {   temp = new CFarm(*(dynamic_cast<CFarm*>(checking)));return temp;}
    if(dynamic_cast<CLightFactory*>(checking)!=NULL)
    {   temp = new CLightFactory(*(dynamic_cast<CLightFactory*>(checking)));return temp;}
    if(dynamic_cast<CHeavyFactory*>(checking)!=NULL)
    {   temp = new CHeavyFactory(*(dynamic_cast<CHeavyFactory*>(checking)));return temp;}
    if(dynamic_cast<CPublicUtilityBuildingAllInOne*>(checking)!=NULL)
    {   temp = new CPublicUtilityBuildingAllInOne(*(dynamic_cast<CPublicUtilityBuildingAllInOne*>(checking)));return temp;}
    if(dynamic_cast<CRoadCross*>(checking)!=NULL)
    {   temp = new CRoadCross(*(dynamic_cast<CRoadCross*>(checking)));return temp;}
    if(dynamic_cast<CRoadStraight*>(checking)!=NULL)
    {   temp = new CRoadStraight(*(dynamic_cast<CRoadStraight*>(checking)));return temp;}
    if(dynamic_cast<CRoadTurning*>(checking)!=NULL)
    {   temp = new CRoadTurning(*(dynamic_cast<CRoadTurning*>(checking)));return temp;}
    if(dynamic_cast<CRoadThreeWay*>(checking)!=NULL)
    {   temp = new CRoadThreeWay(*(dynamic_cast<CRoadThreeWay*>(checking)));return temp;}

    return temp;
}

void MainWindow::societyStatistics()
{
    //QDialog *societyWidget = new QDialog(dynamic_cast<QWidget*>(this));
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QToolBox *mainToolBox= new QToolBox(dynamic_cast<QWidget*>(this));
    mainLayout->addWidget(mainToolBox);
    int frameStyle = QFrame::Sunken | QFrame::Panel;

    //[1] people earnings
    QLabel *basePeopleEarningsLeadLabel = new QLabel(QString("Base lead worker earning [$]"));
    QSpinBox* basePeopleEarningsLead = new QSpinBox;
    basePeopleEarningsLead->setRange(0,10000);
    basePeopleEarningsLead->setSingleStep(10);
    basePeopleEarningsLead->setValue(city->getSocietyIndicators()->getBasePeopleEarnings().getLeadWorkerEarn());
    connect(basePeopleEarningsLead,SIGNAL(valueChanged(int)),this,SLOT(basePeopleEarningsChangedLead(int)));

    QLabel *basePeopleEarningsServiceLabel = new QLabel(QString("Base service worker earning [$]"));
    QSpinBox* basePeopleEarningsService = new QSpinBox(basePeopleEarningsLead);
    basePeopleEarningsService->setRange(0,10000);
    basePeopleEarningsService->setSingleStep(10);
    basePeopleEarningsService->setValue(city->getSocietyIndicators()->getBasePeopleEarnings().getServiceWorkerEarn());
    connect(basePeopleEarningsService,SIGNAL(valueChanged(int)),this,SLOT(basePeopleEarningsChangedService(int)));

    QLabel *basePeopleEarningsLightLabel = new QLabel(QString("Base Light worker earning [$]"));
    QSpinBox* basePeopleEarningsLight = new QSpinBox(basePeopleEarningsLead);
    basePeopleEarningsLight->setRange(0,10000);
    basePeopleEarningsLight->setSingleStep(10);
    basePeopleEarningsLight->setValue(city->getSocietyIndicators()->getBasePeopleEarnings().getLightWorkerEarn());
    connect(basePeopleEarningsLight,SIGNAL(valueChanged(int)),this,SLOT(basePeopleEarningsChangedLight(int)));

    QLabel *basePeopleEarningsHeavyLabel = new QLabel(QString("Base heavy worker earning [$]"));
    QSpinBox* basePeopleEarningsHeavy = new QSpinBox(basePeopleEarningsLead);
    basePeopleEarningsHeavy->setRange(0,10000);
    basePeopleEarningsHeavy->setSingleStep(10);
    basePeopleEarningsHeavy->setValue(city->getSocietyIndicators()->getBasePeopleEarnings().getHeavyWorkerEarn());
    connect(basePeopleEarningsHeavy,SIGNAL(valueChanged(int)),this,SLOT(basePeopleEarningsChangedHeavy(int)));

    QLabel *basePeopleEarningsLowLabel = new QLabel(QString("Base low worker earning [$]"));
    QSpinBox* basePeopleEarningsLow = new QSpinBox(basePeopleEarningsLead);
    basePeopleEarningsLow->setRange(0,10000);
    basePeopleEarningsLow->setSingleStep(10);
    basePeopleEarningsLow->setValue(city->getSocietyIndicators()->getBasePeopleEarnings().getLowWorkerEarn());
    connect(basePeopleEarningsLow,SIGNAL(valueChanged(int)),this,SLOT(basePeopleEarningsChangedLow(int)));

    //[1.1]
    QLabel *actualPeopleEarningsLeadLabel = new QLabel(QString("Actual lead worker earning [$]"));
    QSpinBox* actualPeopleEarningsLead = new QSpinBox;
    actualPeopleEarningsLead->setRange(0,10000);
    actualPeopleEarningsLead->setSingleStep(10);
    actualPeopleEarningsLead->setDisabled(true);
    actualPeopleEarningsLead->setValue(city->getSocietyIndicators()->getPeopleEarnings().getLeadWorkerEarn());

    QLabel *actualPeopleEarningsServiceLabel = new QLabel(QString("Actual service worker earning [$]"));
    QSpinBox* actualPeopleEarningsService = new QSpinBox(actualPeopleEarningsLead);
    actualPeopleEarningsService->setRange(0,10000);
    actualPeopleEarningsService->setSingleStep(10);
    actualPeopleEarningsService->setDisabled(true);
    actualPeopleEarningsService->setValue(city->getSocietyIndicators()->getPeopleEarnings().getServiceWorkerEarn());

    QLabel *actualPeopleEarningsLightLabel = new QLabel(QString("Actual Light worker earning [$]"));
    QSpinBox* actualPeopleEarningsLight = new QSpinBox(actualPeopleEarningsLead);
    actualPeopleEarningsLight->setRange(0,10000);
    actualPeopleEarningsLight->setSingleStep(10);
    actualPeopleEarningsLight->setDisabled(true);
    actualPeopleEarningsLight->setValue(city->getSocietyIndicators()->getPeopleEarnings().getLightWorkerEarn());

    QLabel *actualPeopleEarningsHeavyLabel = new QLabel(QString("Actual heavy worker earning [$]"));
    QSpinBox* actualPeopleEarningsHeavy = new QSpinBox(actualPeopleEarningsLead);
    actualPeopleEarningsHeavy->setRange(0,10000);
    actualPeopleEarningsHeavy->setSingleStep(10);
    actualPeopleEarningsHeavy->setDisabled(true);
    actualPeopleEarningsHeavy->setValue(city->getSocietyIndicators()->getPeopleEarnings().getHeavyWorkerEarn());

    QLabel *actualPeopleEarningsLowLabel = new QLabel(QString("Actual low worker earning [$]"));
    QSpinBox* actualPeopleEarningsLow = new QSpinBox(actualPeopleEarningsLead);
    actualPeopleEarningsLow->setRange(0,10000);
    actualPeopleEarningsLow->setSingleStep(10);
    actualPeopleEarningsLow->setDisabled(true);
    actualPeopleEarningsLow->setValue(city->getSocietyIndicators()->getPeopleEarnings().getLowWorkerEarn());

    QWidget* page1 = new QWidget;
    QGridLayout *baseEarningLayout = new QGridLayout(page1);
    baseEarningLayout->setColumnStretch(1,1);
    baseEarningLayout->addWidget(basePeopleEarningsLeadLabel,0,0);
    baseEarningLayout->addWidget(basePeopleEarningsLead,0,1);
    baseEarningLayout->addWidget(basePeopleEarningsServiceLabel,1,0);
    baseEarningLayout->addWidget(basePeopleEarningsService,1,1);
    baseEarningLayout->addWidget(basePeopleEarningsLightLabel,2,0);
    baseEarningLayout->addWidget(basePeopleEarningsLight,2,1);
    baseEarningLayout->addWidget(basePeopleEarningsHeavyLabel,3,0);
    baseEarningLayout->addWidget(basePeopleEarningsHeavy,3,1);
    baseEarningLayout->addWidget(basePeopleEarningsLowLabel,4,0);
    baseEarningLayout->addWidget(basePeopleEarningsLow,4,1);
    baseEarningLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),5,0);

    baseEarningLayout->addWidget(actualPeopleEarningsLeadLabel,6,0);
    baseEarningLayout->addWidget(actualPeopleEarningsLead,6,1);
    baseEarningLayout->addWidget(actualPeopleEarningsServiceLabel,7,0);
    baseEarningLayout->addWidget(actualPeopleEarningsService,7,1);
    baseEarningLayout->addWidget(actualPeopleEarningsLightLabel,8,0);
    baseEarningLayout->addWidget(actualPeopleEarningsLight,8,1);
    baseEarningLayout->addWidget(actualPeopleEarningsHeavyLabel,9,0);
    baseEarningLayout->addWidget(actualPeopleEarningsHeavy,9,1);
    baseEarningLayout->addWidget(actualPeopleEarningsLowLabel,10,0);
    baseEarningLayout->addWidget(actualPeopleEarningsLow,10,1);
    baseEarningLayout->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),11,0);
    mainToolBox->addItem(page1,QTranslator::tr("People earnings"));
    //[/1]
    //[2]
    QLabel* livingWorkingLead = new QLabel(QString("Living working lead workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingWorkingPeople().getLeadWorker(),2));
    livingWorkingLead->setFrameStyle(frameStyle);
    QLabel* livingWorkingService = new QLabel(QString("Living working service workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingWorkingPeople().getServiceWorker(),2));
    livingWorkingService->setFrameStyle(frameStyle);
    QLabel* livingWorkingLight = new QLabel(QString("Living working light workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingWorkingPeople().getLightWorker(),2));
    livingWorkingLight->setFrameStyle(frameStyle);
    QLabel* livingWorkingHeavy = new QLabel(QString("Living working heavy workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingWorkingPeople().getHeavyWorker(),2));
    livingWorkingHeavy->setFrameStyle(frameStyle);
    QLabel* livingWorkingLow = new QLabel(QString("Living working low workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingWorkingPeople().getLowWorker(),2));
    livingWorkingLow->setFrameStyle(frameStyle);

    QLabel* livingNotWorkingLead = new QLabel(QString("Living unemployed lead workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingNotWorkingPeople().getLeadWorker(),2));
    livingNotWorkingLead->setFrameStyle(frameStyle);
    QLabel* livingNotWorkingService = new QLabel(QString("Living unemployed service workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingNotWorkingPeople().getServiceWorker(),2));
    livingNotWorkingService->setFrameStyle(frameStyle);
    QLabel* livingNotWorkingLight = new QLabel(QString("Living unemployed light workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingNotWorkingPeople().getLightWorker(),2));
    livingNotWorkingLight->setFrameStyle(frameStyle);
    QLabel* livingNotWorkingHeavy = new QLabel(QString("Living unemployed heavy workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingNotWorkingPeople().getHeavyWorker(),2));
    livingNotWorkingHeavy->setFrameStyle(frameStyle);
    QLabel* livingNotWorkingLow = new QLabel(QString("Living unemployed low workers: %1").
                                           arg(city->getSocietyIndicators()->getallLivingNotWorkingPeople().getLowWorker(),2));
    livingNotWorkingLow->setFrameStyle(frameStyle);
    double bla = -1;
    if(city->getSocietyIndicators()->getAllPeople().getAllPeople()!=0)
        bla = city->getSocietyIndicators()->getallLivingNotWorkingPeople().getAllPeople()/city->getSocietyIndicators()->getAllPeople().getAllPeople();
    QLabel *unemployment = new QLabel(QString("Unemployed rate: %1").arg(bla,1,'f',2));
    unemployment->setFrameStyle(frameStyle);

    QWidget* page2 = new QWidget;
    QGridLayout *livingPeople = new QGridLayout(page2);
    livingPeople->setColumnStretch(1,1);
    livingPeople->addWidget(livingWorkingLead,0,0);
    livingPeople->addWidget(livingWorkingService,1,0);
    livingPeople->addWidget(livingWorkingLight,2,0);
    livingPeople->addWidget(livingWorkingHeavy,3,0);
    livingPeople->addWidget(livingWorkingLow,4,0);
    livingPeople->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),5,0);
    livingPeople->addWidget(livingNotWorkingLead,6,0);
    livingPeople->addWidget(livingNotWorkingService,7,0);
    livingPeople->addWidget(livingNotWorkingLight,8,0);
    livingPeople->addWidget(livingNotWorkingHeavy,9,0);
    livingPeople->addWidget(livingNotWorkingLow,10,0);
    livingPeople->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),11,0);
    livingPeople->addWidget(unemployment,12,0);
    mainToolBox->addItem(page2,QTranslator::tr("People employment"));
    //[/2]
    //[3]
    QLabel* allWorkLead = new QLabel(QString("All work for lead workers: %1").
                                           arg(city->getSocietyIndicators()->getAllWorkForPeople().getLeadWorker(),2));
    allWorkLead->setFrameStyle(frameStyle);
    QLabel* allWorkService = new QLabel(QString("All work for service workers: %1").
                                           arg(city->getSocietyIndicators()->getAllWorkForPeople().getServiceWorker(),2));
    allWorkService->setFrameStyle(frameStyle);
    QLabel* allWorkLight = new QLabel(QString("All work for light workers: %1").
                                           arg(city->getSocietyIndicators()->getAllWorkForPeople().getLightWorker(),2));
    allWorkLight->setFrameStyle(frameStyle);
    QLabel* allWorkHeavy = new QLabel(QString("All work for heavy workers: %1").
                                           arg(city->getSocietyIndicators()->getAllWorkForPeople().getHeavyWorker(),2));
    allWorkHeavy->setFrameStyle(frameStyle);
    QLabel* allWorkLow = new QLabel(QString("All work for low workers: %1").
                                           arg(city->getSocietyIndicators()->getAllWorkForPeople().getLowWorker(),2));
    allWorkLow->setFrameStyle(frameStyle);

    QWidget* page3 = new QWidget;
    QGridLayout *workForPeople = new QGridLayout(page3);
    workForPeople->setColumnStretch(1,1);
    workForPeople->addWidget(allWorkLead,0,0);
    workForPeople->addWidget(allWorkService,1,0);
    workForPeople->addWidget(allWorkLight,2,0);
    workForPeople->addWidget(allWorkHeavy,3,0);
    workForPeople->addWidget(allWorkLow,4,0);
    workForPeople->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),5,0);
    mainToolBox->addItem(page3,QTranslator::tr("All work for people"));
    //[/3]
    mainToolBox->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::Dialog);
    mainToolBox->show();
}
void MainWindow::market()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QToolBox *mainToolBox= new QToolBox(dynamic_cast<QWidget*>(this));
    mainLayout->addWidget(mainToolBox);
    int frameStyle = QFrame::Sunken | QFrame::Panel;
    Q_UNUSED(frameStyle);
    //[1]
    QLabel *baseProductsCostLabelFood = new QLabel(QString("Base food cost [$]"));
    QSpinBox* baseProductsCostFood = new QSpinBox;
    baseProductsCostFood->setRange(0,10000);
    baseProductsCostFood->setSingleStep(1);
    baseProductsCostFood->setValue(city->getMarket()->getBaseProductsCost().getFood());
    connect(baseProductsCostFood,SIGNAL(valueChanged(int)),this,SLOT(baseProductsCostChangedFood(int)));

    QLabel *baseProductsCostLabelLight = new QLabel(QString("Base light products cost [$]"));
    QSpinBox* baseProductsCostLight = new QSpinBox;
    baseProductsCostLight->setRange(0,10000);
    baseProductsCostLight->setSingleStep(1);
    baseProductsCostLight->setValue(city->getMarket()->getBaseProductsCost().getLight());
    connect(baseProductsCostLight,SIGNAL(valueChanged(int)),this,SLOT(baseProductsCostChangedLight(int)));

    QLabel *baseProductsCostLabelHeavy = new QLabel(QString("Base heavy products cost [$]"));
    QSpinBox* baseProductsCostHeavy = new QSpinBox;
    baseProductsCostHeavy->setRange(0,10000);
    baseProductsCostHeavy->setSingleStep(1);
    baseProductsCostHeavy->setValue(city->getMarket()->getBaseProductsCost().getHeavy());
    connect(baseProductsCostHeavy,SIGNAL(valueChanged(int)),this,SLOT(baseProductsCostChangedHeavy(int)));

    //[2]
    QLabel *actualProductsCostLabelFood = new QLabel(QString("Actual food cost [$]"));
    QSpinBox* actualProductsCostFood = new QSpinBox;
    actualProductsCostFood->setRange(0,10000);
    actualProductsCostFood->setSingleStep(1);
    actualProductsCostFood->setDisabled(true);
    actualProductsCostFood->setValue(city->getMarket()->getActualProductsCost().getFood());

    QLabel *actualProductsCostLabelLight = new QLabel(QString("Actual light products cost [$]"));
    QSpinBox* actualProductsCostLight = new QSpinBox;
    actualProductsCostLight->setRange(0,10000);
    actualProductsCostLight->setSingleStep(1);
    actualProductsCostLight->setDisabled(true);
    actualProductsCostLight->setValue(city->getMarket()->getActualProductsCost().getLight());

    QLabel *actualProductsCostLabelHeavy = new QLabel(QString("Actual heavy products cost [$]"));
    QSpinBox* actualProductsCostHeavy = new QSpinBox;
    actualProductsCostHeavy->setRange(0,10000);
    actualProductsCostHeavy->setDisabled(true);
    actualProductsCostHeavy->setSingleStep(1);
    actualProductsCostHeavy->setValue(city->getMarket()->getActualProductsCost().getHeavy());

    QWidget* page1 = new QWidget;
    QGridLayout *productsCost = new QGridLayout(page1);
    productsCost->setColumnStretch(1,1);
    productsCost->addWidget(baseProductsCostLabelFood,0,0);
    productsCost->addWidget(baseProductsCostFood,0,1);
    productsCost->addWidget(baseProductsCostLabelLight,1,0);
    productsCost->addWidget(baseProductsCostLight,1,1);
    productsCost->addWidget(baseProductsCostLabelHeavy,2,0);
    productsCost->addWidget(baseProductsCostHeavy,2,1);
    productsCost->addWidget(actualProductsCostLabelFood,3,0);
    productsCost->addWidget(actualProductsCostFood,3,1);
    productsCost->addWidget(actualProductsCostLabelLight,4,0);
    productsCost->addWidget(actualProductsCostLight,4,1);
    productsCost->addWidget(actualProductsCostLabelHeavy,5,0);
    productsCost->addWidget(actualProductsCostHeavy,5,1);
    productsCost->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),6,0);
    mainToolBox->addItem(page1,QTranslator::tr("Products cost"));
    //[/3]
    mainToolBox->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::Dialog);
    mainToolBox->show();
}
void MainWindow::publicUtility()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QToolBox *mainToolBox= new QToolBox(dynamic_cast<QWidget*>(this));
    mainLayout->addWidget(mainToolBox);
    int frameStyle = QFrame::Sunken | QFrame::Panel;

    QLabel *productionDump = new QLabel(QString("Dump service up to %1").arg(city->getUtilitiesGlobalProduction().getDump(),2));
    productionDump->setFrameStyle(frameStyle);
    QLabel *productionWater = new QLabel(QString("Water service up to %1").arg(city->getUtilitiesGlobalProduction().getWater(),2));
    productionWater->setFrameStyle(frameStyle);
    QLabel *productionElectricity = new QLabel(QString("Electricity service up to %1").arg(city->getUtilitiesGlobalProduction().getElectricity(),2));
    productionElectricity->setFrameStyle(frameStyle);
    QLabel *neededDump = new QLabel(QString("Dump service needed up %1").arg(city->getUtilitiesGlobalNeed().getDump(),2));
    neededDump->setFrameStyle(frameStyle);
    QLabel *neededWater = new QLabel(QString("Water service needed %1").arg(city->getUtilitiesGlobalNeed().getWater(),2));
    neededWater->setFrameStyle(frameStyle);
    QLabel *neededElectricity = new QLabel(QString("Electricity service needed %1").arg(city->getUtilitiesGlobalNeed().getElectricity(),2));
    neededElectricity->setFrameStyle(frameStyle);

    QWidget* page1 = new QWidget;
    QGridLayout *utilities = new QGridLayout(page1);
    utilities->setColumnStretch(1,1);
    utilities->addWidget(productionDump,0,0);
    utilities->addWidget(productionWater,1,0);
    utilities->addWidget(productionElectricity,2,0);
    utilities->addWidget(neededDump,3,0);
    utilities->addWidget(neededWater,4,0);
    utilities->addWidget(neededElectricity,5,0);
    utilities->addItem(new QSpacerItem(0,0,QSizePolicy::Ignored,QSizePolicy::MinimumExpanding),6,0);
    mainToolBox->addItem(page1,QTranslator::tr("Public utilities"));
    //[/3]
    mainToolBox->setWindowFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::Dialog);
    mainToolBox->show();
}
void MainWindow::destroy(CStructure * _structure)
{   //qDebug()<<"destroy";
    _structure->destroy();
    city->removeStructureProperly(_structure);}
void MainWindow::showInfo()
{}
void MainWindow::nextTurn()
{
    turnNumber++;
    city->makeTick();
    money->setText(QString::number(city->getMoney())+" $");
    turn->setText(tr("Turn number: ")+QString::number(turnNumber));
    NOPeople->setText(QString::number(city->getSocietyIndicators()->getAllPeople().getAllPeople()));
    income->setText(QString::number(city->getIncome())+" $/turn");
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
{   CHouse* house = new CHouse;
    emit newStructure(house);}
void MainWindow::newBlocks()
{   CBlocks * house = new CBlocks;
    emit newStructure(house);}
void MainWindow::newLawn()
{   CLawn * house = new CLawn;
    emit newStructure(house);}
void MainWindow::newPark()
{   CPark * house = new CPark;
    emit newStructure(house);}
void MainWindow::newOffice()
{   COffice * house = new COffice;
    emit newStructure(house);}
void MainWindow::newShop()
{   CSmallShop * house = new CSmallShop;
    emit newStructure(house);}
void MainWindow::newSchool()
{   CSchoolAllInOne * house = new CSchoolAllInOne;
    emit newStructure(house);}
void MainWindow::newCinema()
{   CCinema * house = new CCinema;
    emit newStructure(house);}
void MainWindow::newFarm()
{   CFarm * house = new CFarm;
    emit newStructure(house);}
void MainWindow::newLightFactory()
{   CLightFactory * house = new CLightFactory;
    emit newStructure(house);}
void MainWindow::newHeavyFactory()
{   CHeavyFactory * house = new CHeavyFactory;
    emit newStructure(house);}
void MainWindow::newPublicBuilding()
{   CPublicUtilityBuildingAllInOne * house = new CPublicUtilityBuildingAllInOne;
    emit newStructure(house);}
void MainWindow::newRoadStraight()
{   CRoadStraight * house = new CRoadStraight;
    emit newStructure(house);}
void MainWindow::newRoadCross()
{   CRoadCross * house = new CRoadCross;
    emit newStructure(house);}
void MainWindow::newRoadTurn()
{   CRoadTurning * house = new CRoadTurning;
    emit newStructure(house);}
void MainWindow::newRoadThreeway()
{   CRoadThreeWay* house = new CRoadThreeWay;
    emit newStructure(house);
}
