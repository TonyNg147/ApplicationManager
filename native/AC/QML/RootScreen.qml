import QtQuick
Item{
    width: 1280
    height: 720
    Loader{
        anchors.centerIn: parent
        sourceComponent: HMIComponent
    }
}