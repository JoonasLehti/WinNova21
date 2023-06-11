import QtQuick 2.0
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import Calculator 1.0

Item {
    default property alias buttons: buttonGrid.children

    ColumnLayout {
        Layout.alignment: Qt.AlignHCenter
        spacing: 5

        Grid {
            id: buttonGrid
            columns: 4
            spacing: 5

            Repeater {
                model: buttons.length
            }
        }
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
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5
                Button {
                    id: clearMemory
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "MC"
                    onClicked: calculator.clearMemory()
                }
                Button {
                    id: digit7
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "7"
                    onClicked: calculator.digitClicked("7")
                }
                Button {
                    id: digit8
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "8"
                    onClicked: calculator.digitClicked("8")
                }
                Button {
                    id: digit9
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "9"
                    onClicked: calculator.digitClicked("9")
                }
                Button {
                    id: multiplicative
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "/"
                    onClicked: calculator.multiplicativeOperatorClicked(Calculator.Division)
                }
                Button {
                    id: unaryOperator
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
                    id: readMemory
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "MR"
                    onClicked: calculator.readMemory()
                }
                Button {
                    id: digit4
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "4"
                    onClicked: calculator.digitClicked("4")
                }
                Button {
                    id: digit5
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "5"
                    onClicked: calculator.digitClicked("5")
                }
                Button {
                    id: digit6
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "6"
                    onClicked: calculator.digitClicked("6")
                }
                Button {
                    id: multiplication
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "*"
                    onClicked: calculator.multiplicativeOperatorClicked(Calculator.Multiplication)
                }
                Button {
                    id: unaryOperatorsquare
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
                    id: setMemory
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "MS"
                    onClicked: calculator.setMemory()
                }
                Button {
                    id: digit1
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "1"
                    onClicked: calculator.digitClicked("1")
                }
                Button {
                    id: digit2
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "2"
                    onClicked: calculator.digitClicked("2")
                }
                Button {
                    id: digit3
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "3"
                    onClicked: calculator.digitClicked("3")
                }
                Button {
                    id: additive
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "-"
                    onClicked: calculator.additiveOperatorClicked(Calculator.Substraction)
                }
                Button {
                    id: unary
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
                    id: addToMemory
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "M+"
                    onClicked: calculator.addToMemory()
                }
                Button {
                    id: digit0
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "0"
                    onClicked: calculator.digitClicked("0")
                }
                Button {
                    id: pointClicked
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "."
                    onClicked: calculator.pointClicked()
                }
                Button {
                    id: changeSignClicked
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "+/-"
                    onClicked: calculator.changeSignClicked()
                }
                Button {
                    id: additiveOpereator
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.alignment: Qt.AlignHCenter

                    text: "+"
                    onClicked: calculator.additiveOperatorClicked(Calculator.Addition)
                }
                Button {
                    id: equalClicked
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
