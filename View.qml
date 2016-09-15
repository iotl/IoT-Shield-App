import QtQuick 2.5
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

import "UI.js" as UI

Rectangle {
    anchors.fill: parent

    property alias tempText: temperature.text
    property alias eventListModel: eventList.model
    property alias led1State: led1.state
    property alias led2State: led2.state
    property alias led3State: led3.state
    property alias segmentNumber: segment.numberSet
    property alias segmentState: segment.state

    Column {
        anchors.margins: UI.margins
        anchors.fill: parent

        //inputs
        GroupBox {
            title: ""
            anchors.right: parent.right
            anchors.left: parent.left

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
                BUTTON {
                    id: button2
                    idx: 2
                    width: UI.switchesWidth
                }
                BUTTON {
                    id: button1
                    idx: 1
                    width: UI.switchesWidth
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

