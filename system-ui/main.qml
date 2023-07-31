import QtQuick 2.11
import QtQuick.Window 2.11
import QtApplicationManager.SystemUI 2.0
Window{
    visible: true
    width: 1280
    height: 800
    color: "transparent"
    Component.onCompleted: {
        console.log("herere")
        ApplicationManager.startApplication("AC")
    }
    ListModel{
        id: applicationModels
    }
    ListView{
        id: listView
        width: 1000
        height: 600
        x: 100
        y: 80
        model: applicationModels
        delegate: Item{
            width: 330
            height: 600
            WindowItem{
                anchors.fill: parent
                window: model.window
            }
            Text{
                anchors.centerIn: parent
                text: model.appId
            }
        }
    }

    Connections {
        target: WindowManager
        function onWindowAdded(window) {
            console.log("herree 22132123")
            applicationModels.append({"window": window, "appId": window.application.id})
        }
    }
    Connections {
        target: ApplicationManager
        function onApplicationRunStateChanged(id, runState) {
            console.log("hererereer 12 " + id)
            if (runState === Am.NotRunning
                && ApplicationManager.application(id).lastExitStatus === Am.CrashExit) {
                ApplicationManager.startApplication(id);
            }
        }
    }
}