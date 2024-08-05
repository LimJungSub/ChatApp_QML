import QtQuick

Window{
    id: emergencyPopupMsg
    visible: false
    width: 400
    height: 200
    title: "Important Emergency Message"

    Rectangle {
            anchors.fill: parent
            color: "#ffeecc"

            Text {
                id: messageText
                anchors.centerIn: parent
                text: ""
                font.pointSize: 18
                color: "#333333"
            }
    }

    // 창을 띄울 때 애니메이션 추가
       Behavior on visible {
           NumberAnimation {
               duration: 500
               easing.type: Easing.OutBounce
           }
       }

}
