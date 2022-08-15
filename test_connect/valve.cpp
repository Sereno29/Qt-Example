#include "valve.h"

Valve::Valve(QObject *parent, QString name):valveName(name)
{
}

QString Valve::getValveName(){
    return valveName;
}

// Setter which emits a signal
void Valve::updateState(PneumaticState::Status state){
    qDebug() << Q_FUNC_INFO;
    if(this->state != state){
        this->state = state;
        this->isActive = this->state == PneumaticState::ACTIVE;
        this->isFailed = !this->isActive;
        emit stateColorChanged(state);
        emit stateChanged();
    }
}
