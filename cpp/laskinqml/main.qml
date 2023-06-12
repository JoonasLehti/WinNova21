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

    ColumnLayout{
        Layout.alignment: Qt.AlignHCenter
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5
            TextField {
                Layout.fillWidth: true
                height: parent.height * 0.1
                id: inputBox2
                text: calculator.display
            }
        }
    }
        RowLayout {
            Layout.alignment: Qt.AlignHCenter
            spacing: 5
            Buttons {
                text: "Backspace"
                onClicked: calculator.backspaceClicked()
            }
            Buttons {
                text: "Clear"
                onClicked: calculator.clear()
            }
            Buttons {
                text: "Clear All"
                onClicked: calculator.clearAll()
            }
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5
                Buttons {
                    text: "MC"
                    onClicked: calculator.clearMemory()
                }
                Buttons {
                    text: "7"
                    onClicked: calculator.digitClicked("7")
                }
                Buttons {
                    text: "8"
                    onClicked: calculator.digitClicked("8")
                }
                Buttons {
                    text: "9"
                    onClicked: calculator.digitClicked("9")
                }
                Buttons {
                    text: "/"
                    onClicked: calculator.multiplicativeOperatorClicked(Calculator.Division)
                }
                Buttons {
                    text: "Sqrt"
                    onClicked: calculator.unaryOperatorClicked(Calculator.SquareRoot)
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5
                Buttons {
                    text: "MR"
                    onClicked: calculator.readMemory()
                }
                Buttons {
                    text: "4"
                    onClicked: calculator.digitClicked("4")
                }
                Buttons {
                    text: "5"
                    onClicked: calculator.digitClicked("5")
                }
                Buttons {
                    text: "6"
                    onClicked: calculator.digitClicked("6")
                }
                Buttons {
                    text: "*"
                    onClicked: calculator.multiplicativeOperatorClicked(Calculator.Multiplication)
                }
                Buttons {
                    text: "X2"
                    onClicked: calculator.unaryOperatorClicked(Calculator.Square)
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5

                Buttons {
                    text: "MS"
                    onClicked: calculator.setMemory()
                }
                Buttons {
                    text: "1"
                    onClicked: calculator.digitClicked("1")
                }
                Buttons {
                    text: "2"
                    onClicked: calculator.digitClicked("2")
                }
                Buttons {
                    text: "3"
                    onClicked: calculator.digitClicked("3")
                }
                Buttons {
                    text: "-"
                    onClicked: calculator.additiveOperatorClicked(Calculator.Substraction)
                }
                Buttons {
                    text: "1/x"
                    onClicked: calculator.unaryOperatorClicked(Calculator.Inverse)
                }
            }
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5

                Buttons {
                    text: "M+"
                    onClicked: calculator.addToMemory()
                }
                Buttons {
                    text: "0"
                    onClicked: calculator.digitClicked("0")
                }
                Buttons {
                    text: "."
                    onClicked: calculator.pointClicked()
                }
                Buttons {
                    text: "+/-"
                    onClicked: calculator.changeSignClicked()
                }
                Buttons {
                    text: "+"
                    onClicked: calculator.additiveOperatorClicked(Calculator.Addition)
                }
                Buttons {
                    text: "="
                    onClicked: calculator.equalClicked()
                }
            }
        }
    }
}
