import QtQuick
import HMIEvent 1.0
Rectangle{
    width: 600
    height: 600
    color: "blue"
    Text{
        anchors.centerIn: parent
        text: "ScreenB"
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            HMIController.changeScreen(HMIEvent.TO_A)
        }
    }
}