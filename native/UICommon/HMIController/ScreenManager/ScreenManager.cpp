#include "ScreenManager.h"
#include <memory>
#include <QVector>
#include <QQmlComponent>
typedef std::shared_ptr<QQmlComponent> SharedQmlComponent;
class ScreenManagerPrivate{
    friend class ScreenManager;
    private:
        bool isExist(const State& state);
        SharedQmlComponent makeScreenComponent(const State& state);
        void applyNewScreen(const SharedQmlComponent& component);
        SharedQmlComponent findComponent(const State& state);
        static QQmlContext *gRootContext;
        static QQmlEngine  *gRootEngine;
        QVector<SharedQmlComponent> mComponents;
        QVector<State>              mScreenStates;
};
QQmlContext *ScreenManagerPrivate::gRootContext = nullptr;
QQmlEngine  *ScreenManagerPrivate::gRootEngine  = nullptr;
ScreenManager& ScreenManager::getInstance(){
    static ScreenManager instance;
    return instance;
}

ScreenManager::ScreenManager(){
    mPrivateController = new ScreenManagerPrivate();
}
ScreenManager::~ScreenManager(){
    delete mPrivateController;
}
void ScreenManager::init(QQmlEngine* rootEngine,QQmlContext* rootContext){
    if (rootContext && rootEngine){
        ScreenManagerPrivate::gRootContext = rootContext;
        ScreenManagerPrivate::gRootEngine  = rootEngine;
    }else{
        // do-sth
    }
}

void ScreenManager::showScreen(const State& state){
    SharedQmlComponent component;
    if (mPrivateController->isExist(state)){
        qDebug()<<__LINE__;
        component = mPrivateController->findComponent(state);
        
    }else{
        component = mPrivateController->makeScreenComponent(state);
    }
    if (component){
        mPrivateController->applyNewScreen(component);
    }else{
        // error
    }
}


// Screen Private

bool ScreenManagerPrivate::isExist(const State& state){
    bool isExist = false;
    for (auto& screenState: mScreenStates){
        if (screenState.state == state.state){
            isExist = true;
            break; 
        }
    }
    return isExist;
}

SharedQmlComponent ScreenManagerPrivate::makeScreenComponent(const State& state){
    SharedQmlComponent component = std::make_shared<QQmlComponent>(gRootEngine,state.filePath);
    mComponents.push_back(component);
    return component;
}

void ScreenManagerPrivate::applyNewScreen(const SharedQmlComponent& component){
    gRootContext->setContextProperty("HMIComponent",nullptr);
    gRootContext->setContextProperty("HMIComponent",QVariant::fromValue(component.get()));
}

SharedQmlComponent ScreenManagerPrivate::findComponent(const State& state){
    bool   isValid = false;
    qsizetype index   = 0;
    for (qsizetype idx = 0; idx < mScreenStates.size() ; ++idx){
        if (mScreenStates[idx].state == state.state){
            index = idx;
            isValid = true;
            break;
        }
        
    }
    if (isValid){
        if (index < mComponents.size()){
            return mComponents[index];
        }
    }
    return SharedQmlComponent();
}