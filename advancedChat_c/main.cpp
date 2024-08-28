#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <serv_interaction.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    serv_interaction server_interaction;
    engine.rootContext()->setContextProperty("serverInteraction", &server_interaction);

    const QUrl url(QStringLiteral("qrc:/advancedChat_client/init.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
