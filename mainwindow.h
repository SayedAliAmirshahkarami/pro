#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include "uiClasses/customerenterwindow.h"
#include "uiClasses/acountantenterwindow.h"
#include <QIcon>
#include <QDir>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_accountantEnter_pbtn_clicked();

    void on_customerEnter_pbtn_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
