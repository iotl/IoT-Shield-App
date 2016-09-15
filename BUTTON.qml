import QtQuick 2.5


Image {
    id: button
    source: "images/button"
    property int idx

    //scale the SVG properly
    sourceSize.width: this.width

    MouseArea {
        anchors.fill: parent
        onClicked: {
            modelHandler.onButtonPressed(idx)
        }
    }
}
