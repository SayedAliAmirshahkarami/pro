//#include "book.h"
#include <iostream>
using namespace std;
#define max_size 5000
#define MAX 5000
class Book
{
private:
    string author, title;
    int publishYear;
    int price;
    Book *next;
public:
    Book(string , string , int , int);
    Book();
    Book(Book*);
    string getAuthor();
    string getTitle();
    int getPublishYear();
    int getPrice();
    Book* getNext();
    void setNext(Book *);
};

Book::Book(string author, string title , int publishYear , int price){
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

string Book::getAuthor(){
    return author;
}

string Book::getTitle(){
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
//*******************************************************************************************
//*************************************************************************************
//***************************************************************************************

 
class Stack 
{ 
    int top; 
public: 
    Book books[max_size];    //Maximum size of Stack 
  
    Stack()  { top = -1; } 
    bool push(Book); 
    Book pop(); 
    bool isEmpty(); 
}; 
  
bool Stack::push(Book book1) 
{ 
    if (top >= (MAX-1)) 
    { 
        cout << "Stack Overflow"; 
        return false; 
    } 
    else
    { 
    
        books[++top] = book1; 
        //cout<<x <<" pushed into stack\n"; 
        return true; 
    } 
} 
  
Book Stack::pop() 
{ 
    if (top < 0) 
    { 
        cout << "Stack Underflow"; 
     //   return ; 
    } 
    else
    { 
        Book book1 = books[top--]; 
        
        return book1; 
    } 
} 
  
bool Stack::isEmpty() 
{ 
    return (top < 0); 
} 
  



//**************************************************************************************************************



int main(){
	
	Stack stack1;
	cout<<"enter the charactrecotr of the book "<<endl;
	cout<<"please enter the 1-the author  2-title 3-RYLTIME 4-PRICE"<<endl;
	string author,title;
	
	int price,RYLTIME;
	for(int i=0;i<3;i++){
	
	cin>>author>>title>>RYLTIME>>price;
	Book book1(author,title,RYLTIME,price);
	stack1.push(book1);
	
}

for(int i=0;i<3;i++){
	Book book1=stack1.pop();
	cout<<book1.getAuthor()<<"book ----> "<<endl;
	
}
	
	
	
}





