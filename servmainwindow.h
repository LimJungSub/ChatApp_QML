#ifndef SERVMAINWINDOW_H
#define SERVMAINWINDOW_H

#include <QObject>
#include <userlist.h>
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>

class servMainWindow : public QObject
{
    Q_OBJECT
private:
    QTcpServer* server;
    static QList<QTcpSocket*> clients; //UserList는 이름과상태정보, 얘는 QTcp소켓관리차원의 컨테이너
    QTcpSocket* currentClient; //검증중인 클라이언트를 공유해야해서 멤버변수로
    QString currentClientUserName;
    UserList userList; //clients와 다르게 Map의 값만 바뀌고 클라를 삭제하진X
public:
    explicit servMainWindow(QObject *parent = nullptr);
    //**얜 언제 호출 되냐? 아직 qml에서 안썼다.
    void init(){
        //서버로 기능을 하게 구현
        server = new QTcpServer;
            //listen
        server->listen(QHostAddress("127.0.0.1"), 20000);
        //.qml에 초기 userSet 정보 넘겨줌

        qDebug() << "[Server is listening on port 20000]";
        connect(server, SIGNAL(newConnection()), this, SLOT(connectAndverify()));
        //connect(currentClient, SIGNAL(readyRead()), this, SLOT(verifyUser())); 안해도될것같은
        connect(currentClient, SIGNAL(readyRead()), this, SLOT(readClientData()));
        connect(currentClient, SIGNAL(disconnected()), this, SLOT(onClientDisconnected()));
    }
    //메시지를 read하고 qml에 전송 [브로드캐스트 기능임에 주의]
    //아래서 QTcpSocket *clientSocket = qobject_cast<QTcpSocket*>(sender()); ,아마 따로 생성은필요업승ㄹ거임
    //send is below
    void readClientData(){
        QByteArray data_before = currentClient->readAll();

        QString data = "["+currentClientUserName+"] "+QString::fromUtf8(data_before)+"\n";

        emit processMsg(data);

        // 받은 데이터를 다른 클라이언트들에게 브로드캐스트
        for (QTcpSocket *client : clients) {
            if (client != currentClient) {
                client->write(data.toUtf8());   //클라이언트에 보낼때는 또 utf8로
                //not only sending message, need qml update
                //in qml, must read
                //clients write contents in qml. so in qml, signal occur
                //in c++, need that contents processing
            }
        }
    }
signals:
    void processInitUserList();
    void checkVertifiedUser(QString currentUserName);
    void processMsg(QString data); //얘를 통해 서버가 전송한데이터와 클라이언트가 전송한 데이터 모두 처리한다. (QML의 슬롯 사용)


//slots에 있는 함수들도 멤버함수처럼 호출가능하다.
public slots:
    void connectAndverify(){
        currentClient = server->nextPendingConnection();
        //currentClient 초기화후에 검증이 필요하다.
        //아마 emit또는 직접호출 하여 검증 필요
        verifyUser();  // verifyUser를 직접 호출하여 검증을 수행(아마 시그널슬롯메커니즘쓰면 비동기적 시행가능할듯)
    }
    //리스트에 넣기전에 해당 client 검증 : 첫 메시지를 읽음.
    void verifyUser(){
        connect(this, SIGNAL(checkVertifiedUser(QString)), &userList, SLOT(userEntered()));
        //첫 데이터 읽기, 첫 데이터는 유저의 이름을 전송
        QByteArray userName = currentClient->readAll();
        // 데이터를 QString으로 변환하고 공백 제거
        currentClientUserName = QString::fromUtf8(userName).trimmed();
        if(userList.verify(currentClientUserName)){ //검증은 userlist를 활용하여
            // setValue를 통해 입장상태로 변경, setValue에서 emit하여 QML에서 처리하게함.
            // 인증 성공 메시지 전송
            clients.append(currentClient); //리스트에 추가
            currentClient->write("Accepted\n");
            userList.setValue(currentClientUserName, true);
        }
        else{
            // 거부, 기본이 false상태였으므로 setValue필요X
            currentClient->write("Rejected\n");
            currentClient->disconnectFromHost();
        }
    }

    void onClientDisconnected(){
        // 현재 연결된 클라이언트의 유저명을 이용해 status를 변경 (QML에 영향주는 것)
        userList.setValue(currentClientUserName, false);

        // QList에서 currentClient를 찾아 제거
        if (clients.removeOne(currentClient)) {
            qDebug() << "클라이언트의 접속이 끊어졌습니다.";
        } else {
            qDebug() << "Failed to remove client from list. Client not found.";
        }

        // currentClient를 삭제하고 포인터를 null로 설정
        currentClient->deleteLater();
        currentClient = nullptr;
    }

    //must in ther client, too
    //얘가 호출이 안되네, 연결이 안됐나
    void sendMsg(QString data){

        qDebug() << "[servmainwindow:sendMsg] [Server]:"+data;

        emit processMsg("[서버] "+data);

        //to clients, directly send
        for (QTcpSocket *client : clients) {
                client->write(("[Server]"+data+"\n").toUtf8());
        }

        //서버측의 qml업데이트도 필요하다
    }
};

#endif // SERVMAINWINDOW_H
