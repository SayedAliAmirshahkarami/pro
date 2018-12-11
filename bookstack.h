#ifndef BOOKSTACK_H
#define BOOKSTACK_H
#include "bookClasses/book.h"
#include "bookClasses/booklist.h"

extern BookList* bookList;

class BookStack
{

private:
    Book* topBook;
    int count; //head

public:

    BookStack();
    void push(Book *book1);
    Book* pop();
    Book* getTopBook();
};

#endif // BOOKSTACK_H
