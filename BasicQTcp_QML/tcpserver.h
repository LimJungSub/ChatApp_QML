#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr){
        Q_UNUSED(parent);
    }

public slots:
    //호출 시점은 qml프로그램이 뜬 순간
    void init(){
        tcpServer = new QTcpServer;
        serverIp = tcpServer->serverAddress();
        //새로운 클라이언트가 접속했음을 알리는 newConnection() 사용
        connect(tcpServer, SIGNAL(newConnection()), this, SLOT(slotConnection())); //이 클래스의 슬롯을 사용(this)

        //listen
        tcpServer->listen(QHostAddress("127.0.0.1"), 20000);
    }
    //서버->클라이언트 메시지 전송 시 사용
    void sendData(QString data){
        tcpSocket->write(data.toUtf8());
    }
signals:
    void r_data(QString data); //데이터 받기

private slots: //초기화는 private로
    void slotConnection(){
        tcpSocket = tcpServer->nextPendingConnection(); //대기열에서 클라이언트 꺼내옴
        clientIp = tcpSocket->peerAddress();
        //데이터를 처리하기 위해 connection필요 -> receivedData함수에서 처리 (데이터받기)
        connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveData()));
        //(초기 데이터 쓰기)
        sendData("<서버 "+serverIp.toString()+"> 에 연결되었습니다.");
    }
    void receiveData(){
        QString data = QString(tcpSocket->readAll());
        //시그널 발생
        emit r_data(data); //.qml파일의 onR_data 슬롯(=이벤트핸들러) 호출
    }
private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QHostAddress serverIp;
    QHostAddress clientIp;
};

#endif // TCPSERVER_H
