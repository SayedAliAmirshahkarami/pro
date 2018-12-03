#include "book.h"

Book::Book(string author, string title , int publishYear , int price){
    this->author = author;
    this->title = title;
    this->publishYear = publishYear;
    this->price = price;
}

string Book::getAuthor(){
    return author;
}

string Book::getTitle(){
    return title;
}

int Book::getPublishYear(){
    return publishYear;
}

Book* Book::getNext(){
    return next;
}

void Book::setNext(Book *nextBook){
    this->next = nextBook;
}
