#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "pneumaticstate.h"
#include "componentstate.h"
#include "pushbutton.h"
#include "valve.h"
#include "panelcontroller.h"
#include "synopticcontroller.h"
#include "mastercontroller.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");

    // Registering types in QML
    qmlRegisterUncreatableType<PneumaticState>("Enum", 1, 0, "PneumaticState", "Access to Pneumatic State enum");
    qmlRegisterType<ComponentState>("Avionics", 1, 0, "ComponentState");
    qRegisterMetaType<PushButton*>("PushButton*");
    qmlRegisterType<PushButton>("PushButton", 1, 0, "PushButton");
    qRegisterMetaType<Valve*>("Valve*");
    qmlRegisterType<Valve>("Synoptic", 1, 0, "Valve");
    qRegisterMetaType<PanelController*>("PanelController*");
    qmlRegisterType<PanelController>("Controller", 1, 0, "PanelController");
    qRegisterMetaType<SynopticController*>("SynopticController*");
    qmlRegisterType<SynopticController>("Controller", 1, 0, "SynopticController");
    qmlRegisterType<MasterController>("Controller", 1, 0, "MasterController");

    // Main class
    MasterController masterController;

    // Connecting push button to valve outside of master controller
    Valve valveTest(nullptr, QString("THIRD_VALVE"));
    PushButton pushButtonTest(nullptr, QString("THIRD_PUSH_BUTTON"));
    Valve *valvePtr = &valveTest;
    PushButton *pushButtonPtr = &pushButtonTest;

    QObject::connect(pushButtonPtr, &PushButton::stateColorChanged, valvePtr, &Valve::updateState);

    engine.rootContext()->setContextProperty("masterController", &masterController);
    engine.rootContext()->setContextProperty("valve", valvePtr);
    engine.rootContext()->setContextProperty("pushButton", pushButtonPtr);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
