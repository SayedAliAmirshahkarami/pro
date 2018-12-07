#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
//    QFile::copy("../pro1/pics/customer_3.png","customer.png");
//    QFile::copy("../pro1/pics/acountant_2.png","acountant.png");
//    QFile::copy("../pro1/pics/bookStore_2.jpg" , "bookStore.jpg");
//    QFile::copy("../pro1/pics/entrance_2.png" , "entrance.png");
//    QFile::copy("../pro1/pics/back_1.png" , "back.png");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
