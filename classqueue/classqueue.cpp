#include "classcustomer.cpp"
#include <iostream>
using namespace std;

class Queue{
private:
  Persion *front,*rear;
  int maxSize , size;
public:
  Queue(int maxSize);
  void push_rear(int value);
  int pop_front();
  void display();
  bool hasValue(int value); //for search we use this
  bool isFull();
};

//****************************************************************

Queue::Queue(int maxSize){
   front = rear = NULL;
   this->maxSize = maxSize;
   size = 0;
}

//******************************************************************

bool Queue::isFull(){
  if(size == maxSize){
    return true;
  }
  return false;
}
//*********************************************************************

void Queue::push_rear(Persion persion1){
   if(isFull()){
     cout<<"queue is full"<<endl;
     return;
   }
   size++;
   Persion *temp = new Persion();
   temp->SetName(persion1.GetName());
   temp->setNext(NULL);

   if(front){
      rear->setNext(temp);
   }
   else{
     front = temp;
   }
   rear = temp;
}


//**********************************************************************************


int Queue::pop_front(){
  if(front == NULL){
    cout<<"queue is empty"<<endl;
    return INT_MIN;
  }
  size--;
  int value = front->getData();
  front = front->GetName();

  if(front == NULL){
    rear = NULL;
  }
  return value;
}

//*******************************************************************************

bool Queue::hasValue(string name){
    Persion *persion = front;
    while(persion){
      if(persion->GetName() == name){
        return true;
      }
      persion = persion->GetNext();
    }
    return false;
}

//***********************************************************************************

void Queue::display(){
    if(front == NULL){
      cout<<"queue is empty"<<endl;
      return;
    }
    cout<<"Elements in Queue are:\n";
    Persion *persion = front;
    while(persion{
        cout<<persion->GetName()<<" ";
        Persion = Persion->GetNext();
    }
    cout<<endl;
}

//*****************************************************************************************




