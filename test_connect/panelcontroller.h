#ifndef PANELCONTROLLER_H
#define PANELCONTROLLER_H

#include <QObject>
#include <QList>
#include <QString>
#include "pushbutton.h"

class PanelController : public QObject
{
    Q_OBJECT
public:
    explicit PanelController(QObject *parent = nullptr);
    QList<PushButton*> getPushButtons();
    Q_INVOKABLE PushButton* getPushButtonByIndex(int index);

signals:

private:
    class Implementation
    {
    public:
        Implementation(PanelController* _panelController)
            : panelController(_panelController)
        {
            // Initializing objects responsible for push buttons
            pushButtons.append(new PushButton(_panelController, QString("FIRST_PUSH_BUTTON"))); // 0
            pushButtons.append(new PushButton(_panelController, QString("SECOND_PUSH_BUTTON"))); // 1
        }

        PanelController* panelController{nullptr};
        QList<PushButton*> pushButtons{};
    };

    QScopedPointer<Implementation> implementation;

};

#endif // PANELCONTROLLER_H
