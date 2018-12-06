#include "classcustomer.cpp"
#include <iostream>
using namespace std;
class Queue{
private:
  Persion *front,*rear;
  int maxSize , size;
public:
  Queue(int maxSize);
  void push_rear(Persion);
  Persion* pop_front();
  void display();
  bool hasValue(string name); //for search we use this
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
   temp->SetNext(NULL);

   if(front){
      rear->SetNext(temp);
   }
   else{
     front = temp;
   }
   rear = temp;
}


//**********************************************************************************


Persion* Queue::pop_front(){
  if(front == NULL){
    cout<<"queue is empty"<<endl;
   // return 0;
  }
  size--;
  string name1 = front->GetName();
  front = front->GetNext();

  if(front == NULL){
    rear = NULL;
  }
  return front;
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
    while(persion){
        cout<<persion->GetName()<<endl;
        persion = persion->GetNext();
    }
    cout<<endl;
}

//*****************************************************************************************

