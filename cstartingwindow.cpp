#include "cstartingwindow.h"

CStartingWindow::CStartingWindow(QWidget *parent) :
    QWidget(parent)
{
    mainLayout = new QVBoxLayout(this);

    QHBoxLayout *first = new QHBoxLayout;
    QLabel* nameLabel = new QLabel(this);
    nameLabel->setText(QString("Enter your name: "));
    userName = new QLineEdit(this);
    userName->setText(QString("The Lord Of The PJC"));
    userName->setMaxLength(20);

    first->addWidget(nameLabel);
    first->addWidget(userName);

    QHBoxLayout *second = new QHBoxLayout;
    QLabel* mapSizeXLabel = new QLabel(this);
    mapSizeXLabel->setText(QString("Map size X:"));
    mapSizeX = new QSpinBox(this);
    mapSizeX->setSingleStep(1);
    mapSizeX->setMinimum(5);
    mapSizeX->setValue(45);

    second->addWidget(mapSizeXLabel);
    second->addWidget(mapSizeX);

    QHBoxLayout *third = new QHBoxLayout;
    QLabel* mapSizeYLabel = new QLabel(this);
    mapSizeYLabel->setText(QString("Map size Y:"));
    mapSizeY= new QSpinBox(this);
    mapSizeY->setSingleStep(1);
    mapSizeY->setMinimum(5);
    mapSizeY->setValue(30);

    third->addWidget(mapSizeYLabel);
    third->addWidget(mapSizeY);

    QHBoxLayout *fourth = new QHBoxLayout;
    QLabel* tileSizeXLabel = new QLabel(this);
    tileSizeXLabel->setText(QString("Tile size X[px]:"));
    tileSizeX= new QSpinBox(this);
    tileSizeX->setSingleStep(5);
    tileSizeX->setMinimum(10);
    tileSizeX->setValue(40);

    fourth->addWidget(tileSizeXLabel);
    fourth->addWidget(tileSizeX);

    QHBoxLayout *fifth = new QHBoxLayout;
    QLabel* tileSizeYLabel = new QLabel(this);
    tileSizeYLabel->setText(QString("Tile size Y[px]:"));;
    tileSizeY= new QSpinBox(this);
    tileSizeY->setSingleStep(5);
    tileSizeY->setMinimum(10);
    tileSizeY->setValue(40);

    fifth->addWidget(tileSizeYLabel);
    fifth->addWidget(tileSizeY);

    OK = new QPushButton(this);
    OK->setText(QString("Start game!"));
    connect(OK,SIGNAL(clicked()),this,SLOT(initializeNewGame()));

    mainLayout->addLayout(first);
    mainLayout->addLayout(second);
    mainLayout->addLayout(third);
    mainLayout->addLayout(fourth);
    mainLayout->addLayout(fifth);
    mainLayout->addWidget(OK);

    this->setLayout(mainLayout);
    this->setWindowFlags(Qt::WindowCloseButtonHint);
}
void CStartingWindow::initializeNewGame()
{
    MainWindow *mainWindowGame = new MainWindow(userName->text(),
                                                QSize(mapSizeX->value(),mapSizeY->value()),
                                                QSize(tileSizeX->value(),tileSizeY->value()));
    mainWindowGame->show();
    this->close();
}
