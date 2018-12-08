#include "mainwindow.h"
#include "ui_mainwindow.h"
//موقت
#include "uiClasses/customerwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customerEnter_pbtn->setIcon(QIcon("../pro1/pics/customer.png"));
    ui->accountantEnter_pbtn->setIcon(QIcon("../pro1/pics/acountant.png"));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountantEnter_pbtn_clicked()
{
//   this->close();
//   AcountantEnterWindow *acountantEnterWindow = new AcountantEnterWindow;
//   acountantEnterWindow->showNormal();
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


