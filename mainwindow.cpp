#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountantEnter_pbtn_clicked()
{
   this->close();
   AcountantWindow *acountantWindow = new AcountantWindow;
   acountantWindow->showNormal();
}

void MainWindow::on_customerEnter_pbtn_clicked()
{
    this->close();
    CustomerEnterWindow *customerEnterWindow = new CustomerEnterWindow;
    customerEnterWindow->showNormal();
}
