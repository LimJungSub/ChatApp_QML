import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
// import UserList 1.0

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "Server Chat Application"

    Component{
        id: userListDelegate
        Repeater{
            model: UserList.userMapAsVariant().keys()

        Row{
            width: parent.width
            height: parent.height
            //유저명
            Text{
                text: modelData
            }
            //입장 상태 표시
            Text{
                text: model[modelData] //UserList.userMapAsVariant()[modelData]
            }
        }
    }
    }

    //1 model을 초기화 (유저 목록 생성) - append ()
    //2 model을 변경 (유저 접속) - set (checkVertifiedUser)
    //위 두 가지 시그널 필요
    //c++에서 시그널 발생 -> qml에서 잡음, qml에서는 어떤 타입에서 이 처리? -> Connections
    //1은 타입을 직접 등록하여 구현(ListModel, ListView 미사용) vs 사용(main.cpp에서 setContextProperty)하여 구현 고민좀 해봐야할듯
    GridLayout {
        anchors.fill: parent
        columns: 2
        rows: 2
        // spacing: 10

        // 클라이언트 목록 (왼쪽)


        ListView {
            id: clientListView
            Layout.column: 0
            Layout.row: 0
            Layout.rowSpan: 2
            width: parent.width / 3
            clip: true

            model: UserList

            delegate: userListDelegate


        }

        Connections{

        }


        // 대화 기록 (오른쪽)
        ListView {
            id: chatHistory
            Layout.column: 1
            Layout.row: 0
            width: parent.width * 2 / 3
            clip: true
            model: ListModel {
                // 예시 대화 기록 데이터
                ListElement { message: "Alice: Hello!" }
                ListElement { message: "Bob: Hi there!" }
                ListElement { message: "Server: Welcome everyone." }
            }
            delegate: Item {
                width: chatHistory.width
                height: 40
                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: index % 2 === 0 ? "#f0f0f0" : "#e0e0e0"
                    Text {
                        anchors.centerIn: parent
                        text: model.message
                        font.pixelSize: 16
                    }
                }
            }
        }

        // 채팅 입력과 전송 버튼 (하단)
        Rectangle {
            Layout.column: 1
            Layout.row: 1
            width: chatHistory.width
            height: 80
            color: "white"
            border.color: "gray"

            RowLayout {
                anchors.fill: parent
                spacing: 10
                padding: 10

                TextArea {
                    id: messageInput
                    Layout.fillWidth: true
                    placeholderText: "Enter your message..."
                    wrapMode: TextArea.Wrap
                }

                Button {
                    text: "Send"
                    onClicked: {
                        if (messageInput.text !== "") {
                            chatHistory.model.append({ message: "Server: " + messageInput.text })
                            messageInput.clear()
                            // 실제 서버 전송 로직을 여기에 추가
                        }
                    }
                }
            }
        }
    }
}
