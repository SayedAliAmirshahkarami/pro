#include "mainwindow.h"
#include "ui_mainwindow.h"
//موقت
#include "uiClasses/customerwindow.h"
#include "queue.h"

Queue maleQueue , femaleQueue;
QFile maleQueueFile("Queue/maleQueue.txt");
QFile femaleQueueFile("Queue/femaleQueue.txt");
BookList bookList;
QFile bookListFile("BookList/bookList.txt");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customerEnter_pbtn->setIcon(QIcon("../pro1/pics/customer.png"));
    ui->accountantEnter_pbtn->setIcon(QIcon("../pro1/pics/acountant.png"));

    QDir bookListDir;
    bookListDir.mkdir("BookList");

    if(!bookListFile.open(QIODevice::Append | QIODevice::Text)){
        if(!bookListFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug("bookListFile not created...");

        }

    }
    bookListFile.close();


    QDir queueDir;
    queueDir.mkdir("Queue");

    if(!maleQueueFile.open(QIODevice::Append | QIODevice::Text)){
        if(!maleQueueFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug("maleQueueFile not Created...");

        }


    }
    maleQueueFile.close();
    if(!femaleQueueFile.open(QIODevice::Append | QIODevice::Text)){
        if(!femaleQueueFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug("femaleQueueFile not Created...");

        }
    }
    femaleQueueFile.close();

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


