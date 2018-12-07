#include "booklist.h"

BookList::BookList(){
    lastBook = NULL;
}

BookList* BookList::find(QString author="" , QString title="" , int publishYear = -1, int price = -1){

    BookList *foundedBooks = new BookList;
    Book *currentBook = lastBook->getNext();


    if(author == "" && title == "" && publishYear == -1 && price == -1){
       return NULL;
    }
    else if(author == "" && title == "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title == "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title == "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getTitle() == title){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getTitle() == title){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear && currentBook->getTitle() == title){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear && currentBook->getTitle() == title){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price  && currentBook->getPublishYear() == publishYear && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks->addEnd(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }

    return foundedBooks;


}

//Book* BookList::addAfter(Book *newBook,QString ){

//}

Book* BookList::addEnd(Book *newBook){
    if(!lastBook){
        return addToEmptyList(newBook);
    }
    Book *tempBook = new Book(newBook);
    tempBook->setNext(lastBook->getNext());
    lastBook->setNext(tempBook);

    lastBook = tempBook;

    return lastBook;
}

Book* BookList::addBegin(Book *newBook){
  if(!lastBook){
      return addToEmptyList(newBook);
  }
  Book *tempBook = new Book(newBook);
  tempBook->setNext(lastBook->getNext());
  lastBook->setNext(tempBook);

  return lastBook;
}

Book* BookList::addToEmptyList(Book *newBook){
    if(lastBook){
        qDebug("BookList is not Empty but you consider it empty!!!\n");
        return lastBook;
    }
    lastBook = new Book(newBook);
    return lastBook;
}

                                                                                                                                                                                                                                                                                                                                                                                    
