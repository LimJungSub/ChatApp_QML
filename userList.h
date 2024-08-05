#ifndef USERLIST_H
#define USERLIST_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include <QString>
#include <QVariantMap>

//클라이언트 정보 담아두는 클래스
//정적으로 선언하여 main에서 접근가능토록 하자

//Q_PROPERTY를 활용하기 위해, set대신 map을 사용하여 유저의 입장상태정보를 관리하자. 그게 더 편할듯.
//Q_PROPERTY의 NOTIFY는 map의 value가 바뀌었을때 이를 감지할 수 있는지 알아야한다.
//Q_PROPERTY의 NOTIFY 시그널은 QMap 또는 std::map과 같은 맵 컨테이너의 개별 값 변경을 직접적으로 감지할 수 없습니다. Q_PROPERTY는 기본적으로 속성 전체가 변경되었을 때 시그널을 발생시킵니다. 개별 요소의 변경을 감지하려면 별도의 메커니즘이 필요합니다
//맵의 개별 값 변경을 감지하려면 직접 요소 변경 시 로직을 추가하거나 커스텀 시그널 및 슬롯을 사용해야 합니다.
class UserList: public QObject
{
    Q_OBJECT
    //read, notify만 사용
    Q_PROPERTY(QMap<QString, bool> userMap MEMBER userMap NOTIFY userMapChanged FINAL)
private:
    static QMap<QString, bool> userMap;

public:
    explicit UserList(QObject *parent = nullptr);
    static void addUser(const QString& userName, bool isEntering){
        userMap.insert(userName, isEntering);
    }
    static QMap<QString, bool> getUsers(){
        return userMap;
    }
    static bool vertify(QString username){
        auto iter = userMap.find(username);
        if(iter!=userMap.end()) return true;
        return false;
    }
    //QMap을 직접 변경시에 사용할 메소드
    Q_INVOKABLE void setValue(const QString userName, const bool isEntering) {
        if (userMap.value(userName) != isEntering) {
            userMap[userName] = isEntering;
            emit enterStatusChange();
        }
    }
    //유저 리스트 qml로 넘길때 사용할 메소드 -> Q_PROPERTY쓰니 필요없을 줄 알았지만, QVariantMap타입을 쓰는게 좋다고 한다.
    //Repeator 개념 참고 -> 위개념도 Pdf에
    Q_INVOKABLE QVariantMap userMapAsVariant() const {
        QVariantMap variantMap;
        for (auto it = userMap.cbegin(); it != userMap.cend(); ++it) {
            variantMap.insert(it.key(), it.value());
        }
        return variantMap;
    }
signals:
    void enterStatusChange();
};

//QMap<std::string> User::userSet;

#endif // USERLIST_H
