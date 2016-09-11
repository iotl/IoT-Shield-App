import QtQuick 2.5
import QtQuick.Controls 1.4

import "UI.js" as UI

ApplicationWindow {
    visible: true
    width: 400
    height: 400

    //signal bindings + model logic on js/qml side
    Connections {
        target: modelHandler
        onUpdateTemp: {
            screen.tempText = temp
        }
        onNewEvent: {  //(QString message, QString eventType = 0 )
            screen.eventListModel.insert(0, {"iconSource": UI.getImagePathFromType("buttonPressed"), "eventText": message})
        }
    }

    View {
        id: screen

    }
}

