#ifndef ACOUNTANTWINDOW_H
#define ACOUNTANTWINDOW_H

#include <QMainWindow>

namespace Ui {
class AcountantWindow;
}

class AcountantWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit AcountantWindow(QWidget *parent = 0);
    ~AcountantWindow();
    
private:
    Ui::AcountantWindow *ui;
};

#endif // ACOUNTANTWINDOW_H
