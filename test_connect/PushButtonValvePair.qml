import QtQuick 2.15
import QtQuick.Controls 2.15
import Enum 1.0

Item {
    id: pushButtonValvePair
    width: parent.width
    height: parent.height/2

    property var pushButtonClass
    property bool isButtonActive: pushButton.isActive
    property bool isValveActive: false
    property alias textButton: pushButton.text

    Button {
        id: pushButton
        width: pushButtonValvePair.width/2
        height: pushButtonValvePair.height
        anchors{
            top: pushButtonValvePair.top
            left: pushButtonValvePair.left
        }

        text: qsTr("Button")
        onClicked: pushButtonClass.setState(isButtonActive? PneumaticState.INACTIVE : PneumaticState.ACTIVE)
    }

    Text{
        id: valve
        width: pushButtonValvePair.width/2
        height: pushButtonValvePair.height
        color: isValveActive? "green" : "red"
        text: isValveActive? qsTr("Valve Active") : qsTr("Valve Inactive")
        anchors{
            top: pushButtonValvePair.top
            right: pushButtonValvePair.right
        }
    }

}
