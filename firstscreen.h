#ifndef FIRSTSCREEN_H
#define FIRSTSCREEN_H

#include <QMainWindow>

namespace Ui {
class firstScreen;
}

class firstScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit firstScreen(QWidget *parent = nullptr);
    ~firstScreen();

private:
    Ui::firstScreen *ui;
};

#endif // FIRSTSCREEN_H
