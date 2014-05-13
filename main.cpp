#include "mainwindow.h"
#include <QApplication>
#include "cstructure.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    CStructure structure;

    w.show();

    return a.exec();
}
