#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include "panelcontroller.h"
#include "synopticcontroller.h"

class MasterController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(SynopticController* synoptic_controller READ getSynopticController CONSTANT)
    Q_PROPERTY(PanelController* panel_controller READ getPanelController CONSTANT)
public:
    explicit MasterController(QObject *parent = nullptr);
    SynopticController* getSynopticController();
    PanelController* getPanelController();
    void connectPanelSynoptic();

signals:

private:
    class Implementation
    {
    public:
        Implementation(MasterController* _masterController)
            : masterController(_masterController)
        {
            synopticController = new SynopticController(masterController);
            panelController = new PanelController(masterController);
        }

        MasterController* masterController{nullptr};
        PanelController* panelController{nullptr};
        SynopticController* synopticController{nullptr};
    };

    QScopedPointer<Implementation> implementation;

};

#endif // MASTERCONTROLLER_H
