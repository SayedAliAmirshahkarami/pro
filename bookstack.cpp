#include "bookstack.h"

BookStack::BookStack()
{
        topBook = NULL;
        count=0;

}

void BookStack::push(Book *book1)
{
if(count == bookList.getBooksNumber())
        cout<<"stack is full";
else
{
    Book *book2 = new Book(book1);
    if(topBook == NULL)
    {

        book2->setNext(NULL);
        topBook = book2;
        count++;
    }
    else
    {

        book2->setNext(topBook);
        topBook = book2;
        count++;
    }
}
}

Book* BookStack::pop(){

if(topBook == NULL){
    qDebug("bookStack is empty...");
        return NULL;
}
else
{
    Book * book1 = topBook;

    topBook = topBook->getNext();
    count--;
    return book1;
}
}
