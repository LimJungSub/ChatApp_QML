import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: mainQmlObj
    visible: true
    property alias sourceFileName_Rec: sourceFileName_Rec
    width: 800
    height: 600
    title: "Chat Application"

    signal sendDataToServer(string msg)

    Row {
        anchors.fill: parent
        anchors.rightMargin: 12
        anchors.topMargin: 13
        anchors.bottomMargin: 12
        spacing: 10

        // 1번: 유저들의 실시간 채팅 기록
        Rectangle {
            width: parent.width * 2 / 3
            height: parent.height
            color: "#f0f0f0"

            Column {
                id: column
                anchors.fill: parent
                spacing: 5

                // 채팅 기록을 표시하는 ListView
                ListView {
                    id: chatListView
                    width: parent.width
                    height: parent.height - 50
                    spacing: 5
                    model: chatModel // 채팅 메시지 모델 (아래에서 정의)
                    delegate: Item{
                                // Text 대신 Item으로 감싸서 크기 명시 가능
                                width: chatListView.width
                                height: childrenRect.height
                                Text {
                                    anchors.verticalCenter: parent.verticalCenter
                                    height: 20
                                    text: modelData
                                    font.bold: true
                                    font.pixelSize: 14
                                    padding: 5
                                }
                    }
                }

                // 채팅 입력 창과 전송 버튼
                Row {
                    width: parent.width
                    height: 50
                    spacing: 5

                    //내부적으로 정의되어있는 시그널 returnPressed(엔터키)
                    TextField {
                        id: chatInput
                        width: parent.width - 100
                        placeholderText: "Type your message..."

                        Keys.onReturnPressed: {
                            //occurs signal, process this signal in slots in c++
                            //만약 그냥 Q_INVOKABLE이 붙은 함수를 사용한다면, 동기식 처리라 느리다. 시그널 슬롯메커니즘 ㄱㄱ
                            //rootObjects를 통해 qml을 가져와서 connect해야하는데 어렵다
                            //once, send to server then, broadcast in server.
                            if (chatInput.text !== "") {
                                console.log("[main.qml] return pressed / contents: "+chatInput.text)
                                mainQmlObj.sendDataToServer(chatInput.text); //시그널은 함수처럼 호출할 수 있지만, 시그널의 위치에 신경을 써야한다. (소속을 꼭 잘 써주자. parent키워드를 통해 부모요소로 접근할수있다는것도 알자)
                                chatInput.clear();
                            } else{
                                warningWindow.visible = true
                            }
                        }
                    }

                    Button {
                        text: "Send"
                        width: 80
                        onClicked: {
                            if (chatInput.text !== "") {
                                console.log("[main.qml] return pressed / contents: "+chatInput.text);
                                mainQmlObj.sendDataToServer(chatInput.text);
                                chatInput.clear();
                            } else{
                                warningWindow.visible = true
                            }
                        }
                    }

                    // 경고창으로 사용할 새 창 (모달로 설정하자)
                    Window {
                        id: warningWindow
                        width: 300
                        height: 150
                        title: "경고"
                        visible: false
                        modality: Qt.ApplicationModal // 다른 창의 동작을 차단하는 모달 설정

                        Rectangle {
                            width: parent.width
                            height: parent.height

                            Column {
                                anchors.centerIn: parent
                                spacing: 20

                                Text {
                                    font.bold: true
                                    text: "메시지를 입력해주세요."
                                    horizontalAlignment: Text.AlignHCenter
                                    verticalAlignment: Text.AlignVCenter
                                }

                                Button {
                                        onClicked: warningWindow.close()
                                        contentItem: Text {
                                            text: "확인"
                                            color: "black" // 검정색으로 설정
                                            horizontalAlignment: Text.AlignHCenter
                                            verticalAlignment: Text.AlignVCenter
                                        }
                                }
                            }
                        }
                    }
                }
            }

            Connections{
                target: Server
                onProcessMsg: {
                    chatModel.append({"text": data}); //message는 signal의 인자명을 그대로 가져온 것 (이렇게 사용한다)
                    chatListView.positionViewAtEnd();  // 새로운 메시지를 받을 때 ListView의 끝으로 스크롤
                }
            }

        }


        // 2번: 유저들의 이름과 입장상태를 보여주는 부분
        Rectangle {
            id: rectangle
            width: parent.width * 1 / 3
            height: parent.height
            color: "white"
            border.color: "#cccccc"

            // Column 레이아웃을 사용하여 수직으로 구성
            Column {
                anchors.fill: parent
                spacing: 0  // 각 컴포넌트 사이의 간격 조정

                // ListView를 Column의 첫 번째 자식으로 배치
                ListView {
                    id: userListView
                    width: parent.width
                    height: parent.height * 0.8
                    spacing: 0
                    model: UserList.userMap_keys()

                    signal listViewCompleted()

                    delegate: Rectangle {
                        width: parent.width
                        height: 30
                        color: index % 2 === 0 ? "lightgray" : "white" // 짝수이면 회색, 홀수이면 흰색

                        Row {
                            anchors.fill: parent
                            spacing: 0
                            padding: 3  // 위, 아래 padding을 조정
                            width: parent.width

                            // 유저명
                            Text {
                                id: userNameText
                                width: parent.width * 0.5
                                text: modelData
                                font.pixelSize: 15
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                Component.onCompleted: {
                                    console.log("[Text 컴포넌트 (유저명) 완성 로그] 유저명:" + modelData);
                                }
                            }

                            // 입장 상태 표시
                            Text {
                                id: userStatusText
                                width: parent.width * 0.5
                                property bool isEntering: UserList.userMap_values(modelData)
                                text: isEntering ? "입장" : "미입장"
                                font.pixelSize: 15
                                color: isEntering ? "green" : "red"
                                horizontalAlignment: Text.AlignHCenter
                                verticalAlignment: Text.AlignVCenter
                                Component.onCompleted: {
                                    console.log("[Text 컴포넌트 (유저입장상태) 완성 로그] 유저명:" + modelData + " / 유저입장상태:" + isEntering);
                                }
                            }
                        }
                        //함수로 따로 분리하여 재사용성 높임 유저상태변경은 자주있는 일이므로. (강퇴기능에 활용가능)
                        function handleUserMapChanged(userName, isEntering) {
                                if (userNameText.text === userName) {
                                    userStatusText.isEntering = isEntering;
                                }
                        }
                        Connections {
                                    target: UserList
                                    onUserMapChanged: handleUserMapChanged
                        }
                        //Connections {
                        // target: UserList
                        // onUserMapChanged: {
                        //     if (userNameText.text === userName) {
                        //         userStatusText.isEntering = isEntering;
                        //         userStatusText.text = isEntering ? "입장" : "미입장";
                        //         userStatusText.color = isEntering ? "green" : "red";
                        //     }
                        // }
                    }
                    }

                    Component.onCompleted: {
                        console.log("ListView completed rendering");
                        //userListView.listViewCompleted();  // ListView 렌더링 완료 시 신호를 보냄
                        /* 역할을 하긴 하나 겹쳐보이는 문제떄문에 윗줄만 주석처리함 */
                    }
                }

                // Loader를 Column의 두 번째 자식으로 배치
                Loader {
                    id: rectangleLoader
                    width: parent.width
                    height: parent.height * 0.2

                    Connections {
                        target: userListView
                        function onListViewCompleted() {
                            console.log("sourceFileName Rect rendering now")
                            rectangleLoader.sourceComponent = sourceFileName_Rec;
                        }
                    }
                }
            }

            // 어떤 파일로부터 유저 목록을 받았는지 표시
            Component {  // 포함되려면 무조건 컴포넌트로 감싸야 합니다.
                id: sourceFileName_Rec

                Rectangle {
                    width: parent.width
                    height: rectangle.height * 0.2

                    radius: 13  // 모서리를 둥글게 만듭니다.
                    color: "#F5F5F5"  // 배경색을 밝은 회색으로 설정합니다.
                    border.color: "#D3D3D3"  // 테두리 색상을 연한 회색으로 설정합니다.
                    border.width: 3
                    anchors.verticalCenter: mainQmlObj.verticalCenter
                    anchors.left: mainQmlObj.right
                    anchors.right: mainQmlObj.left
                    anchors.top: mainQmlObj.bottom
                    anchors.bottom: mainQmlObj.top
                    anchors.leftMargin: -800
                    anchors.rightMargin: -800
                    anchors.topMargin: -600
                    anchors.bottomMargin: -115
                    anchors.horizontalCenter: mainQmlObj.horizontalCenter  // 테두리 두께를 설정합니다.

                    // 텍스트 추가
                    Text {
                        id: userListFileName
                        text: "유저 목록 파일: login.txt"
                        anchors.centerIn: parent  // 텍스트를 중앙에 배치
                        font.pixelSize: 15
                        font.family: "Arial"
                        color: "#333333"
                        anchors.margins: 1
                    }
                }
            }
        }
    // 채팅 메시지 모델
    ListModel {
        id: chatModel
    }




}










/*##^##
Designer {
    D{i:0}D{i:20;locked:true}
}
##^##*/
