#include "book.h"

Book::Book(QString author, QString title , int publishYear , int price){
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
    this->next = nextBook;
}
