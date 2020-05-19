// @file Book.h
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include <string>
using namespace std;
class Book {
 /**
* @param is the input stream
* @param book the book object to be filled
* @return the input stream
*/
 friend istream& operator >> (istream& is, Book& book);
 /**
* @param os the output stream
* @param book the book object reference
* @return the output stream
*/
 friend ostream& operator << (ostream& os, const Book& book);
 public:
 static const int MAX_AUTHORS = 35;
 Book();
 Book(string title, string authors[], int authorCount,
 string publisher, short yearPublish, bool hardcover,
 float price, string isbn, long copies);
 
 Book(string title, string authors[], int authorCount,
 string publisher, short yearPublish, bool hardcover,
 float price, string isbn, long copies, Book* next);

 string getTitle() const;
 int getAuthorCount() const;
 string getAuthors(int i) const;
 string getPublisher() const;
 short getYearPublish() const;
 bool getHardcover() const;
 float getPrice() const;
 string getIsbn() const;
 long getCopies() const;
 Book* getNext() const;
 void setNext(Book* next);
 /** add all the setter and getter methods **/
 private:
 Book* next;
 string title;
 string authors[Book::MAX_AUTHORS];
 int authorCount;
 string publisher;
 short yearPublish;
 bool hardcover;
 float price;
 string isbn;
 long copies;
 /** add all attributes **/
};
#endif /* BOOK_H */
 
