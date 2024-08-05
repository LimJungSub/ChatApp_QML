#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <iostream>
#include <userList.h>
#include <servmainwindow.h>
#include <QQmlContext>
using namespace std;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    const int MAX_USERNAME_SIZE = 15;

    if (argc != 2) {
        cout << "인자의 갯수가 올바르지 않습니다." << endl;
        return 1;
    }

    //파일 처리
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    //login.txt 처리 : 유저들을 set에 담음
    char line[MAX_USERNAME_SIZE];

    while(fgets(line, sizeof(line), file) != 0){
        line[strcspn(line,"\n")] = 0;
        UserList::addUser(line, false);
    }
    fclose(file);


    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/advancedChatApp_server/main.qml"));

    // qmlRegisterType<UserList>("UserList", 1, 0, "UserList");
    UserList userList;
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("UserList", &userList);

    engine.load(url);

    return app.exec();
}
