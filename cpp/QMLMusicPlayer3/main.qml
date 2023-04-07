import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Mp3Player")

    ColumnLayout {
    anchors.fill: parent;
        ColumnLayout {
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Layout.fillWidth: true
                Button {
                    Layout.fillWidth: true
                    width: 100
                    text: "Choose File"
                    onClicked: musicPlayer.openfile()
                }
                Button {
                    Layout.fillWidth: true
                    width: 100
                    text: "Play"
                    onClicked: musicPlayer.playfile()
                }
                Button {
                    Layout.fillWidth: true
                    width: 100
                    text: "Stop"
                    onClicked: musicPlayer.stop()
                }
            }
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter
            Layout.fillWidth: true
            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                Label {
                }
                Slider {
                    Layout.fillWidth: true
                    Layout.maximumWidth: 500
                    id: volumeSlider
                    value: 0
                    from: 0
                    to: 100
                    stepSize: 1

                    onValueChanged: {
                        musicPlayer.setVolume(value) // Call MusicPlayer's setVolume slot
                    }
                }
            }
        }
        ColumnLayout{
            Layout.alignment: Qt.AlignHCenter

            RowLayout {
                Layout.alignment: Qt.AlignHCenter
                spacing: 5

                ProgressBar {
                    Layout.fillWidth: true
                    Layout.maximumWidth: 500
                    id: progressBar
                    value: 0
                    from: 0
                    to: 100

                    Connections {
                        target: musicPlayer
                        onPlaybackPositionChanged: progressBar.value = position
                        onDurationChanged: progressBar.to = duration
                    }
                }
            }
        }
    }
}
