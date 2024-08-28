#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QVariantMap>

// 클라이언트 정보 담아두는 클래스
// 정적으로 선언하여 main에서 접근 가능토록 하자
// 얘는 싱글톤으로 동작해야하는게 맞다...
//UserList 클래스에 userMap 멤버 변수를 static으로 선언한 것은 이 클래스가 싱글톤처럼 동작하게 만들기 위한 일부분입니다. 그러나 클래스 자체를 싱글톤으로 구현하는 것이 더 좋습니다. 이를 통해 UserList의 멤버 함수들이 싱글톤 인스턴스에서만 호출되도록 보장할 수 있습니다.
class UserList : public QObject
{
    Q_OBJECT
    // read, notify만 사용
    //Q_PROPERTY(QMap<QString, bool> userMap MEMBER userMap FINAL) //NOTIFY userMapChanged 는 빼자. map의 요소를 변경한다고해서 이게 발생 안됨

private:
    static QVariantMap userMap; //정적 멤버변수이므로 초기화 필요하다. cpp에서

public:
    explicit UserList(QObject *parent = nullptr);

    //main.cpp에서 login.txt에서 읽은 유저명을 유저맵에 추가하기위한 메소드 (입장값은 당연히 초기에 false)
    void addUser(const QString& userName) {
        qDebug() << "[userlist.h : addUser() : add to Map] " << userName;
        userMap.insert(userName, false);
    }

    //실제 유저의 검증 (servmainWindow에서도 이것을 통해 검증)
    bool verify(const QString& username) {
        auto iter = userMap.find(username);
        return iter != userMap.end();
    }

    // [servMainWindow에서 입장상태 변경시에 사용] QMap을 직접 변경 시에 사용할 메소드
    // Q_INVOKABLE을 붙여서 강퇴기능을 사용시에는 반영할 수 있긴 하겠지만, 우선 보류
    void setValue(const QString& userName, const QVariant isEntering) {
        if (userMap.value(userName) != isEntering) {
            userMap[userName] = isEntering;
            emit userMapChanged(userName, isEntering);
        }
    }
    //qml에선 이를 어떻게 반영할까? Q_PROPERTY를 썼다면 그냥 자동으로 변경됐을텐데;
    //물론 내 방식도 장점이 있긴할거다 직관적인? 그런느낌

    // 유저 리스트 qml로 넘길 때 사용할 메소드 -> Q_PROPERTY 쓰니 필요 없을 줄 알았지만, QVariantMap 타입을 쓰는 게 좋다고 한다.
    // QVariantMap을 qml에서 받아봤자 할수있는게 별로 없으니 키밸류 리턴하는 함수 따로 만든다
    Q_INVOKABLE QList<QString> userMap_keys() const {
        return userMap.keys();
    }

    Q_INVOKABLE QVariant userMap_values(QString userName) const{
        return userMap[userName];
    }
signals:
    void userMapChanged(QString userName, QVariant isEntering);
    void enterStatusChange();

public slots:
    //servmainwindow 참고
    void userEntered(QString userName){
        userMap[userName] = true;
    }
};

#endif // USERLIST_H
