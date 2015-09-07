import QtQuick 2.0
import QtQuick.Controls 1.4

import "UI.js" as UI

ScrollView {
    property alias model: listView.model
    anchors.fill: parent
    ListView { //TODO: automattically scroll downwards on ne items
        id: listView
        height: 300
        model: ListModel {
            id: eventList
//            ListElement {
//                iconSource: "images/button"
//                eventText: "test new"
//            }
        }

        delegate: Item {
            height: UI.itemIconWidth
            width: parent.width

            Image {
                id: elemnetIcon
                anchors.verticalCenter: parent.verticalCenter
                width: .5 * parent.height
                height: .5 * parent.height
                anchors.left: parent.left

                source: iconSource
            }
            Text { //FIXME
                id: elemnetText
                font.pixelSize: UI.fontPixelSize
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: elemnetIcon.right
                anchors.right: parent.right
                anchors.leftMargin: UI.margins
                anchors.rightMargin: UI.margins
                elide: Text.ElideLeft   //doesn't work...
                text: eventText
            }

        }
    }
}
