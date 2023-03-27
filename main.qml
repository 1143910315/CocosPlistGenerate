import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Cocos Plist Generate")

    //Drag.active: true
    //Drop.active: true

    //onDragged:{
    //}

    //onDropped:{

    //}
    DropArea {
        anchors.fill: parent
        onEntered: {
            console.log("File Entered.")
        }
        onExited: {
            console.log("File exited.")
        }
        onDropped: {
            console.log("File dropped: " + drop.text)
            loadImage(drop.text)
        }
    }

    Image {
        id: mainImage
        anchors.fill: parent
    }
    function loadImage(path) {
        mainImage.source = path
    }
}
