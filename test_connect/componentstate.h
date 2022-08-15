#ifndef COMPONENTSTATE_H
#define COMPONENTSTATE_H

#include "pneumaticstate.h"
#include <QObject>

class ComponentState : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool is_failed READ getIsFailed NOTIFY stateChanged)
    Q_PROPERTY(bool is_active READ getIsActive NOTIFY stateChanged)
public:
    explicit ComponentState(QObject *parent = nullptr);

    // Getter member
    bool getIsFailed();
    bool getIsActive();
    PneumaticState::Status getState();
    PneumaticState::FailureStatus getFailureState();

signals:
    void stateColorChanged(PneumaticState::Status);
    void stateChanged();


protected:
    PneumaticState::Status state = PneumaticState::INACTIVE; // Default value
    PneumaticState::FailureStatus failureState = PneumaticState::NOT_FAILED; // Default value
    bool isFailed = this->failureState == PneumaticState::FAILED; // Default value
    bool isActive = this->state == PneumaticState::ACTIVE; // Default value
};

#endif // COMPONENTSTATE_H
