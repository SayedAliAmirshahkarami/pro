#include "booklist.h"

BookList::BookList(){
    lastBook = NULL;
    count = 0;
}

void BookList::clear(){
    lastBook = NULL;
    count = 0;
}

int BookList::getBooksNumber(){
    return count;
}

BookList* BookList::operator =(BookList &bookList){
    Book *currentBook = bookList.lastBook->getNext();
    this->clear();
    do{
        this->addEnd(currentBook);
        currentBook = currentBook->getNext();
    }while(currentBook != lastBook->getNext());
    return this;
}

Book* BookList::getLastBook(){
    return lastBook;
}

Book* BookList::getBookAt(int i){

    Book* currentBook = lastBook->getNext();
    for(int j = 0;j < i;j++){
        currentBook = currentBook->getNext();
    }
    return currentBook;
}


vector<Book*> BookList::find(QString author="" , QString title="" , int publishYear = -1, int price = -1){

//    BookList *foundedBooks = new BookList;
    vector<Book*>foundedBooks;
    foundedBooks.clear();
    Book *currentBook = lastBook->getNext();


    if(author == "" && title == "" && publishYear == -1 && price == -1){

        return foundedBooks;
    }
    else if(author == "" && title == "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price){
               foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title == "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title == "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getTitle() == title){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getTitle() == title){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear && currentBook->getTitle() == title){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author == "" && title != "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear && currentBook->getTitle() == title){
               foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getAuthor() == author){
               foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title == "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price  && currentBook->getPublishYear() == publishYear && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear == -1 && price == -1){
        do{
            if(currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear == -1 && price > -1){
        do{
            if(currentBook->getPrice() == price  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear > -1 && price == -1){
        do{
            if(currentBook->getPublishYear() == publishYear  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }
    else if(author != "" && title != "" && publishYear > -1 && price > -1){
        do{
            if(currentBook->getPrice() == price && currentBook->getPublishYear() == publishYear  && currentBook->getTitle() == title && currentBook->getAuthor() == author){
                foundedBooks.push_back(currentBook);
            }
            currentBook = currentBook->getNext();
        }while(currentBook != lastBook->getNext());
    }

    return foundedBooks;


}


Book* BookList::addEnd(Book *newBook){
    count++;
    if(!lastBook){
        qDebug("bookList is empty...");
        return addToEmptyList(newBook);
    }
    Book *tempBook = new Book(newBook);
    tempBook->setNext(lastBook->getNext());
    lastBook->setNext(tempBook);

    lastBook = tempBook;
    return lastBook;
}

Book* BookList::addBegin(Book *newBook){
  count++;
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
    lastBook->setNext(lastBook);
    return lastBook;
}

void BookList::display(){
    qDebug("display : ");
    if(!lastBook){

        qDebug("list is empty..");
       return;
    }
    Book* currentBook = lastBook->getNext();

    do{
        qDebug(currentBook->getTitle().toStdString().c_str());
        currentBook = currentBook->getNext();
    }while(currentBook != lastBook->getNext());
}

int BookList::remove(Book *rmBook){
    if(!lastBook){
        qDebug("list is empty can't remove...");
      return 0;
    }

     Book *currentBook = lastBook->getNext();

     if(currentBook == lastBook){
         if(rmBook == lastBook){
             lastBook = NULL;
             count--;
             return 1;
         }
         else{
             return 0;
         }
     }

     if(rmBook == lastBook){
         while(currentBook->getNext() != lastBook){
             currentBook = currentBook->getNext();
         }
         currentBook->setNext(rmBook->getNext());
         lastBook = currentBook;
         count--;
         return 1;


     }

     do{
         if(currentBook->getNext() == rmBook){
             currentBook->setNext(rmBook->getNext());
             count--;
             return 1;
         }
         currentBook = currentBook->getNext();
     }while(currentBook != lastBook->getNext());
     return 0;
}

                                                                                                                                                                                                                                                                                                                                                                                    
