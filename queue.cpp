#include "queue.h"
#include <QMessageBox>
#include "Customer.h"
#include "uiClasses/customerwindow.h"


Queue::Queue()
{
       front = rear = NULL;
       size = 0;
}

Customer* Queue::getFrontCustomer(){
    return front;
}

bool Queue::isEmpty(){
    if(front == NULL){
        return true;
    }
    else
        return false;
}

int Queue::getSize(){
    return size;
}
    void Queue::push_rear(Customer *customer){

           size++;
           Customer *temp = new Customer(customer);

           if(front){
              rear->setNext(temp);
           }
           else{
             front = temp;
           }
           rear = temp;
    }


    Customer* Queue::pop_front(){
        if(isEmpty()){
           return NULL;
          }
          size--;

          Customer* temp=front;

          front = front->getNext();


          if(front == NULL){
            rear = NULL;
          }
          return temp;

    }
