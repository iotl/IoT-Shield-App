import QtQuick 2.5
import QtQuick.Controls 1.4

ApplicationWindow {
    visible: true
    width: 400
    height: 600

    //property alias tempLabel: page.tempText
    Connections {
        target: modelHandler
        onTestSignal: {
            console.log("Recieved " + message)
        }
        onUpdateTemp: {
            console.log("I sould now update my temperature-label..")
            screen.tempText = temp
        }
    }

    View {
        id: screen

    }
}

