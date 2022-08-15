#include "componentstate.h"

ComponentState::ComponentState(QObject *parent) : QObject(parent)
{

}

bool ComponentState::getIsFailed(){
    return this->isFailed;
}

bool ComponentState::getIsActive(){
    return this->isActive;
}

PneumaticState::Status ComponentState::getState() {
    return state;
}

PneumaticState::FailureStatus ComponentState::getFailureState(){
    return failureState;
}
