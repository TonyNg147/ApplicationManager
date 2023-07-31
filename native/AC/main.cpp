#include <QGuiApplication>
#include <HMIController.h>
#include <ViewDefines.h>
#include <QtAppManCommon/logging.h>
#include <QtAppManLauncher/launchermain.h>
#include <QtAppManLauncher/dbusapplicationinterface.h>
#include <QtAppManLauncher/dbusnotification.h>
int main(int argc, char** argv){
    QtAM::Logging::initialize(argc, argv);
    QtAM::Logging::setApplicationId("AC");
    qDebug()<<__LINE__;
    QtAM::LauncherMain::initialize();
    QGuiApplication app(argc,argv);
    QtAM::LauncherMain launcher;

    launcher.registerWaylandExtensions();
    launcher.loadConfiguration();
    launcher.setupLogging(false, launcher.loggingRules(), QString(), launcher.useAMConsoleLogger());
    launcher.setupDBusConnections();
    
    qmlRegisterType<ViewEnums>("HMIEvent",1,0,"HMIEvent");
    HMIController::registerState(SYSTEM_ALL_STATE, size(SYSTEM_ALL_STATE));
    HMIController::getInstance();
    HMIController::getInstance().changeScreen(ViewEnums::TO_A);
    HMIController::getInstance().show();
    QtAM::DBusApplicationInterface iface(launcher.p2pDBusName(), launcher.notificationDBusName());
    iface.initialize();
    QObject::connect(&iface, &QtAM::DBusApplicationInterface::quit, [&iface] () {
        iface.acknowledgeQuit();
    });
    return app.exec();
};