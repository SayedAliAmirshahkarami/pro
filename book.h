#ifndef BOOK_H
#define BOOK_H

class Book
{
private:
    string author, title;
    int publishYear;
    int price;
    Book *next;
public:
    Book(string , string , int , int);
    string getAuthor();
    string getTitle();
    int getPublishYear();
    int getPrice();
    Book* getNext();
    void setNext(Book *);
};

#endif // BOOK_H
