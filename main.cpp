#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QQuickStyle>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QQuickStyle::setStyle("Material");

    w.show();



    return a.exec();
}



