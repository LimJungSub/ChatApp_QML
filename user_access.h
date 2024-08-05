#ifndef USER_ACCESS_H
#define USER_ACCESS_H

#include <QObject>

//클라이언트 요청 허용 시 사용할 클래스
class User_access : public QObject
{
    Q_OBJECT
public:
    explicit User_access(QObject *parent = nullptr);

signals:
};

#endif // USER_ACCESS_H
