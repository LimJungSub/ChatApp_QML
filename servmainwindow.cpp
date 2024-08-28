#include "servmainwindow.h"

servMainWindow::servMainWindow(QObject *parent)
    : QObject{parent}
{}
QList<QTcpSocket*> servMainWindow::clients;
