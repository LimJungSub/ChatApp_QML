#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tcpserver.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);\


    //c++에서 qml 타입 구현을 위해 사용
    qmlRegisterType<TcpServer>("TCP", 1, 0, "TcpServer"); //임포트시 사용할이름, 메이저버전, 마이너버전, qml에서쓸타입명

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/training_chatServer_qml/main.qml"));

    engine.load(url);

    return app.exec();
}
