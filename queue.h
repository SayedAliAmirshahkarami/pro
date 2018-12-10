#ifndef QUEUE_H
#define QUEUE_H

#include <QString>
#include "customer.h"

class Queue
{
private:
  Customer *front,*rear;
public:
  Queue();
  void push_rear(Customer *customer);
  Customer* pop_front();
  void display();
  bool hasValue(QString name); //for search we use this

};

#endif // QUEUE_H
