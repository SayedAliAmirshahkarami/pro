#include <iostream>
#include <climits>
#include <map>

using namespace std;

class CircularQueue{
private:
  int rear , front;
  int *arr;
  int maxSize;

public:
  CircularQueue(int maxSize);
  void push_rear(int value);
  int pop_front();
  void display();
};

CircularQueue::CircularQueue(int maxSize){
  this->maxSize = maxSize + 1;
  front = 0;
  rear = 0;
  arr = new int[this->maxSize];
}

void CircularQueue::push_rear(int value){

     if (front == (rear + 1) % maxSize) {
         cout<<"queue is full"<<endl;
         return;
     }
     else {
         rear = (rear + 1) % maxSize;
         arr[rear] = value;
     }
}

int CircularQueue::pop_front(){
  if(rear == front){
    cout<<"queue is empty"<<endl;
    return INT_MIN;
  }
  else{
    front = (front + 1) % maxSize;
    int frontElement = arr[front];
    arr[front] = INT_MIN;
    return frontElement;
  }
}

void CircularQueue::display(){
  if (front == rear){
        cout<<"queue is empty"<<endl;
        return;
  }
    cout<<"Elements in Circular Queue are: "<<endl;
    if (rear >= front) {
        for (int i = front + 1; i <= rear; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    else{
        for (int i = front + 1; i < maxSize; i++)
            cout<<arr[i]<<" ";

        for (int i = 0; i <= rear; i++)
            cout<<arr[i]<<" ";

        cout<<endl;
    }
}
