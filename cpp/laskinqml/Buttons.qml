import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Calculator 1.0

Rectangle {
    id: root
    property alias text: label.text
    signal clicked

    width: 116; height: 26
    color: "orange"
    border.color: "black"

    Text {
        id: label
        anchors.centerIn: parent
        text: "Start"
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
    Layout.fillWidth: true
    Layout.fillHeight: true
}

