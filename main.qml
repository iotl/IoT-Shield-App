import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true
    id: screen
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
            page.tempText = temp
        }
    }

    View {
        id: page

    }
}

