#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <userlist.h>
#include <servmainwindow.h>
#include <QQmlContext>
#include <QFile> //방식 변경

using namespace std;
int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // if (argc != 2) {
    //     cout << "인자의 갯수가 올바르지 않습니다." << endl;
    //     return 1;
    // }                                            -> command line argument로 실행을 가정했던 상태의 코드

    //파일 처리
    QFile qfile(":/login.txt");
    if (!qfile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        perror("Error opening file");
        return 1;
    }


    UserList userList;
    servMainWindow server;

    //login.txt 처리 : 유저들을 set에 담음
    QTextStream in(&qfile);
    QString line;
    while (!in.atEnd()) {
        line = in.readLine();
        line = line.trimmed();  // 공백 및 개행 문자 제거
        if (!line.isEmpty()) {  // 빈 줄은 무시
            userList.addUser(line);
            qDebug() << "[main.cpp] User: " << line << "추가 완료";
        }
    }

    QQmlApplicationEngine engine;

    //qmlRegisterSingletonType<UserList>("UserList", 1, 0, "UserList");
    QQmlContext *ctx = engine.rootContext();
    ctx->setContextProperty("UserList", &userList);
    ctx->setContextProperty("Server", &server);

    engine.load(":/main.qml");

    // [서버->서버 데이터 전송을 위해]for qml signal -> c++ slot    //사실 아래부분은 servmainwindow init에서 해도 될것같기도, 는 아닌가... qml을 못가져오는구나
    // 단순 함수호출은 동기적이니 비동기를 위해 시그널 슬롯을 씀을 기억한다. 서버서버도 비동기적으로하려고하는거
    // 서버ui에서 return pressed됐음에도 sendDataToServer이 호출 안되는 문제
    //rootObjects()는 임시객체를 반환하기때문에, first()를 임시객체에 저장하지 말라는 경고가 발생한다. 따라서 안전하게 rootObejcts()까지를 변수에 저장하고, 후에 first() 적용
    // if,else를 통해 qml컴포넌트를 제대로 가져왔는지 확인하는 로그를 추가하자

    // rootObjects()의 반환값을 명시적으로 변수에 저장
    QObject* mainObj = engine.rootObjects().first();    //qml파일에서 signal의 위치에대해 주의하자. 정말 root Level에 있어야한다. //https://stackoverflow.com/questions/43758113/how-to-connect-a-qml-signal-with-a-c-slot
    // qDebug() << "rootObjects: " << rootObjects;
    // 명시적으로 저장된 객체를 사용하여 first() 호출
    // QObject *mainQmlObj = rootObjects.first()->findChild<QObject*>("mainQmlObj");
    // qDebug() << "mainQmlObj: " << mainQmlObj;
    if(mainObj){
        qDebug() << "[main.cpp] server to server sending is completed";
        // SIGNAL과 SLOT 연결
        QObject::connect(mainObj, SIGNAL(sendDataToServer(QString)), &server, SLOT(sendMsg(QString))); //qml 시그널 인자 stirng은 c++ QString과 대응된다.
    }else{
        qDebug() << "[main.cpp] mainObj not initialized";
    }


    return app.exec();
}
