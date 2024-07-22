#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QTcpSocket>

class TcpClient : public QObject
{
    Q_OBJECT
public:
    explicit TcpClient(QObject *parent = nullptr){
        //parent 안쓰기때문에 오류없애려면 unused 필요
        Q_UNUSED(parent);
    }
private:
    QTcpSocket *tcpSocket;

signals:
    void r_data(QString rdata);

public slots:
    void init(){
        tcpSocket = new QTcpSocket(this);
        connect(tcpSocket, SIGNAL(readyRead()),  this, SLOT(receiveData()));

        //서버 접속
        tcpSocket->connectToHost("127.0.0.1", 20000);
    }
    void sendData(const QString &data){
        tcpSocket->write(data.toUtf8()+"\n");
    }

private slots:
    //서버로부터 받은 메시지 처리
    void receiveData(){
        QString txt = QString(tcpSocket->readAll());
        emit r_data(txt);
    }
};

#endif // TCPCLIENT_H
