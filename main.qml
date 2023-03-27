import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3

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
    RowLayout {
        spacing: 10
        anchors.fill: parent

        Rectangle {
            width: 100
            height: 50
            color: "red"
        }
        Rectangle {
            RowLayout.fillWidth: true
            height: 50

            Image {
                id: mainImage

                anchors.fill: parent
                //sourceSize: {
                //    width: parent.width
                //    height: parent.height
                //}
                fillMode: Image.PreserveAspectFit
            }
        }

        Rectangle {
            width: 100
            height: 50
            color: "blue"
        }
    }

    function loadImage(path) {
        mainImage.source = path
    }
}
