#include "panelcontroller.h"

PanelController::PanelController(QObject *parent) : QObject(parent)
{
    implementation.reset(new Implementation(this));
}

QList<PushButton*> PanelController::getPushButtons(){
    return implementation->pushButtons;
}

PushButton* PanelController::getPushButtonByIndex(int index){
    return implementation->pushButtons.at(index);
}
