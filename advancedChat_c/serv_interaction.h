#ifndef SERVER_INTERACTION_H
#define SERVER_INTERACTION_H

#include <QTcpSocket>
#include <QObject>
#include <QTcpServer>
#include <QDebug>

class serv_interaction : public QObject
{
    Q_OBJECT
private:
    QTcpSocket *m_tcpSocket;
    QString userName;
public:
    explicit serv_interaction(QObject *parent = nullptr);

    Q_INVOKABLE bool getServerConnectionResult(QString username, QString serverAddress, int serverPort){
        m_tcpSocket = new QTcpSocket(this);
        this->userName = username;
        m_tcpSocket->connectToHost(serverAddress, serverPort); //기본적으로 서버주소와 포트만 넘겨서 연결을 요청한다.
        //서버측에서 유저명 검증을 클라이언트측에서의 최초데이터로 유저명을 전송함을 가정하였으므로 따른다
        connect(m_tcpSocket, SIGNAL(readyRead()), this, SLOT(sendUserName()));
    }
signals:
    void imAccepted();
    void imRejected();

private slots:
    void sendUserName(){
        m_tcpSocket->write((this->userName).toUtf8());
        qDebug() << (this->userName).toUtf8() << "is toUtf8 userName";
    }
    void readData(){
        QString msg = QString(m_tcpSocket->readAll());
        if(msg == "Accepted\n"){    //qml에 성공 메시지 전달
            emit imAccepted();
        } else{
            emit imRejected();
        }
    }
};

#endif // SERVER_INTERACTION_H
