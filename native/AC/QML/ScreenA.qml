import QtQuick
import HMIEvent 1.0
Rectangle{
    Component.onCompleted: console.log("Created herere")
    Component.onDestruction: console.log("destruct herere")
    width: 600
    height: 600
    color: "green"
    Text{
        anchors.centerIn: parent
        text: "ScreenA"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            HMIController.changeScreen(HMIEvent.TO_B)
        }
    }
}