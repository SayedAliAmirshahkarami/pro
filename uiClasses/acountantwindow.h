#ifndef ACOUNTANTWINDOW_H
#define ACOUNTANTWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QTableWidgetItem>
#include "acountantenterwindow.h"
#include "../bookClasses/booklist.h"

namespace Ui {
class AcountantWindow;
}

class AcountantWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AcountantWindow(QWidget *parent = 0);
    ~AcountantWindow();

private slots:
    void on_addBook_btn_clicked();

    void on_back_btn_clicked();

    void on_removeBook_btn_clicked();



private:
    Ui::AcountantWindow *ui;
};

#endif // ACOUNTANTWINDOW_H
