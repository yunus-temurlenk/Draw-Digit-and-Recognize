import QtQuick 2.15
import QtQuick.Window 2.15
import Painter 1.0
import QtQuick.Controls 2.15
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Digit Recognizer")
    color: "lightblue"

    PainterItemQml{
        id: painterItem
        width: 100
        height: 100
        anchors.centerIn: parent
    }

    Column{
        anchors.left: painterItem.right
        anchors.leftMargin: 100
        anchors.verticalCenter: parent.verticalCenter
        spacing: 10
        Button{
            text: "Clear"
            onClicked: {
                painterItem.clearImage()
            }
        }
        Button{
            text: "Analyze"
            onClicked: {
                imageAnalyzer.analyzeImage(painterItem.toQImage())
            }
        }


    }

    Text{
        anchors.top: painterItem.bottom
        anchors.topMargin: 50
        font.pixelSize: 30
        font.bold: true
        text: imageAnalyzer.resultStr
        anchors.horizontalCenter: parent.horizontalCenter
    }


}
