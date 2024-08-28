import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Dialogs

Window {
    visible: true
    width: 400
    height: 300
    title: "Chat Client"

    Column {
        anchors.centerIn: parent
        spacing: 20

        TextField {
            id: usernameField
            placeholderText: "Enter your username"
        }

        TextField {
            id: serverAddressField
            placeholderText: "Enter server address"
        }

        Button {
            text: "Connect"
            onClicked: {
                var username = usernameField.text;
                var serverAddress = serverAddressField.text;
                if (username && serverAddress) {
                    // 서버에 연결 시도
                    console.log("[init.qml] connecting server");
                    connectToServer(username, serverAddress);
                } else {
                    // 입력 오류 처리
                    console.log("[init.qml] Please enter both username and server address.");
                }
            }
        }
    }

    Text {
        id: _text
        x: 131
        y: 70
        width: 138
        height: 25
        text: "For Server Entering,"
        font.pixelSize: 13
        leftPadding: 6
        topPadding: 0
        font.weight: Font.Bold
    }

    function connectToServer(username, serverAddress) {
        // 서버 연결 로직 구현 : qml to c++로 구현
        console.log("[init.qml] Connecting to server at " + serverAddress + " with username " + username);
        // 서버 연결 후 검증 로직
        //c++의 Q_INVOKABLE로 선언된 함수 호출, 리턴값 받음
        serverInteraction.getServerConnectionResult(username, serverAddress);
    }

    Connections{
        target: serverInteraction
        onImAccepted: {
            // 새 창을 생성
            var component = Qt.createComponent("mainChatWindow.qml");
            var window = component.createObject(null);
            if (window) {
                window.show();
                Qt.callLater(() => close());  // 현재 창 닫기
            } else {
                console.log("Failed to load SecondWindow.qml");
            }
        }
        onImRejected: {
            connectionRejectedDialog.open();
        }
    }

    MessageDialog:{
        id: connectionRejectedDialog
        title: "알림"
        text: "입장이 허용되지 않은 유저입니다."
        standardButtons: StandardButton.Ok
    }
}
