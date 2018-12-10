#include "queue.h"
#include <QMessageBox>
#include "Customer.h"
#include "uiClasses/customerwindow.h"


Queue::Queue()
{
       front = rear = NULL;

}
    void Queue::push_rear(Customer *customer){


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
        if(front == NULL){
            QMessageBox msgBox;
            msgBox.setText("the queue is empty().");
            msgBox.exec();

          }

          Customer* temp=front;

          front = front->getNext();


          if(front == NULL){
            rear = NULL;
          }
          return temp;

    }
