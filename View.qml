import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4
import "UI.js" as UI

Rectangle {
    //horizontalScrollBarPolicy: Qt.ScrollBarAlwaysOff
    anchors.fill: parent

    //property alias tempText: temperature.text

    ColumnLayout {
        anchors.margins: UI.margins
        id: grid
        height: implicitHeight
        width: parent.width


        GroupBox {
            title: "LEDs"
            Layout.fillWidth: true
            anchors.margins: UI.margins
            //Layout.columnSpan: grid.columns
            LED {

            }

//            RowLayout {
//                anchors.fill: parent
//                CheckBox {
//                    text: "LED 1"
//                    onClicked: modelHandler.switchLED("1")
//                }
//                CheckBox {
//                    text: "LED 2"
//                    onClicked: modelHandler.switchLED("2")
//                }
//                CheckBox {
//                    text: "LED 3"
//                    onClicked: modelHandler.switchLED("2")
//                }
//            }
        }

        GroupBox {
            title: "7-Segment Anzeige"
            Layout.fillWidth: true
            //Layout.columnSpan: grid.columns
            ComboBox {
                id: segment7
                anchors.fill: parent
                editable: false
                model: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
                onActivated: modelHandler.setSEGMENT(index)
            }
        }

        GroupBox {
            id: temp
            title: "Temperatursensor"
            Layout.fillWidth: true
            //Layout.columnSpan: grid.columns
            Label {
                id: temperature
                anchors.fill: parent
                text: "--"
            }
        }

        GroupBox {//for what?
            title: "Buttons"
            Layout.fillWidth: true
            //Layout.columnSpan: grid.columns
            RowLayout {
                anchors.fill: parent
                Button {
                    text: "Button 1"
                    onClicked: modelHandler.test("Button 1 clicked")
                }
                Button {
                    text: "Button 2"
                    onClicked: modelHandler.test("Button 2 clicked")
                }
            }
        }
    }
}

