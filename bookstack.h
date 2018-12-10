#ifndef BOOKSTACK_H
#define BOOKSTACK_H
#include "bookClasses/book.h"
#include "bookClasses/booklist.h"

extern BookList bookList;

class BookStack
{

private:
    Book* topBook;
    int count; //head
    int stackData;

public:

    BookStack();
    void push(Book *book1);
    Book* pop();

};

#endif // BOOKSTACK_H
