import QtQuick 2.5
import QtQuick.Window 2.2

Window {
    visible: true

    //MainForm {
    //    anchors.fill: parent
    //    mouseArea.onClicked: {
    //        // Qt.quit();
    //    }
    //}


    Connections {
        target: modelHandler
        onTestSignal: {
            console.log("Recieved " + message)
        }
        onUpdateTemp: {
            console.log("I sould now update my temperature-label..")
        }
    }

    View {
        anchors.fill: parent
    }
}

