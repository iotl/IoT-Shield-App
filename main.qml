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
        onSetState: { // (bool redLed, bool yellowLed, bool greenLed, int credit)
            screen.led1State = redLed ? "On" : "Off"
            screen.led2State = yellowLed ? "On" : "Off"
            screen.led3State = greenLed ? "On" : "Off"
            if(credit >= 0) {
                screen.segmentNumber = credit
                screen.segmentState = "Set"
            } else {
                screen.segmentState = "NotSet"
            }
        }
        onUpdateTemp: {
            screen.tempText = temp
        }
        onNewEvent: {  //(QString message, QString eventType = 0 )
            screen.eventListModel.insert(0, {"eventText": message})
        }
    }

    View {
        id: screen
    }
}

