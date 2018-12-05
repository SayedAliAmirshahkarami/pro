#include <iostream>
#include <climits>

using namespace std;

class Node{
private:
  int data;
  Node *next;
public:
  int getData();
  Node* getNext();
  void setData(int value);
  void setNext(Node *node);
};

int Node::getData(){
  return data;
}

Node* Node::getNext(){
  return next;
}

void Node::setData(int value){
  data = value;
}

void Node::setNext(Node *node){
  next = node;
}

class Queue{
private:
  Node *front,*rear;
  int maxSize , size;
public:
  Queue(int maxSize);
  void push_rear(int value);
  int pop_front();
  void display();
  bool hasValue(int value);
  bool isFull();
};

Queue::Queue(int maxSize){
   front = rear = NULL;
   this->maxSize = maxSize;
   size = 0;
}

bool Queue::isFull(){
  if(size == maxSize){
    return true;
  }
  return false;
}

void Queue::push_rear(int value){
   if(isFull()){
     cout<<"queue is full"<<endl;
     return;
   }
   size++;
   Node *temp = new Node();
   temp->setData(value);
   temp->setNext(NULL);

   if(front){
      rear->setNext(temp);
   }
   else{
     front = temp;
   }
   rear = temp;
}

int Queue::pop_front(){
  if(front == NULL){
    cout<<"queue is empty"<<endl;
    return INT_MIN;
  }
  size--;
  int value = front->getData();
  front = front->getNext();

  if(front == NULL){
    rear = NULL;
  }
  return value;
}

bool Queue::hasValue(int value){
    Node *node = front;
    while(node){
      if(node->getData() == value){
        return true;
      }
      node = node->getNext();
    }
    return false;
}

void Queue::display(){
    if(front == NULL){
      cout<<"queue is empty"<<endl;
      return;
    }
    cout<<"Elements in Queue are:\n";
    Node *node = front;
    while(node){
        cout<<node->getData()<<" ";
        node = node->getNext();
    }
    cout<<endl;
}


int main(){

  int capacity;
  cin>>capacity;
  int index;
  Queue queue(capacity);
  int pageFaultNum = 0;
  while(1){
    cin>>index;
    if(queue.hasValue(index) == false){
       pageFaultNum++;
       if(queue.isFull()){
          queue.pop_front();
          queue.push_rear(index);
       }
       else{
         queue.push_rear(index);
       }
    }

    if(cin.get() == '\n'){
      break;
    }
  }
  cout<<pageFaultNum;
  return 0;
}
