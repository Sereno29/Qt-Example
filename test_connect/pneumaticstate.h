#ifndef PNEUMATICSTATE_H
#define PNEUMATICSTATE_H

#include <QObject>

class PneumaticState
{
    Q_GADGET

public:

    explicit PneumaticState();

    enum Status{
        ACTIVE,
        INACTIVE
    };

    enum FailureStatus{
        NOT_FAILED,
        FAILED
    };

    Q_ENUM(FailureStatus);

    Q_ENUM(Status);
};

#endif // PNEUMATICSTATE_H
