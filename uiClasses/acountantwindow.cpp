#include "acountantwindow.h"
#include "ui_acountantwindow.h"
#include <QFile>
#include <QDir>
#include <QTextStream>
#include "acountantenterwindow.h"

AcountantWindow::AcountantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcountantWindow)
{
    ui->setupUi(this);
    ui->addBook_btn->setIcon(QIcon("../pro1/pics/addBook.png"));
    ui->books_tableWidget->insertRow(0);

    QDir bookListDir;
    bookListDir.mkdir("BookList");
    QFile bookListFile("BookList/bookList.txt");

    bookList = new BookList;

    if(bookListFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&bookListFile);
        while(!in.atEnd()){
            QString bookInfo = in.readLine();


//            for(int i = 0;bookInfo.at(i) != ";";i++){


//            }

        }
    }

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
