#include "synopticcontroller.h"

//Constructor
SynopticController::SynopticController(QObject *parent) : QObject(parent){
    implementation.reset(new Implementation(this));
}

QList<Valve*> SynopticController::getValves(){
    return implementation->valves;
}

Valve* SynopticController::getValveByIndex(int index){
    return implementation->valves.at(index);
}
