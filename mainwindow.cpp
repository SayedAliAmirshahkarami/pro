#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "uiClasses/customerenterwindow.h"
#include "queue.h"

Queue maleQueue , femaleQueue;
QFile maleQueueFile("Queue/maleQueue.txt");
QFile femaleQueueFile("Queue/femaleQueue.txt");
BookList *bookList;
QFile bookListFile("BookList/bookList.txt");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->customerEnter_pbtn->setIcon(QIcon("../pro1/pics/customer.png"));
    ui->accountantEnter_pbtn->setIcon(QIcon("../pro1/pics/acountant.png"));

    bookList = new BookList();

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

    if(!maleQueueFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        if(!maleQueueFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug("maleQueueFile not Created...");

        }


    }
    else{
      if(maleQueue.isEmpty()){
        QTextStream in(&maleQueueFile);
        in.setCodec("UTF-8");
        while(!in.atEnd()){
           QString line = in.readLine();
           QStringList customerInfo = line.split(";");
           Customer *customer = new Customer(customerInfo.at(0) , 1);
           customer->increaseCost(customerInfo.at(1).toInt());

           qDebug(QString::number(customer->getCost()).toStdString().c_str());
           maleQueue.push_rear(customer);

        }
      }
    }

    maleQueueFile.close();
    if(!femaleQueueFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        if(!femaleQueueFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            qDebug("femaleQueueFile not Created...");

        }
    }
    else{
      if(femaleQueue.isEmpty()){
        QTextStream in(&femaleQueueFile);
        in.setCodec("UTF-8");
        while(!in.atEnd()){
           QString line = in.readLine();
           QStringList customerInfo = line.split(';');
           Customer *customer = new Customer(customerInfo.at(0) , 0);

           customer->increaseCost(customerInfo.at(1).toInt());
           qDebug(QString::number(customer->getCost()).toStdString().c_str());
           femaleQueue.push_rear(customer);
        }
      }
    }
    femaleQueueFile.close();


    QDir nobatDir;
    nobatDir.mkdir("Nobat");
    QFile nobatFile("Nobat/nobat.txt");
    if(!nobatFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        if(nobatFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&nobatFile);
            out<<'0';

        }
        else{
            qDebug("nobatFile not created...");

        }
    }
    nobatFile.close();

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


