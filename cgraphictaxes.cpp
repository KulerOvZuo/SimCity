#include "cgraphictaxes.h"
#include <QLayout>
#include <QPalette>
#include <QDebug>

CGraphicTaxes::CGraphicTaxes(QWidget *parent) :
    QDialog(parent)
{
    sliderFromProd = new QSlider(Qt::Horizontal,this);
    sliderFromProd->setFocusPolicy(Qt::StrongFocus);
    sliderFromProd->setTickInterval(10);
    sliderFromProd->setFixedWidth(200);
    sliderFromProd->setMinimum(0);
    sliderFromProd->setMaximum(100);
    sliderFromProd->setTickPosition(QSlider::TicksBothSides);
    sliderFromProd->setSingleStep(1);

    sliderFromPeople = new QSlider(Qt::Horizontal,this);
    sliderFromPeople->setFocusPolicy(Qt::StrongFocus);
    sliderFromPeople->setTickInterval(10);
    sliderFromPeople->setFixedWidth(200);
    sliderFromPeople->setMinimum(0);
    sliderFromPeople->setMaximum(100);
    sliderFromPeople->setTickPosition(QSlider::TicksBothSides);
    sliderFromPeople->setSingleStep(1);

    sliderFromOthers = new QSlider(Qt::Horizontal,this);
    sliderFromOthers->setFocusPolicy(Qt::StrongFocus);
    sliderFromOthers->setTickInterval(10);
    sliderFromOthers->setFixedWidth(200);
    sliderFromOthers->setMinimum(0);
    sliderFromOthers->setMaximum(100);
    sliderFromOthers->setTickPosition(QSlider::TicksBothSides);
    sliderFromOthers->setSingleStep(1);

    fromProductionIndText = new QLabel(tr("Taxes from production"),this);
    fromProductionIndText->setFixedWidth(130);
    fromPeopleIndText = new QLabel(tr("Taxes from people"),this);
    fromPeopleIndText->setFixedWidth(130);
    fromOthersIndText = new QLabel(tr("Taxes from others"),this);
    fromOthersIndText->setFixedWidth(130);

    editFromProd = new QLineEdit(this);
    editFromProd->setDisabled(true);
    editFromPeople = new QLineEdit(this);
    editFromPeople->setDisabled(true);
    editFromOthers = new QLineEdit(this);
    editFromOthers->setDisabled(true);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    QHBoxLayout *first = new QHBoxLayout(this);
        first->addWidget(fromProductionIndText);
        first->addWidget(sliderFromProd);
        first->addWidget(editFromProd);
    QHBoxLayout *second = new QHBoxLayout(this);
        second->addWidget(fromPeopleIndText);
        second->addWidget(sliderFromPeople);
        second->addWidget(editFromPeople);
    QHBoxLayout *third = new QHBoxLayout(this);
        third->addWidget(fromOthersIndText);
        third->addWidget(sliderFromOthers);
        third->addWidget(editFromOthers);

    OK = new QPushButton(this);
    OK->setText(tr("OK"));

    mainLayout->addLayout(first);
    mainLayout->addLayout(second);
    mainLayout->addLayout(third);
    mainLayout->addWidget(OK);
    this->setFixedSize(430,180);

    connectSignalsSlots();
    setValues(0,0,0);
    QPalette pal(palette());
    pal.setColor(QPalette::Background,QColor(230,200,167));
    this->setAutoFillBackground(true);
    this->setPalette(pal);

    this->setLayout(mainLayout);
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

void CGraphicTaxes::connectSignalsSlots()
{
    connect(sliderFromProd,SIGNAL(valueChanged(int)),this,SLOT(fromProductionIndChanged(int)));
    connect(sliderFromPeople,SIGNAL(valueChanged(int)),this,SLOT(fromPeopleIndChanged(int)));
    connect(sliderFromOthers,SIGNAL(valueChanged(int)),this,SLOT(fromOthersIndChanged(int)));
    connect(OK,SIGNAL(clicked()),this,SLOT(sendInfo()));
}
void CGraphicTaxes::setValues(int _prod, int _people, int _others)
{
    sliderFromProd->setValue(1);
    sliderFromPeople->setValue(1);
    sliderFromOthers->setValue(1);
    ///for change
    sliderFromProd->setValue(_prod);
    sliderFromPeople->setValue(_people);
    sliderFromOthers->setValue(_others);
    update();
}

void CGraphicTaxes::fromProductionIndChanged(int _value)
{   this->fromProductionInd = _value;
    this->editFromProd->setText(QString::number(_value)+"%");}
void CGraphicTaxes::fromPeopleIndChanged(int _value)
{
    this->fromPeopleInd = _value;
    this->editFromPeople->setText(QString::number(_value)+"%");}
void CGraphicTaxes::fromOthersIndChanged(int _value)
{
    this->fromOthersInd = _value;
    this->editFromOthers->setText(QString::number(_value)+"%");}
void CGraphicTaxes::sendInfo()
{   emit this->taxesChanged();
    this->close();
}

void CGraphicTaxes::show()
{   emit this->taxesRead();
    QWidget::show();
}
