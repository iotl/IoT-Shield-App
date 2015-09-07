import QtQuick 2.5


Image {
    id: segment
    //source: "images/7segment"
    property int numberSet: 0

    fillMode: Image.PreserveAspectFit

    //scale the SVG properly
    sourceSize.width: this.width

    //initial state
    state: "Set"



    MouseArea {
        anchors.fill: parent
        onClicked: {
            (numberSet == 9)? numberSet = 0 : numberSet++
            modelHandler.setSEGMENT(numberSet)
        }

    }

    states: [
        State {
            name: "NotSet"
            PropertyChanges {
                target: segment
                source: "images/7segment-"
            }
        },
        State {
            name: "Set"
            PropertyChanges {
                target: segment
                //hint: maybe there is a possibility do change certan id-nodes in svg
                //      then we don't need the varios svg files (abcdefgdp-ids in default
                //      svg added)
                source: "images/7segment" + numberSet
            }
        }
    ]


}
