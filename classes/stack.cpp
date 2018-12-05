#include <iostream>

using namespace std;

class Node{
private:
  int *arr;
  Node *next;
  int arrSize;
public:
  Node(int arraySize);
  int* getArray();
  Node* getNext();
  int getArraySize();
  void setArray(int* array , int size);
  void setNext(Node *node);
};

Node::Node(int arraySize){
  arr = new int(arraySize);
  arrSize = arraySize;
  next = NULL;
}

int* Node::getArray(){
  return arr;
}

Node* Node::getNext(){
  return next;
}

int Node::getArraySize(){
  return arrSize;
}

void Node::setArray(int* array , int size){
  if(size <= arrSize){
    for(int i = 0;i < size;i++){
      arr[i] = array[i];
    }
  }

}

void Node::setNext(Node *node){
  next = node;
}

class Stack{
private:
  Node *top , *bottom;
public:
  Stack();
  void push_top(int* array , int size);
  int* pop_top();
  void display();
};

Stack::Stack(){
  top = NULL;
  bottom = NULL;
}


void Stack::push_top(int* array , int size){

  Node *node = new Node(size);
  node->setArray(array , size);
  node->setNext(NULL);

  if(bottom){
    top->setNext(node);
  }
  else{
    bottom = node;
  }
  top = node;

}

int* Stack::pop_top(){
  if(bottom == NULL){
    cout<<"stack is empty"<<endl;
    return NULL;
  }

  int *arr = new int(top->getArraySize());
  for(int i = 0;i < top->getArraySize();i++){
    arr[i] = top->getArray()[i];
  }
  Node *node = bottom;
  if(top == bottom){
    top = NULL;
    bottom = NULL;
    return arr;
  }

  while(node->getNext() != top){
      node = node->getNext();
  }
  node->setNext(NULL);
  top = node;
  return arr;
}

void Stack::display(){
  if(bottom == NULL){
    cout<<"stack is empty"<<endl;
    return;
  }
  Node *node = bottom;
  while(node){

    for(int i = 0;i < node->getArraySize();i++){
       cout<<node->getArray()[i]<<" ";
    }
    node = node->getNext();
    cout<<endl;
  }
  cout<<endl;
}

int main(){

  int n;
  cin>>n;
  int zeroNum = 0;
  int arr[n][n];
  Stack stack;
  int target = -1;
  bool rowEmptyCounted = false;
  for(int i = 0;i < n;i++){
    for(int j = 0;j < n;j++){
      cin>>arr[i][j];
      if(arr[i][j] == 0 && (rowEmptyCounted == false)){
        zeroNum++;
      }
    }
    if(zeroNum == n){
       target = i;
       rowEmptyCounted = true;
    }
    else{
       stack.push_top(arr[i] , n);
    }

    zeroNum = 0;

  }
  if(target != -1){
    int i;
     for(i = 0;i < n - 1;i++){
        if(stack.pop_top()[target] == 0){
          break;
        }
     }
     if(i == n - 1){
       cout<<"Person "<<target<<" is a celebrity!";
       return 0;
     }
  }

  cout<<"There's no celebrity in this party!";
  return 0;
}
