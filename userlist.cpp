#include "UserList.h"

UserList::UserList(QObject *parent)
    : QObject(parent) {  // 부모 객체를 QObject에 전달하여 초기화
}
QVariantMap UserList::userMap; //정의
