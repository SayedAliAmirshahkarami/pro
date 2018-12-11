#include "acountantwindow.h"
#include "ui_acountantwindow.h"
#include "queue.h"
#include <QMessageBox>

extern Queue maleQueue , femaleQueue;
extern QFile maleQueueFile , femaleQueueFile;
extern BookList *bookList;
extern QFile bookListFile;

AcountantWindow::AcountantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcountantWindow)
{
    ui->setupUi(this);
    ui->addBook_btn->setIcon(QIcon("../pro1/pics/addBook.png"));
    ui->removeBook_btn->setIcon(QIcon("../pro1/pics/removeBook.png"));
    ui->back_btn->setIcon(QIcon("../pro1/pics/back.png"));
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

            QStringList bookInfo = line.split(';');


            if(wasEmpty == true){
               Book *newBook = new Book(bookInfo.at(0) , bookInfo.at(1) ,  bookInfo.at(2).toInt() , bookInfo.at(3).toInt());

               bookList->addEnd(newBook);
            }

            ui->books_tableWidget->insertRow(i);

                for(int j = 0;j < 4;j++){

                    QTableWidgetItem *item = new QTableWidgetItem(bookInfo.at(j));

                    ui->books_tableWidget->setItem(i ,j , item);
                }

        i++;
        }
        bookList->display();

        bookListFile.close();
        }

    QHeaderView* header = ui->books_tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);

    QTableWidgetItem *newItem;

    qDebug(QString::number(maleQueue.getSize()).toStdString().c_str());

    if(maleQueue.getSize()){
        Customer *maleCustomer = maleQueue.getFrontCustomer();
        for(int i = 0;i < maleQueue.getSize();i++){
            ui->maleQueue_tableWidget->insertRow(i);
            newItem = new QTableWidgetItem(maleCustomer->getName());
            ui->maleQueue_tableWidget->setItem(i , 0 , newItem);
            qDebug("male customer cost : ");
            qDebug(QString::number(maleCustomer->getCost()).toStdString().c_str());
            qDebug(maleCustomer->getName().toStdString().c_str());

            newItem = new QTableWidgetItem(QString::number(maleCustomer->getCost()));
            ui->maleQueue_tableWidget->setItem(i , 1 , newItem);
            maleCustomer = maleCustomer->getNext();
        }
    }
    header = ui->maleQueue_tableWidget->horizontalHeader();
    header->setSectionResizeMode(QHeaderView::Stretch);
    header->setStretchLastSection(true);

    if(femaleQueue.getSize()){
        Customer *femaleCustomer = femaleQueue.getFrontCustomer();
        for(int i = 0;i < femaleQueue.getSize();i++){
            ui->femaleQueue_tableWidget->insertRow(i);
            newItem = new QTableWidgetItem(femaleCustomer->getName());
            ui->femaleQueue_tableWidget->setItem(i , 0 , newItem);
            newItem = new QTableWidgetItem(QString::number(femaleCustomer->getCost()));
            ui->femaleQueue_tableWidget->setItem(i , 1 , newItem);
            femaleCustomer = femaleCustomer->getNext();
        }
    }
    header = ui->femaleQueue_tableWidget->horizontalHeader();
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
        ui->changeBookListReply_label->setText("نام کتاب وارد نشده است!");
        return;
    }


    for(i = 0;i < author.size() && author.at(i) == ' ';i++);
    author.remove(0,i);

    if(author.isEmpty()){
        ui->changeBookListReply_label->setText("نام نویسنده وارد نشده است!");
        return;
    }


    QString publishYearStr = ui->publishYear_lineEdit->text();

    for(i = 0;i < publishYearStr.size() && publishYearStr.at(i) == ' ';i++);
    publishYearStr.remove(0,i);

    if(publishYearStr.isEmpty()){
        ui->changeBookListReply_label->setText("سال انتشار کتاب وارد نشده است!");
        return;
    }

    QString priceStr = ui->price_lineEdit->text();
    for(i = 0;i < priceStr.size() && priceStr.at(i) == ' ';i++);
    priceStr.remove(0,i);

    if(priceStr.isEmpty()){
        ui->changeBookListReply_label->setText("قیمت کتاب وارد نشده است!");
        return;
    }

    price = priceStr.toInt();
    publishYear = publishYearStr.toInt();


    if(title.contains(";")){
        ui->changeBookListReply_label->setText("در نام کتاب نباید کاراکتر ; وجود داشته باشد!");
        return;
    }

    if(author.contains(";")){
        ui->changeBookListReply_label->setText("در نام نویسنده نباید کاراکتر ; وجود داشته باشد!");
        return;
    }
    if(publishYear <= 0){
        ui->changeBookListReply_label->setText("سال انتشار کتاب صحیح وارد نشده است!");
        return;
    }

    if(price <= 0 && priceStr != "0"){
        ui->changeBookListReply_label->setText("مقدار قیمت کتاب صحیح وارد نشده است!");
        return;
    }

    Book* newBook = new Book(title , author , publishYear , price);

    bookList->addEnd(newBook);

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




     if (bookListFile.open(QIODevice::Append | QIODevice::Text)){

           QTextStream out(&bookListFile);
           out.setCodec("UTF-8");
           out<<title<<";"<<author<<";"<<publishYearStr<<";"<<priceStr<<"\n";
           bookListFile.close();

           ui->changeBookListReply_label->setText("کتاب  " + title + " با موفقیت اضافه شد ");

      }


}

void AcountantWindow::on_back_btn_clicked()
{
    this->close();
    AcountantEnterWindow *acountantEnterWd = new AcountantEnterWindow;
    acountantEnterWd->showNormal();
}



void AcountantWindow::on_removeBook_btn_clicked()
{
    if(ui->books_tableWidget->rowCount()){
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
             ui->changeBookListReply_label->setText("کتاب " + rmBookStr +  "از لیست کتاب ها حذف شد!");
             bookListFile.close();
         }
    }
}



void AcountantWindow::on_calculateCost_btn_clicked()
{
    QFile nobatFile("Nobat/nobat.txt");
    Customer *frontCustomer;
    if(nobatFile.open(QIODevice::ReadWrite | QIODevice::Text)){
        QTextStream inOut(&nobatFile);
        char nobatChar;
        inOut>>nobatChar;
        inOut.seek(0);
        if(maleQueue.isEmpty()){
           inOut<<'0';
           inOut.seek(0);
           nobatChar = '0';
        }
        if(femaleQueue.isEmpty()){
            inOut<<'1';
            inOut.seek(0);
            nobatChar = '1';
        }
        if(nobatChar == '1'){

          frontCustomer = maleQueue.pop_front();

           if(maleQueueFile.open(QIODevice::WriteOnly | QIODevice::Text)){
               QTextStream qOut(&maleQueueFile);
               qOut.setCodec("UTF-8");
               Customer* customer = maleQueue.getFrontCustomer();
               for(int i = 0;i < maleQueue.getSize();i++){
                   qOut<<customer->getName()<<";"<<customer->getCost()<<"\n";
                   customer = customer->getNext();
               }
            maleQueueFile.close();
           }

           ui->maleQueue_tableWidget->removeRow(0);
           inOut<<'0';
        }
        else if(nobatChar == '0'){
           frontCustomer = femaleQueue.pop_front();
           if(femaleQueueFile.open(QIODevice::WriteOnly | QIODevice::Text)){
               QTextStream qOut(&femaleQueueFile);
               qOut.setCodec("UTF-8");
               Customer* customer = femaleQueue.getFrontCustomer();
               for(int i = 0;i < femaleQueue.getSize();i++){
                   qOut<<customer->getName()<<";"<<customer->getCost()<<"\n";
                   customer = customer->getNext();
               }
               femaleQueueFile.close();
           }
           ui->femaleQueue_tableWidget->removeRow(0);

           inOut<<'1';
        }

     nobatFile.close();
    }
    if(frontCustomer){
      QMessageBox msgBox;

      msgBox.setText( "مبلغ قابل پرداخت  " + QString::number(frontCustomer->getCost()) );

      msgBox.showNormal();
      msgBox.exec();
    }

}

void AcountantWindow::on_sortByName_btn_clicked()
{

    bool swapped;
    for(int i = 0;i < bookList->getBooksNumber() - 1;i++){
        swapped = false;
        for(int j = 0;j < bookList->getBooksNumber() - i - 1;j++){
            if(QString::compare(bookList->getBookAt(j)->getTitle() , bookList->getBookAt(j + 1)->getTitle()) > 0){
                QString tempTitle = bookList->getBookAt(j)->getTitle();
                bookList->getBookAt(j)->setTitle(bookList->getBookAt(j + 1)->getTitle());
                bookList->getBookAt(j + 1)->setTitle(tempTitle);
                QString tempAuthor = bookList->getBookAt(j)->getAuthor();
                bookList->getBookAt(j)->setAuthor(bookList->getBookAt(j + 1)->getAuthor());
                bookList->getBookAt(j + 1)->setAuthor(tempAuthor);
                int tempPublishYear = bookList->getBookAt(j)->getPublishYear();
                bookList->getBookAt(j)->setPublishYear(bookList->getBookAt(j + 1)->getPublishYear());
                bookList->getBookAt(j + 1)->setPublishYear(tempPublishYear);
                int tempPrice = bookList->getBookAt(j)->getPrice();
                bookList->getBookAt(j)->setPrice(bookList->getBookAt(j + 1)->getPrice());
                bookList->getBookAt(j + 1)->setPrice(tempPrice);
                swapped = true;
           }
        }
        if (swapped == false)
            break;
    }
    for(int i = 0;i < bookList->getBooksNumber();i++){
        ui->books_tableWidget->removeRow(0);
    }
    QTableWidgetItem *item;
    for(int i = 0;i < bookList->getBooksNumber();i++){
        ui->books_tableWidget->insertRow(i);
        item = new QTableWidgetItem(bookList->getBookAt(i)->getTitle());
        ui->books_tableWidget->setItem(i , 0 , item);
        item = new QTableWidgetItem(bookList->getBookAt(i)->getAuthor());
        ui->books_tableWidget->setItem(i , 1 , item);
        item = new QTableWidgetItem(QString::number(bookList->getBookAt(i)->getPublishYear()));
        ui->books_tableWidget->setItem(i , 2 , item);
        item = new QTableWidgetItem(QString::number(bookList->getBookAt(i)->getPrice()));
        ui->books_tableWidget->setItem(i , 3 , item);
    }

}

void AcountantWindow::on_sortByPublishYear_btn_clicked()
{
    bool swapped;
    for(int i = 0;i < bookList->getBooksNumber() - 1;i++){
        swapped = false;
        for(int j = 0;j < bookList->getBooksNumber() - i - 1;j++){
            if(bookList->getBookAt(j)->getPublishYear() > bookList->getBookAt(j + 1)->getPublishYear()){
                QString tempTitle = bookList->getBookAt(j)->getTitle();
                bookList->getBookAt(j)->setTitle(bookList->getBookAt(j + 1)->getTitle());
                bookList->getBookAt(j + 1)->setTitle(tempTitle);
                QString tempAuthor = bookList->getBookAt(j)->getAuthor();
                bookList->getBookAt(j)->setAuthor(bookList->getBookAt(j + 1)->getAuthor());
                bookList->getBookAt(j + 1)->setAuthor(tempAuthor);
                int tempPublishYear = bookList->getBookAt(j)->getPublishYear();
                bookList->getBookAt(j)->setPublishYear(bookList->getBookAt(j + 1)->getPublishYear());
                bookList->getBookAt(j + 1)->setPublishYear(tempPublishYear);
                int tempPrice = bookList->getBookAt(j)->getPrice();
                bookList->getBookAt(j)->setPrice(bookList->getBookAt(j + 1)->getPrice());
                bookList->getBookAt(j + 1)->setPrice(tempPrice);
                swapped = true;
           }
        }
        if (swapped == false)
            break;
    }
    for(int i = 0;i < bookList->getBooksNumber();i++){
        ui->books_tableWidget->removeRow(0);
    }
    QTableWidgetItem *item;
    for(int i = 0;i < bookList->getBooksNumber();i++){
        ui->books_tableWidget->insertRow(i);
        item = new QTableWidgetItem(bookList->getBookAt(i)->getTitle());
        ui->books_tableWidget->setItem(i , 0 , item);
        item = new QTableWidgetItem(bookList->getBookAt(i)->getAuthor());
        ui->books_tableWidget->setItem(i , 1 , item);
        item = new QTableWidgetItem(QString::number(bookList->getBookAt(i)->getPublishYear()));
        ui->books_tableWidget->setItem(i , 2 , item);
        item = new QTableWidgetItem(QString::number(bookList->getBookAt(i)->getPrice()));
        ui->books_tableWidget->setItem(i , 3 , item);
    }
}
