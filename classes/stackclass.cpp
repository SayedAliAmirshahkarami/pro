#include "book.h"
#include <iostream>
using namespace std;

Book::Book(QString author, QString title , int publishYear , int price){
    this->author = author;
    this->title = title;
    this->publishYear = publishYear;
    this->price = price;
}

Book::Book(Book *copyBook){
    this->author = copyBook->getAuthor();
    this->title = copyBook->getTitle();
    this->publishYear = copyBook->getPublishYear();
    this->price = copyBook->getPrice();
}

QString Book::getAuthor(){
    return author;
}

QString Book::getTitle(){
    return title;
}

int Book::getPublishYear(){
    return publishYear;
}

int Book::getPrice(){
    return price;
}

Book* Book::getNext(){
    return next;
}

void Book::setNext(Book *nextBook){
    this->next = nextBook;
}



//*************************************************************************************************************



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


//**************************************************************************************************************



int main(){
	
	
	
}





