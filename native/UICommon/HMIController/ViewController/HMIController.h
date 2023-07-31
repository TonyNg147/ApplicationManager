#ifndef HMI_CONTROLLER_H
#define HMI_CONTROLLER_H
#include <QObject>
#include <QMap>
#include <QQuickView>
#include <QQmlContext>
#include <QQmlEngine>
#include <ViewStructs.h>
typedef QMap<uint16_t,State> Event_Register;
class HMIController: public QObject{
    Q_OBJECT
    private:
        HMIController(QObject* parent = nullptr);
    public:
        static HMIController& getInstance();
        static void registerState(SystemState*, qsizetype);
        void show(){
            mView->show();
        }
    public slots:
        void changeScreen(uint16_t event);
    private:
        static Event_Register mEvents;
        QQuickView*    mView = nullptr;
        QQmlEngine*    mEngine = nullptr;
        QQmlContext*    mContext = nullptr;
        
};
#endif //HMI_CONTROLLER_H