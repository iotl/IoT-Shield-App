import QtQuick 2.5


Image {
    id: testLED
    source: "images/redLED"

    //crop the legs!
    height: 40
    horizontalAlignment: Image.AlignLeft
    verticalAlignment: Image.AlignTop
    fillMode: Image.PreserveAspectCrop
    clip: true

    opacity: 0.2


    MouseArea {
        anchors.fill: parent
        onClicked: (testLED.state == "On")? testLED.state = "Off" : testLED.state = "On"

    }

    states: [
        State {
            name: "On"
            PropertyChanges {
                target: testLED
                opacity: 1
            }
        },
        State {
            name: "Off"
            PropertyChanges {
                target: testLED
                opacity: 0.2
            }
        }
    ]


}
