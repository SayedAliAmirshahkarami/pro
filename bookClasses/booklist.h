#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "book.h"


class BookList
{
private:
    Book *lastBook;
    Book* addToEmptyList(Book *);

public:
    BookList();
    Book* addAfter(Book * , Book *);
    Book* addEnd(Book *);
    Book* addBegin(Book *);
    Book* remove(Book *);
    BookList* find(QString , QString , int , int);
    Book* find(Book*);
    BookList* operator =(BookList &bookList);
    Book* getLastBook();
    void clear();


};

#endif // BOOKLIST_H
