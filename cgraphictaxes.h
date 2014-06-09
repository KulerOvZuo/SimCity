#ifndef CGRAPHICTAXES_H
#define CGRAPHICTAXES_H

#include <QtWidgets>
#include <QLabel>
#include <QSlider>
#include <QLineEdit>
#include <QCloseEvent>

class CGraphicTaxes : public QDialog
{
    Q_OBJECT
public:
    explicit CGraphicTaxes(QWidget *parent = 0);

    int getFromProductionInd() const {return fromProductionInd;}
    int getFromPeopleInd()const {return fromPeopleInd;}
    int getFromOthersInd()const {return fromOthersInd;}
    void setValues(int _prod, int _people, int _others);

protected:
    int fromProductionInd;
    int fromPeopleInd;
    int fromOthersInd;

    QVBoxLayout *mainLayout;
    QLabel *fromProductionIndText;
    QLabel *fromPeopleIndText;
    QLabel *fromOthersIndText;
    QSlider *sliderFromProd;
    QSlider *sliderFromPeople;
    QSlider *sliderFromOthers;
    QLineEdit *editFromProd;
    QLineEdit *editFromPeople;
    QLineEdit *editFromOthers;
    QPushButton *OK;

    void connectSignalsSlots();

signals:
    void valueChanged(int _value);
    void taxesChanged();
    void taxesRead();

public slots:
    void show();
private slots:
    void fromProductionIndChanged(int);
    void fromPeopleIndChanged(int);
    void fromOthersIndChanged(int);
    void sendInfo();
};

#endif // CGRAPHICTAXES_H
