#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tcpclient.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    qmlRegisterType<TcpClient>("TCP",1,0,"TcpClient");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/trainig_chatClient_qml/main.qml"));

    engine.load(url);

    return app.exec();
}
