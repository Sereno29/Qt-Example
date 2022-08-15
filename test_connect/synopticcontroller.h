#ifndef SYNOPTICCONTROLLER_H
#define SYNOPTICCONTROLLER_H

#include <QObject>
#include <QList>
#include <QString>
#include "valve.h"

class SynopticController : public QObject
{
    Q_OBJECT
public:
    explicit SynopticController(QObject *parent = nullptr);
    QList<Valve*> getValves();
    Q_INVOKABLE Valve* getValveByIndex(int index);

signals:

private:
    class Implementation
    {
    public:
        Implementation(SynopticController* _synopticController)
            : synopticController(_synopticController)
        {
            // Initializing objects responsible for valves
            valves.append(new Valve(_synopticController, QString("FIRST"))); // 0
            valves.append(new Valve(_synopticController, QString("SECOND"))); // 1
        }

        SynopticController* synopticController{nullptr};
        QList<Valve*> valves{};
    };

    QScopedPointer<Implementation> implementation;

};

#endif // SYNOPTICCONTROLLER_H
