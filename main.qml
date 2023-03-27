import QtQuick
import QtQuick.Window
import QtQuick.Layouts

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
        onEntered: function () {
            console.log("File Entered.")
        }
        onExited: function () {
            console.log("File exited.")
        }
        onDropped: function (drop) {
            console.log("File dropped: " + drop.text)
            mainImage.source = drop.text
        }
    }

    Rectangle {
        id: leftLayout
        width: 100
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        color: "red"
    }
    Rectangle {

        anchors.left: leftLayout.right
        anchors.right: rightLayout.left

        anchors.top: parent.top
        anchors.bottom: parent.bottom

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
        id: rightLayout
        width: 100
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.right: parent.right
        color: "blue"
    }
}
