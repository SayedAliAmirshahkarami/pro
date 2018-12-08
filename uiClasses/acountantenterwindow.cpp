#include "acountantenterwindow.h"
#include "ui_acountantenterwindow.h"

AcountantEnterWindow::AcountantEnterWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcountantEnterWindow)
{
    ui->setupUi(this);

    ui->enter_btn->setIcon(QIcon("../pro1/pics/entrance.png"));
    ui->back_btn->setIcon(QIcon("../pro1/pics/back.png"));

}

AcountantEnterWindow::~AcountantEnterWindow()
{
    delete ui;
}

void AcountantEnterWindow::on_enter_btn_clicked()
{
    QString username = ui->username_lineEdit->text();
    QString password = ui->password_lineEdit->text();

    int i;
    for(i = 0;i < username.size() && username.at(i) == ' ';i++);
    username.remove(0,i);

    for(i = 0;i < password.size() && password.at(i) == ' ';i++);
    password.remove(0,i);

    if(username.isEmpty()){
        ui->reply_label->setText("نام کاربری وارد نشده است!\n");
        return;
    }
    if(password.isEmpty()){
         ui->reply_label->setText("رمزعبور وارد نشده است!\n");
         return;
    }

    if(username == "admin" && password == "1234"){
        this->close();
        AcountantWindow *acountantWindow = new AcountantWindow;
        acountantWindow->showNormal();
    }
    else{

        ui->reply_label->setText("نام کاربری یا رمزعبور وارد شده صحیح نمی باشد.");
    }
}

void AcountantEnterWindow::on_back_btn_clicked()
{
    this->close();
    MainWindow *mainWindow = new MainWindow;
    mainWindow->showNormal();
}
