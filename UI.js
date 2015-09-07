.pragma library

var margins = 4
var fontPixelSize = 20
var switchesWidth = 50
var switchesSpacing = 20
var itemIconWidth = 30


function getImagePathFromType(eventType) {
    if (eventType === "buttonPressed") {
        return "images/button"
    } else {
        return "" //TODO: search for info svg
    }
}

