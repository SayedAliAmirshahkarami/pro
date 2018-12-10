#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "book.h"
#include <iostream>
#include <vector>

using namespace std;


class BookList
{
private:
    Book *lastBook;
    Book* addToEmptyList(Book *);

public:
    BookList();
    Book* addEnd(Book *);
    Book* addBegin(Book *);
    int remove(Book *);
    vector<Book*> find(QString , QString , int , int);
    BookList* operator =(BookList &bookList);
    Book* getLastBook();
    void clear();
    Book* getBookAt(int i);
    void display();
};

#endif // BOOKLIST_H
