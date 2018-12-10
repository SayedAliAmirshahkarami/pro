#include "acountantwindow.h"
#include "ui_acountantwindow.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QStringList>
#include <QTableWidgetItem>
#include "acountantenterwindow.h"

AcountantWindow::AcountantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcountantWindow)
{
    ui->setupUi(this);
    ui->addBook_btn->setIcon(QIcon("../pro1/pics/addBook.png"));

    QDir bookListDir;
    bookListDir.mkdir("BookList");
    QFile bookListFile("BookList/bookList.txt");

    bookList = new BookList;

    if(bookListFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&bookListFile);
        int i = 0;
        in.setCodec("UTF-8");
        while(!in.atEnd()){

            QString line = in.readLine();
//            qDebug(line.toUtf8().data());

            QStringList bookInfo = line.split(';');
            for(int k = 0;k < 4;k++)
                qDebug(bookInfo.at(k).toStdString().c_str());

            Book *newBook = new Book(bookInfo.at(0) , bookInfo.at(1) ,  bookInfo.at(2).toInt() , bookInfo.at(3).toInt());

            bookList->addEnd(newBook);


            ui->books_tableWidget->insertRow(i);
                for(int j = 0;j < 4;j++){
//                    qDebug(bookInfo.at(j).toUtf8().data());
                    QTableWidgetItem *item = new QTableWidgetItem(bookInfo.at(j));

                    ui->books_tableWidget->setItem(i ,j , item);
                }

        i++;
        }

        bookListFile.close();
    }
    QHeaderView* header = ui->books_tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);

}

AcountantWindow::~AcountantWindow()
{
    delete ui;
}

void AcountantWindow::on_addBook_btn_clicked()
{
    QString title , author;
    int price , publishYear;

    title = ui->title_lineEdit->text();
    author = ui->author_lineEdit->text();

    int i;
    for(i = 0;i < title.size() && title.at(i) == ' ';i++);
    title.remove(0,i);

    if(title.isEmpty()){
        ui->addBookReply_label->setText("نام کتاب وارد نشده است!");
        return;
    }


    for(i = 0;i < author.size() && author.at(i) == ' ';i++);
    author.remove(0,i);

    if(author.isEmpty()){
        ui->addBookReply_label->setText("نام نویسنده وارد نشده است!");
        return;
    }


    QString publishYearStr = ui->publishYear_lineEdit->text();

    for(i = 0;i < publishYearStr.size() && publishYearStr.at(i) == ' ';i++);
    publishYearStr.remove(0,i);

    if(publishYearStr.isEmpty()){
        ui->addBookReply_label->setText("سال انتشار کتاب وارد نشده است!");
        return;
    }

    QString priceStr = ui->price_lineEdit->text();
    for(i = 0;i < priceStr.size() && priceStr.at(i) == ' ';i++);
    priceStr.remove(0,i);

    if(priceStr.isEmpty()){
        ui->addBookReply_label->setText("قیمت کتاب وارد نشده است!");
        return;
    }

    price = priceStr.toInt();
    publishYear = publishYearStr.toInt();


    if(title.contains(";")){
        ui->addBookReply_label->setText("در نام کتاب نباید کاراکتر ; وجود داشته باشد!");
        return;
    }

    if(author.contains(";")){
        ui->addBookReply_label->setText("در نام نویسنده نباید کاراکتر ; وجود داشته باشد!");
        return;
    }
    if(publishYear <= 0){
        ui->addBookReply_label->setText("سال انتشار کتاب صحیح وارد نشده است!");
        return;
    }

    if(price <= 0 && priceStr != "0"){
        ui->addBookReply_label->setText("مقدار قیمت کتاب صحیح وارد نشده است!");
        return;
    }

    Book* newBook = new Book(title , author , publishYear , price);
    qDebug("newBook title : ");
    qDebug(newBook->getTitle().toStdString().c_str());
    bookList->addEnd(newBook);
    bookList->display();

    ui->books_tableWidget->insertRow(ui->books_tableWidget->rowCount());

        QTableWidgetItem *item = new QTableWidgetItem(title);
        ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 0 , item);
        item = new QTableWidgetItem(author);
        ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 1 , item);
        item = new QTableWidgetItem(publishYearStr);
        ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 2 , item);
        item = new QTableWidgetItem(priceStr);
        ui->books_tableWidget->setItem(ui->books_tableWidget->rowCount() - 1 , 3 , item);

        QHeaderView* header = ui->books_tableWidget->horizontalHeader();
        header->setSectionResizeMode(QHeaderView::Stretch);
        header->setStretchLastSection(true);

    QDir bookListDir;
    bookListDir.mkdir("BookList");
    QFile bookListFile("BookList/bookList.txt");


    if (!bookListFile.open(QIODevice::Append | QIODevice::Text)){

        if(bookListFile.open(QIODevice::WriteOnly | QIODevice::Text)){
            QTextStream out(&bookListFile);
            out.setCodec("UTF-8");
            out<<title<<";"<<author<<";"<<publishYearStr<<";"<<priceStr<<"\n";
            bookListFile.close();
        }
       return;
    }


           QTextStream out(&bookListFile);
           out.setCodec("UTF-8");
           out<<title<<";"<<author<<";"<<publishYearStr<<";"<<priceStr<<"\n";
           bookListFile.close();

           ui->addBookReply_label->setText("کتاب  " + title + " با موفقیت اضافه شد ");




}

void AcountantWindow::on_back_btn_clicked()
{
    this->close();
    AcountantEnterWindow *acountantEnterWd = new AcountantEnterWindow;
    acountantEnterWd->showNormal();
}

void AcountantWindow::on_books_tableWidget_clicked(const QModelIndex &index)
{

}

void AcountantWindow::on_removeBook_btn_clicked()
{
//    ui->books_tableWidget->selectedItems().at(0)->text;
    qDebug(QString::number(ui->books_tableWidget->currentRow()).toStdString().c_str());
    bookList->remove(bookList->getBookAt(ui->books_tableWidget->currentRow()));

    ui->books_tableWidget->removeRow(ui->books_tableWidget->currentRow());
}


