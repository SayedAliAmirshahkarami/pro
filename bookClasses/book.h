#ifndef BOOK_H
#define BOOK_H

#include<QString>

class Book
{
private:
    QString author, title;
    int publishYear;
    int price;
    Book *next;
public:
    Book(QString , QString , int , int);
    Book(Book*);
    QString getAuthor();
    QString getTitle();
    int getPublishYear();
    int getPrice();
    Book* getNext();
    void setNext(Book *);
};

#endif // BOOK_H
