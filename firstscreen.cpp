#include "firstscreen.h"
#include "ui_firstscreen.h"

firstScreen::firstScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::firstScreen)
{
    ui->setupUi(this);
}

firstScreen::~firstScreen()
{
    delete ui;
}
