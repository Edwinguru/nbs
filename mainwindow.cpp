#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //opening the db connection
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setDatabaseName(MainWindow::DATABASE_NAME);
    if (this->db.open()) {
        if (this->checkTableExists()) {

        }
        else {
            this->createUserTable();
        }
    }
    else {
        std::cout << "unable" << std::endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::createUserTable()
{
    QString sql = "CREATE TABLE IF NOT EXISTS `product` ("
                  "`productName` varchar(1000) NOT NULL,"
                  "`productDescription` varchar(1000) NOT NULL)";
    QSqlQuery qs(this->db);
    qs.exec(sql);

}



void MainWindow::on_pushButton_clicked()
{
    QString productName = ui->productName->text();
    QString productDescription = ui->productDescription->text();
     MainWindow::StoreDataInDataBase(productName, productDescription);

}

bool MainWindow::checkTableExists() {
    bool boolean = this->db.tables().contains(MainWindow::PRODUCT_TABLE_NAME);
    return boolean;
}

void MainWindow::StoreDataInDataBase(QString productName, QString productDescription) {
    QSqlQuery query(this->db);
    query.prepare("INSERT INTO product ('productName', 'productDescription') VALUES(:pn, :pd)");

    query.bindValue(":pn", productName);
    query.bindValue(":pd", productDescription);
    bool q = query.exec();


}
