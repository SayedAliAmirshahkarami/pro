#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customerEnter_pbtn->setIcon(QIcon("../pro1/pics/customer_3.png"));
    ui->accountantEnter_pbtn->setIcon(QIcon("../pro1/pics/acountant_2.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_accountantEnter_pbtn_clicked()
{
   this->close();
   AcountantEnterWindow *acountantEnterWindow = new AcountantEnterWindow;
   acountantEnterWindow->showNormal();
}

void MainWindow::on_customerEnter_pbtn_clicked()
{
    this->close();
    CustomerEnterWindow *customerEnterWindow = new CustomerEnterWindow;
    customerEnterWindow->showNormal();
}


