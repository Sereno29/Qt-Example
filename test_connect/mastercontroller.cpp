#include "mastercontroller.h"
#include <iostream>

// Constructor
MasterController::MasterController(QObject *parent) : QObject(parent)
{
    implementation.reset(new Implementation(this));
    connectPanelSynoptic();
}

//Getters
SynopticController* MasterController::getSynopticController(){
    return implementation->synopticController;
}

PanelController* MasterController::getPanelController(){
    return implementation->panelController;
}

void MasterController::connectPanelSynoptic(){
    bool connection = QObject::connect(implementation->panelController->getPushButtons().at(0), &PushButton::stateColorChanged, implementation->synopticController->getValves().at(0), &Valve::Valve::updateState);
    Q_ASSERT(connection);
}
