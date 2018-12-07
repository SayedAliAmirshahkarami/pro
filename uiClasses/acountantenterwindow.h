#ifndef ACOUNTANTENTERWINDOW_H
#define ACOUNTANTENTERWINDOW_H

#include <QMainWindow>
#include "acountantwindow.h"
#include "../mainwindow.h"

namespace Ui {
class AcountantEnterWindow;
}

class AcountantEnterWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AcountantEnterWindow(QWidget *parent = 0);
    ~AcountantEnterWindow();
    
private slots:
    void on_enter_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::AcountantEnterWindow *ui;
};

#endif // ACOUNTANTENTERWINDOW_H
