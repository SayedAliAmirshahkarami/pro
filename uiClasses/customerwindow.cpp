#include "customerwindow.h"
#include "ui_customerwindow.h"

CustomerWindow::CustomerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWindow)
{
    ui->setupUi(this);
    ui->back_btn->setIcon(QIcon("../pro1/pics/back_1.png"));

}

CustomerWindow::~CustomerWindow()
{
    delete ui;
}

void CustomerWindow::on_back_btn_clicked()
{
    this->close();
    CustomerEnterWindow *cstEnterWindow = new CustomerEnterWindow;
    cstEnterWindow->showNormal();
}
