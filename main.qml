import QtQuick
import QtQuick.Window
import QtQuick.Layouts
import QtQuick.Controls
import PlistManageItem

Window {
    id: mainWindow
    width: 640
    height: 480
    visible: true
    title: qsTr("Cocos Plist文件生成器")

    //Drag.active: true
    //Drop.active: true

    //onDragged:{
    //}

    //onDropped:{

    //}
    PlistManageItem {
        id: plistClass
    }

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
        width: 150
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.leftMargin: 5
        color: "red"

        Rectangle {
            id: splic
            anchors.left: parent.left
            anchors.right: parent.right
            height: 70
            border.width: 1
            border.color: "blue"

            Label {
                id: splicGroupTitle
                anchors.horizontalCenter: parent.horizontalCenter
                text: "切割分片"
            }
            Label {
                id: horizontalSplicTitle
                anchors.top: splicGroupTitle.bottom
                anchors.topMargin: 5
                text: "横向切块："
            }
            Rectangle {
                id: horizontalSplicEditBackgroup
                anchors.top: horizontalSplicTitle.top
                anchors.left: horizontalSplicTitle.right
                anchors.right: parent.right
                height: 17
                color: "#F5F5F5"
                border.color: "#DDDDDD"
                border.width: 1
                TextEdit {
                    anchors.fill: parent
                }
            }
            Label {
                id: verticalSplicTitle
                anchors.top: horizontalSplicEditBackgroup.bottom
                anchors.topMargin: 5
                text: "纵向切块："
            }
            Rectangle {
                anchors.top: verticalSplicTitle.top
                anchors.left: verticalSplicTitle.right
                anchors.right: parent.right
                height: 17
                color: "#F5F5F5"
                border.color: "#DDDDDD"
                border.width: 1
                TextEdit {
                    anchors.fill: parent
                }
            }
        }

        Button {
            id: myButton
            text: "生成文件"
            anchors.top: splic.bottom

            onClicked: function () {
                plistClass.writePlist("test.plist")
            }
        }
    }

    Rectangle {

        anchors.left: leftLayout.right
        anchors.leftMargin: 5
        anchors.right: rightLayout.left
        anchors.rightMargin: 5

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
