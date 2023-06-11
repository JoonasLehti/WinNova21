import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import Calculator 1.0

ApplicationWindow {
    visible: true
    width: 480
    height: 640
    title: "Calculator"

    Drawer {
        id: drawer
        width: parent.width / 2
        height: parent.height
        modal: true

        contentItem: ColumnLayout {
            anchors.fill: parent
            spacing: 5

            Label {
                text: "Drawer Content"
                font.bold: true
            }
            Item {
                Layout.fillHeight: true
            }
            Label {
                text: "Copyright:"
                font.pixelSize: 50
                font.bold: true
                Layout.fillWidth: true
                wrapMode: Text.Wrap
            }
            Label {
                text: "This is the legal copyright information for this project, please do not steal or redistribute this application"
                font.pixelSize: 35
                font.bold: false
                Layout.fillWidth: true
                wrapMode: Text.Wrap
            }
        }
    }

    Calculator {
        id: calculator
        onDisplayChanged: {
            inputBox2.text = calculator.display;
        }
    }

    TextField {
        anchors {
            top: parent.top
            left: parent.left
            right: parent.right
        }
        height: parent.height * 0.1
        id: inputBox2
        text: calculator.display
    }

    Buttons {
        anchors {
            top: inputBox2.bottom
            left: parent.left
            right: parent.right
            bottom: parent.bottom
        }
    }
}
