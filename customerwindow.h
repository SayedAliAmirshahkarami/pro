#ifndef CUSTOMERWINDOW_H
#define CUSTOMERWINDOW_H

#include <QMainWindow>

namespace Ui {
class CustomerWindow;
}

class CustomerWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CustomerWindow(QWidget *parent = 0);
    ~CustomerWindow();
    
private:
    Ui::CustomerWindow *ui;
};

#endif // CUSTOMERWINDOW_H
