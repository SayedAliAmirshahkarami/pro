#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QMainWindow>
#include "customerenterwindow.h"
#include "customer.h"

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CustomerWindow(QWidget *parent = 0);
    ~CustomerWindow();
    Customer *customer;
    
private slots:
    void on_back_btn_clicked();

    void on_addBookToStack_btn_clicked();

    void on_finish_btn_clicked();

    void on_removeFromStack_btn_clicked();

private:
    Ui::CustomerWindow *ui;
};

#endif // CUSTOMERWINDOW_H



