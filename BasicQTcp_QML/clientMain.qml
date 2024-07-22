import QtQuick
import QtQuick.Controls
import TCP 1.0

Window {
    width: 400
    height: 276
    visible: true
    title: qsTr("client")

    TcpClient{
        id: myClient
        onR_data: function(data){

        }
    }

    Component.onCompleted: myClient.init()

    Column{
        spacing: 7;
        anchors.margins: 10;
        anchors.fill: parent
        width: parent.width
        Rectangle{ //서버가 보낼 메시지를 출력
            border.color: "black"; color:"lightgray"
            width:parent.width; height:200
            TextEdit{

            }
        }
        Rectangle{ //클라이언트가 메시지를 보내는 부분
            border.color: "black"; color:"lightgray"
            width:parent.width; height:200
            TextInput{
                width: 200; height:30
                id: entryField; focus: true
                font.pixelSize: 15
                //내부적으로 정의되어있는 시그널 returnPressed(엔터키)
                Keys.onReturnPressed: {
                    myClient.sendData(text); //TextInput의 text를 참고 (pdf)
                    clear(); //작성되어있던 내용은 지운다.
                }
            }
        }
    }
}
