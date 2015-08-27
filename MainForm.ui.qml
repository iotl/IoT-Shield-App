import QtQuick 2.5
import QtQuick.Controls 1.3

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    MouseArea {
        id: mouseArea
        anchors.fill: parent

        CheckBox {
            id: led_1
            x: 224
            y: 19
            text: qsTr("LED_1")
        }

        CheckBox {
            id: led_2
            x: 224
            y: 43
            text: qsTr("LED_2")
        }

        CheckBox {
            id: led_3
            x: 224
            y: 69
            text: qsTr("LED_3")
        }

        Text {
            id: ldr
            x: 101
            y: 113
            width: 48
            height: 15
            text: qsTr("Text")
            font.pixelSize: 12
        }

        Text {
            id: temp
            x: 101
            y: 129
            width: 48
            height: 15
            text: qsTr("Text")
            font.pixelSize: 12
        }

        Button {
            id: button1
            x: 101
            y: 167
            text: qsTr("Buzzer")
        }

        ComboBox {
            id: seg7
            x: 63
            y: 19
        }
    }
}

