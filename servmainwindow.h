#ifndef SERVMAINWINDOW_H
#define SERVMAINWINDOW_H

#include <QObject>
#include <userList.h>
#include <user_access.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class servMainWindow : public QObject
{
    Q_OBJECT
private:
    QTcpServer* server;
    QList<QTcpSocket*> clients;
    QTcpSocket* currentClient; //검증중인 클라이언트를 공유해야해서 멤버변수로

public:
    explicit servMainWindow(QObject *parent = nullptr);
    void init(){
        //서버로 기능을 하게 구현
        server = new QTcpServer;
            //listen
        server->listen(QHostAddress("127.0.0.1"), 20000);
        //.qml에 초기 userSet 정보 넘겨줌

        qDebug() << "[Server is listening on port 20000]";
        connect(server, SIGNAL(newConnection()), this, SLOT(connectAndVertify()));
    }
signals:
    void processInitUserList();
    void checkVertifiedUser();

private slots:
    void connectAndVertify(){
        //connect 확인
        currentClient = server->nextPendingConnection();
        //리스트에 넣기전에 해당 client 검증 : 첫 메시지를 읽음.
        connect(currentClient, SIGNAL(readyRead()), this, SLOT(vertifyUser()));
        //User::getUsers()
    }
    void vertifyUser(){
        //첫 데이터 읽기, 첫 데이터는 유저의 이름을 전송
        QByteArray data = currentClient->readAll();
        // 데이터를 QString으로 변환하고 공백 제거
        QString currentUserName = QString::fromUtf8(data).trimmed();
        if(UserList::vertify(currentUserName)){
            // 인증 성공 메시지 전송
            currentClient->write("유저 인증되셨습니다. 환영합니다!\n");
            //서버측에서 gui리스트에 작업 필요
            emit checkVertifiedUser();
        }
        else{
            //거부(시그널; 클라이언트에게 데이터 전송)
            currentClient->write("허가된 유저가 아닙니다. 연결을 종료합니다\n");
            currentClient->disconnectFromHost();
        }
    }
};

#endif // SERVMAINWINDOW_H
