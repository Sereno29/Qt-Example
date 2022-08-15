#ifndef VALVE_H
#define VALVE_H

#include <QObject>
#include <QDebug>
#include "componentstate.h"

class Valve : public ComponentState
{
    Q_OBJECT
    Q_PROPERTY(QString valve_name READ getValveName CONSTANT)
public:
    // Constructor
    explicit Valve(QObject *parent = nullptr, QString name = QString("VALVE"));

    // Getter
    QString getValveName();

public slots:
    void updateState(PneumaticState::Status);

private:
    QString valveName;
};

#endif // VALVE_H
