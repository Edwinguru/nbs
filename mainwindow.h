#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <iostream>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QDebug>
#include<QSqlError>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QString PRODUCT_TABLE_NAME  = "products";
    QString DATABASE_NAME = "/home/naveen/NBS/nbs.sqlite";
    QSqlDatabase db;
    explicit MainWindow(QWidget *parent = nullptr);
    bool isDbConnected(QSqlDatabase db);
    void StoreDataInDataBase(QString productName, QString productDescription);
    bool checkTableExists();
    void createUserTable();

    ~MainWindow();


private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
