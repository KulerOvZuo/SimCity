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

/**
 * @brief Klasa CStartingWindow (okno startowe)
 *
 *Klasa implementująca okno początkowe gry, pozwalajace na wybranie imienia gracza, wymiarów mapy i żetonów.
 */
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
    /**
     * @brief Inicjalizuj nową grę
     *
     *Funkcja powoduje zainicjalizowanie nowej gry podanymi przez użytkownika parametrami, a następnie zamyka to okno i otwiera okno gry właściwej.
     */
    void initializeNewGame();
};

#endif // CSTARTINGWINDOW_H
