import QtQuick 2.5
import QtQuick.Controls 1.4

import "UI.js" as UI

ApplicationWindow {
    visible: true
    width: 400
    height: 600

    //signal bindings + model logic on js/qml side
    Connections {
        target: modelHandler
        onUpdateTemp: {
            console.log("I sould now update my temperature-label..")
            screen.tempText = temp
        }
        onNewEvent: {  //(QString message, QString eventType = 0 )
            console.log(message + ", " + eventType)
            screen.eventListModel.append({"iconSource": UI.getImagePathFromType("buttonPressed"), "eventText": "test new"})
        }
    }

    View {
        id: screen

    }
}

