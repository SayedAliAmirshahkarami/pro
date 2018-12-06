#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QFile::copy("../pro1/pics/customer_3.png","customer_3.png");
    QFile::copy("../pro1/pics/acountant_2.png","acountant_2.png");
    QFile::copy("../pro1/pics/bookStore_2.jpg" , "bookStore.jpg");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
