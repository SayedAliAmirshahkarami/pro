#include "customer.h"

Customer::Customer(QString name,int type)
{
       bookStack = new BookStack();
       this->name=name;
       this->type=type;
       cost = 0;

}

Customer::Customer(Customer *customer){
    this->bookStack = customer->getBookStack();
    this->name = customer->getName();
    this->type = customer->getType();
    this->next = NULL;
    cost = customer->getCost();

}

int Customer::getCost(){
    return cost;
}
void Customer::increaseCost(int amount){
    cost += amount;
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

    BookStack* Customer::getBookStack(){
        return bookStack;
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
