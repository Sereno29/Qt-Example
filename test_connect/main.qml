import QtQuick 2.15
import QtQuick.Window 2.15
import Controller 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    PushButtonValvePair{
        pushButtonClass: masterController.panel_controller.getPushButtonByIndex(0)
        isButtonActive: masterController.panel_controller.getPushButtonByIndex(0).is_active
        textButton: masterController.panel_controller.getPushButtonByIndex(0).push_button_name
        isValveActive: masterController.synoptic_controller.getValveByIndex(0).is_active
        anchors{
            top: parent.top
            right: parent.right
        }
    }

    PushButtonValvePair{
        pushButtonClass: pushButton
        isButtonActive: pushButton.is_active
        isValveActive: valve.is_active
        textButton: pushButton.push_button_name
        anchors{
            bottom: parent.bottom
            left: parent.left
        }
    }
}
