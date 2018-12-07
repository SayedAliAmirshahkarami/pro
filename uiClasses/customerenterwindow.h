#ifndef CUSTOMERENTERWINDOW_H
#define CUSTOMERENTERWINDOW_H

#include <QMainWindow>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QChar>
#include "customerwindow.h"
#include "../mainwindow.h"

namespace Ui {
class CustomerEnterWindow;
}

class CustomerEnterWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CustomerEnterWindow(QWidget *parent = 0);
    ~CustomerEnterWindow();
    
private slots:
    void on_enter_btn_clicked();

    void on_back_btn_clicked();

private:
    Ui::CustomerEnterWindow *ui;
};

#endif // CUSTOMERENTERWINDOW_H


