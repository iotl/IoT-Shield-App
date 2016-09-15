import QtQuick 2.0
import QtQuick.Controls 1.4

import "UI.js" as UI

ScrollView {
    property alias model: listView.model
    anchors.fill: parent
    ListView {
        id: listView
        height: 300
        model: ListModel {
            id: eventList
        }

        delegate: Item {
            height: 15
            width: parent.width

            Text {
                id: elemnetText
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.leftMargin: UI.margins
                anchors.rightMargin: UI.margins
                elide: Text.ElideLeft
                text: eventText
            }
        }
    }
}
