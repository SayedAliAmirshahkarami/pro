#include "customer.h"

Customer::Customer(QString name,int type)
{

       this->name=name;
       this->type=type;

}

Customer::Customer(Customer *customer){
    this->name = customer->getName();
    this->type = customer->getType();
    this->next = NULL;

}

    Customer*Customer::getNext(){
        return next;

    }
    QString Customer::getName(){
        return name;
    }

    int Customer::getType(){
        return type;
    }

    void Customer::setName(QString name){
        this->name=name;
    }
    void Customer::setType(int type){
        this->type=type;
    }
    void Customer::setNext(Customer* customer){
        this->next=customer;
    }
