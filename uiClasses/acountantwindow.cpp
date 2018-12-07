#include "acountantwindow.h"
#include "ui_acountantwindow.h"

AcountantWindow::AcountantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcountantWindow)
{
    ui->setupUi(this);
    ui->addBook_btn->setIcon(QIcon("../pro1/pics/addBook.png"));
}

AcountantWindow::~AcountantWindow()
{
    delete ui;
}
