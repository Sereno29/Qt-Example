#ifndef PUSHBUTTON_H
#define PUSHBUTTON_H

#include <QObject>
#include <QString>
#include <QDebug>
#include "componentstate.h"

class PushButton : public ComponentState
{
    Q_OBJECT
    Q_PROPERTY(QString push_button_name READ getPushButtonName CONSTANT)

public:
    // Constructor
    explicit PushButton(QObject *parent = nullptr, QString pushButtonName = QString("PushButton"));

    // Getter
    QString getPushButtonName();

protected:
    // Setter for Pneumatic State
    Q_INVOKABLE void setState(int state);

private:
    QString name;

};

#endif // PUSHBUTTON_H
