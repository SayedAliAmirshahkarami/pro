#include "customerwindow.h"
#include "ui_customerwindow.h"
#include "customer.h"
#include "queue.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include "../bookClasses/bookList.h"
#include <QMessageBox>

extern int type;
extern QString nameStr;
extern Queue maleQueue , femaleQueue;
extern QFile maleQueueFile;
extern QFile femaleQueueFile;
extern BookList *bookList;
extern QFile bookListFile;

CustomerWindow::CustomerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerWindow)
{
    ui->setupUi(this);
    ui->back_btn->setIcon(QIcon("../pro1/pics/back.png"));


    customer = new Customer(nameStr , type);

    bool wasEmpty;
if(bookList->isEmpty()){
    wasEmpty = true;
}
else{
   wasEmpty = false;
}
    if(bookListFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&bookListFile);
        int i = 0;
        in.setCodec("UTF-8");
        while(!in.atEnd()){

            QString line = in.readLine();
//            qDebug(line.toUtf8().data());

            QStringList bookInfo = line.split(';');
//            for(int k = 0;k < 4;k++)
//                qDebug(bookInfo.at(k).toStdString().c_str());
            if(wasEmpty == true){
              Book *newBook = new Book(bookInfo.at(0) , bookInfo.at(1) ,  bookInfo.at(2).toInt() , bookInfo.at(3).toInt());

               bookList->addEnd(newBook);
            }

            ui->books_tableWidget->insertRow(i);
            QTableWidgetItem *item;
                for(int j = 0;j < 4;j++){
//                    qDebug(bookInfo.at(j).toUtf8().data());
                    item = new QTableWidgetItem(bookInfo.at(j));

                    ui->books_tableWidget->setItem(i ,j , item);
                }
                item = new QTableWidgetItem("+");
                ui->books_tableWidget->setItem(i , 4 , item);

        i++;
        }
        bookList->display();

        bookListFile.close();
    }

    QHeaderView* header = ui->books_tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);





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



void CustomerWindow::on_addBookToStack_btn_clicked()
{
    if(ui->books_tableWidget->rowCount()){

        customer->getBookStack()->push(bookList->getBookAt(ui->books_tableWidget->currentRow()));

        QString rmBookStr = bookList->getBookAt(ui->books_tableWidget->currentRow())->getTitle();
        bookList->remove(bookList->getBookAt(ui->books_tableWidget->currentRow()));
         qDebug("remove");
         bookList->display();
         ui->books_tableWidget->removeRow(ui->books_tableWidget->currentRow());
         if(bookListFile.open(QIODevice::WriteOnly | QIODevice::Text)){
             QTextStream out(&bookListFile);
             out.setCodec("UTF-8");
             for(int i = 0;i < bookList->getBooksNumber();i++){
                 qDebug(QString::number(i).toStdString().c_str());
                 out<<bookList->getBookAt(i)->getTitle()<<";"<<bookList->getBookAt(i)->getAuthor()<<";"<<bookList->getBookAt(i)->getPublishYear()<<";"<<bookList->getBookAt(i)->getPrice()<<"\n";
             }
             ui->addToStackReply_label->setText(" کتاب " + rmBookStr +  " به سبد خرید اضافه شد!");
             
             ui->bookStack_tableWidget->insertRow(ui->bookStack_tableWidget->rowCount());

                 QTableWidgetItem *item = new QTableWidgetItem(customer->getBookStack()->getTopBook()->getTitle());
                 ui->bookStack_tableWidget->setItem(ui->bookStack_tableWidget->rowCount() - 1 , 0 , item);
                 item = new QTableWidgetItem(customer->getBookStack()->getTopBook()->getAuthor());
                 ui->bookStack_tableWidget->setItem(ui->bookStack_tableWidget->rowCount() - 1 , 1 , item);
                 item = new QTableWidgetItem(QString::number(customer->getBookStack()->getTopBook()->getPublishYear()));
                 ui->bookStack_tableWidget->setItem(ui->bookStack_tableWidget->rowCount() - 1 , 2 , item);
                 item = new QTableWidgetItem(QString::number(customer->getBookStack()->getTopBook()->getPrice()));
                 ui->bookStack_tableWidget->setItem(ui->bookStack_tableWidget->rowCount() - 1 , 3 , item);

                 QHeaderView* header = ui->bookStack_tableWidget->horizontalHeader();
                 header->setSectionResizeMode(QHeaderView::Stretch);
                 header->setStretchLastSection(true);

             bookListFile.close();
         }
    }
}

void CustomerWindow::on_finish_btn_clicked()
{


    if(type == 1){



        if(maleQueueFile.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&maleQueueFile);
            out.setCodec("UTF-8");
            while(customer->getBookStack()->getTopBook()){
                customer->increaseCost(customer->getBookStack()->pop()->getPrice());
            }
            maleQueue.push_rear(customer);
            out<<nameStr<<";"<<QString::number(customer->getCost())<<"\n";

         maleQueueFile.close();
        }
    }
    else if(type == 0){


        if(femaleQueueFile.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&femaleQueueFile);
            out.setCodec("UTF-8");
            while(customer->getBookStack()->getTopBook()){
                customer->increaseCost(customer->getBookStack()->pop()->getPrice());
            }
            femaleQueue.push_rear(customer);
            out<<nameStr<<";"<<QString::number(customer->getCost())<<"\n";

         femaleQueueFile.close();
        }
    }
    QMessageBox msgBox;

    msgBox.setText(" شما وارد صف شدید! " );

    msgBox.showNormal();
    msgBox.exec();

    this->close();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->showNormal();
}

void CustomerWindow::on_removeFromStack_btn_clicked(){

    if(ui->bookStack_tableWidget->rowCount()){

        if(bookListFile.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&bookListFile);
            out.setCodec("UTF-8");

                out<<customer->getBookStack()->getTopBook()->getTitle()<<";"<<customer->getBookStack()->getTopBook()->getAuthor()<<";"<<customer->getBookStack()->getTopBook()->getPublishYear()<<";"<<customer->getBookStack()->getTopBook()->getPrice()<<"\n";
        bookListFile.close();
        }
            ui->removeFromStackReply_label->setText(" کتاب " + customer->getBookStack()->getTopBook()->getTitle() +  " از سبدخرید حذف شد!");

            ui->books_tableWidget->insertRow(ui->books_tableWidget->rowCount());

                QTableWidgetItem *item = new QTableWidgetItem(customer->getBookStack()->getTopBook()->getTitle());
                ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 0 , item);
                item = new QTableWidgetItem(customer->getBookStack()->getTopBook()->getAuthor());
                ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 1 , item);
                item = new QTableWidgetItem(QString::number(customer->getBookStack()->getTopBook()->getPublishYear()));
                ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 2 , item);
                item = new QTableWidgetItem(QString::number(customer->getBookStack()->getTopBook()->getPrice()));
                ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 3 , item);

                QHeaderView* header = ui->books_tableWidget->horizontalHeader();
                header->setSectionResizeMode(QHeaderView::Stretch);
                header->setStretchLastSection(true);


         bookList->addEnd(customer->getBookStack()->pop());

         ui->bookStack_tableWidget->removeRow(ui->bookStack_tableWidget->rowCount() - 1);


    }
}
