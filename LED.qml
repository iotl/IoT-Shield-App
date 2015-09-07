import QtQuick 2.5


Image {
    id: defaultLED
    source: "images/redLED"
    property int idx

    //scale the SVG properly
    sourceSize.width: this.width

    //initial state
    state: "Off"

    MouseArea {
        anchors.fill: parent
        onClicked: {
            if (defaultLED.state == "On") {
                defaultLED.state = "Off"
                modelHandler.switchLED(idx, "Off")
            }
            else {

                defaultLED.state = "On"
                modelHandler.switchLED(idx, "On")
            }
        }
    }

    states: [
        State {
            name: "On"
            PropertyChanges {
                target: defaultLED
                opacity: 1
            }
        },
        State {
            name: "Off"
            PropertyChanges {
                target: defaultLED
                opacity: 0.2
            }
        }
    ]


}
