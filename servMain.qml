import QtQuick
import QtQuick.Controls
import TCP 1.0

Window {
    width: 400
    height: 250
    visible: true
    title: qsTr("server")

    TcpServer{
        id: myServer
        onR_data: function(data){
            output.text += "Client> "+data;
            myServer.sendData("Server> 메시지를 전달받았습니다.");
        }
    }
    //qml이 로딩되고 생성자처럼 호출하는 부분이 Component.onCompleted
    Component.onCompleted: myServer.init() //c++의 init호출

    Column{
        spacing:7; anchors.margins: 10;
        anchors.fill: parent

        Rectangle{
          border.color: "black"; color:"lightgray";
          width: parent.width; height: parent.height

          //클라이언트가 보낸 메시지를 출력하는 부분
          TextEdit{
              id:output
              anchors.fill: parent

          }
        }
    }
}
