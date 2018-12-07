#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "book.h"


class BookList
{
private:
    Book *lastBook;
    Book* addToEmptyList(Book *);
    BookList search(int , int flag);
    BookList search(QString , int flag);
public:
    BookList();
    Book* addAfter(Book * , Book *);
    Book* addEnd(Book *);
    Book* addBegin(Book *);
    Book* remove(Book *);
    BookList* find(QString , QString , int , int);
    Book* find(Book*);


};

#endif // BOOKLIST_H
