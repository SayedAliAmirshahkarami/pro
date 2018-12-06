#include "acountantwindow.h"
#include "ui_acountantwindow.h"

AcountantWindow::AcountantWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AcountantWindow)
{
    ui->setupUi(this);
}

AcountantWindow::~AcountantWindow()
{
    delete ui;
}
