import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

import "UI.js" as UI

Rectangle {
    anchors.fill: parent

    property alias tempText: temperature.text
    property alias eventListModel: eventList.model

    Column {
        anchors.margins: UI.margins
        anchors.fill: parent

        //inputs
        GroupBox {
            title: "Click Me!"
            anchors.right: parent.right
            anchors.left: parent.left

            anchors.margins: UI.margins

            RowLayout {
                anchors.horizontalCenter: parent.horizontalCenter
                spacing: UI.switchesSpacing

                LED { //redLED
                    id: led1
                    idx: 1
                    width: UI.switchesWidth
                }
                LED {
                    id: led2
                    idx: 2
                    source: "images/yellowLED"
                    width: UI.switchesWidth
                }
                LED {
                    id: led3
                    idx: 3
                    source: "images/greenLED"
                    width: UI.switchesWidth
                }
                SEGMENT {
                    id: segment
                    width: 1.5 * UI.switchesWidth
                }
            }
        }
        GroupBox {
            title: "Temperatursensor"

            anchors.right: parent.right
            anchors.left: parent.left

            Label {
                id: temperature

                anchors.fill: parent
                text: "--"
            }
        }
        GroupBox {
            id: events
            title: "Events"

            anchors.right: parent.right
            anchors.left: parent.left

            EventList{
                id: eventList
            }
        }
    }
}

