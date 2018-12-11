#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QString>
#include "bookstack.h"


class Customer
{
private:
    QString name;
    int type;
    BookStack *bookStack;
    Customer *next;
public:
    Customer (QString name,int type);
    Customer (Customer *);
    Customer * getNext();
    QString getName();
    int getType();
    BookStack* getBookStack();
    void setType(int);
    void setName(QString);
    void setNext(Customer*Customer);

};

#endif // CUSTOMER_H
