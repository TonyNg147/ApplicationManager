#ifndef SCREEN_MANAGER_H
#define SCREEN_MANAGER_H
#include <ViewStructs.h>
#include <QQmlContext>
#include <QQmlEngine>
class ScreenManagerPrivate; 
class ScreenManager{
    private:
        ScreenManager();
    public:
        static ScreenManager& getInstance();
        ~ScreenManager();
        static void init(QQmlEngine* rootEngine,QQmlContext* rootContext);
        void showScreen(const State& state);
    private:    
        ScreenManagerPrivate*   mPrivateController = nullptr;


};
#endif //SCREEN_MANAGER_H