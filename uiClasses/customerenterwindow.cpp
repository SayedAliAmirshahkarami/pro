#include "customerenterwindow.h"
#include "ui_customerenterwindow.h"

CustomerEnterWindow::CustomerEnterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CustomerEnterWindow)
{
    ui->setupUi(this);
}

CustomerEnterWindow::~CustomerEnterWindow()
{
    delete ui;
}

void CustomerEnterWindow::on_enter_btn_clicked()
{
    if(ui->name_lineEdit->text() == ""){
        ui->reply_label->setText("نام و نام خانوادگی وارد نشده \n لطفا نام و نام خانوادگی خود را وارد کنید");
        return;
    }
    QDir enteredCustomersDir;
    enteredCustomersDir.mkdir("enteredCustomers");
    QFile enteredCustomersFile("enteredCustomers/enteredCustomers.txt");
    if(enteredCustomersFile.open(QIODevice::Append)){
        QTextStream out(&enteredCustomersFile);
        out<<ui->name_lineEdit<<'\n';

    }
}
