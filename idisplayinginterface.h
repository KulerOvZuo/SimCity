#ifndef IDISPLAYINGINTERFACE_H
#define IDISPLAYINGINTERFACE_H

#include <QList>
#include <QString>
class IDisplayingInterface
{
public:
    IDisplayingInterface();
    virtual ~IDisplayingInterface();

    virtual QList<QString> infoToDisplay();
    virtual void display(QList<QString> _toDisplay);
};

#endif // IDISPLAYINGINTERFACE_H
