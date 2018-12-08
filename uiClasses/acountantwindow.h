#ifndef ACOUNTANTWINDOW_H
#define ACOUNTANTWINDOW_H

#include <QMainWindow>
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
    BookList *bookList;
    
private slots:
    void on_addBook_btn_clicked();

    void on_back_btn_clicked();

    void on_books_tableWidget_clicked(const QModelIndex &index);

private:
    Ui::AcountantWindow *ui;
};

#endif // ACOUNTANTWINDOW_H
