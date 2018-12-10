#include "book.h"

Book::Book(QString title, QString author, int publishYear , int price){
    this->author = author;
    this->title = title;
    this->publishYear = publishYear;
    this->price = price;
    next = NULL;
}

Book::Book(Book *copyBook){
    this->author = copyBook->getAuthor();
    this->title = copyBook->getTitle();
    this->publishYear = copyBook->getPublishYear();
    this->price = copyBook->getPrice();
    this->next = NULL;
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
    next = nextBook;
}
