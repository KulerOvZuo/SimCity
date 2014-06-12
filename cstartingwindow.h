#ifndef CSTARTINGWINDOW_H
#define CSTARTINGWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QAction>
#include <QLineEdit>
#include <QSpinBox>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QCloseEvent>
#include "mainwindow.h"

class CStartingWindow : public QWidget
{
    Q_OBJECT
private:
    QVBoxLayout* mainLayout;
    QLineEdit *userName;
    QSpinBox* mapSizeX;
    QSpinBox* mapSizeY;
    QSpinBox* tileSizeX;
    QSpinBox* tileSizeY;
    QPushButton* OK;
public:
    explicit CStartingWindow(QWidget *parent = 0);
signals:
public slots:
    void initializeNewGame();
};

#endif // CSTARTINGWINDOW_H
