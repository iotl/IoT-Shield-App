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
