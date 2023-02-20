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

    Control {
        padding: 10
}
    ColumnLayout {
        anchors.fill: parent
        spacing: 5
        ColumnLayout {
            Layout.alignment: Qt.AlignHCenter
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5
                TextField {
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter | Qt.AlignVCenter
                    id: inputBox2
                    text: calculator.display
                }
            }
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter
                text: "Backspace"
                onClicked: calculator.backspaceClicked()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter
                text: "Clear"
                onClicked: calculator.clear()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter
                text: "Clear All"
                onClicked: calculator.clearAll()
            }
        }
    }
        ColumnLayout{
        Layout.alignment: Qt.AlignHCenter
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter
                text: "MC"
                onClicked: calculator.clearMemory()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "7"
                onClicked: calculator.digitClicked("7")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "8"
                onClicked: calculator.digitClicked("8")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "9"
                onClicked: calculator.digitClicked("9")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "/"
                onClicked: calculator.multiplicativeOperatorClicked(Calculator.Division)
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "Sqrt"
                onClicked: calculator.unaryOperatorClicked(Calculator.SquareRoot)
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "MR"
                onClicked: calculator.readMemory()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "4"
                onClicked: calculator.digitClicked("4")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "5"
                onClicked: calculator.digitClicked("5")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "6"
                onClicked: calculator.digitClicked("6")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "*"
                onClicked: calculator.multiplicativeOperatorClicked(Calculator.Multiplication)
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "X2"
                onClicked: calculator.unaryOperatorClicked(Calculator.Square)
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "MS"
                onClicked: calculator.setMemory()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "1"
                onClicked: calculator.digitClicked("1")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "2"
                onClicked: calculator.digitClicked("2")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "3"
                onClicked: calculator.digitClicked("3")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "-"
                onClicked: calculator.additiveOperatorClicked(Calculator.Substraction)
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "1/x"
                onClicked: calculator.unaryOperatorClicked(Calculator.Inverse)
            }
        }

        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "M+"
                onClicked: calculator.addToMemory()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "0"
                onClicked: calculator.digitClicked("0")
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "."
                onClicked: calculator.pointClicked()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "+/-"
                onClicked: calculator.changeSignClicked()
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "+"
                onClicked: calculator.additiveOperatorClicked(Calculator.Addition)
            }
            Button {
                Layout.fillWidth: true
                Layout.fillHeight: true
                Layout.alignment: Qt.AlignHCenter

                text: "="
                onClicked: calculator.equalClicked()
            }
        }
    }
}
}
