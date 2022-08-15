#include "pushbutton.h"

// Constructor
PushButton::PushButton(QObject *parent, QString name):name(name)
{
    this->isFailed = this->failureState == PneumaticState::FAILED;
    this->isActive = this->state == PneumaticState::ACTIVE;
}

// Getter
QString PushButton::getPushButtonName(){
    return name;
}

void PushButton::setState(int state){
    qDebug() << Q_FUNC_INFO;
    PneumaticState::Status st = static_cast<PneumaticState::Status>(state);
    qDebug() << "Current state: " << this->state;
    qDebug() << "Next state: " << st;
    qDebug() << "Is active: " << this->isActive;
    if(this->state != st){
        this->state = st;
        this->isActive = this->state == PneumaticState::ACTIVE;
        emit stateColorChanged(st);
        emit stateChanged();
    }
}
