#include "idisplayinginterface.h"

IDisplayingInterface::IDisplayingInterface()
{
}
IDisplayingInterface:: ~IDisplayingInterface()
{}
QList<QString> IDisplayingInterface::infoToDisplay()
{   QList<QString> none;
    none.clear();
    none.append(QString("no info about"));
    return none;
}
void IDisplayingInterface::display(QList<QString> _toDisplay)
{   Q_UNUSED(_toDisplay);}
QPixmap IDisplayingInterface::findGraphicForBuilding(CStructure *_S)
{   Q_UNUSED(_S);
    return QPixmap(noImagePixmapSource);}
