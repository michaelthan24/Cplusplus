#include<iostream>
#include<fstream>
#include<string>
#include"Book.h"
using namespace std;

 istream& operator >> (istream& is, Book& book) {
   getline(is , book.title);
   is >> book.authorCount;
   is.ignore();
   for (int i=0; i<book.authorCount; ++i) {
      getline(is, book.authors[i]);
   }
   getline(is, book.publisher);
   is >> book.yearPublish;
   is >> book.hardcover;
   is >> book.price;
   is.ignore();
   getline(is, book.isbn);
   is >> book.copies;
   is.ignore();
   return is;
} // end >> overload

 ostream& operator << (ostream& os, const Book& book) {
   os << "Title: " << book.getTitle() << endl;
   for (int i=0; i<book.getAuthorCount(); ++i) {
      os << "Author: " << book.getAuthors(i) << endl;
   } // end for
   os << "Publisher: " << book.getPublisher() << endl;
   os << "Year: " << book.getYearPublish() << endl;
   if (book.getHardcover()==0)
      os << "Cover: Paperback" << endl;
   if (book.getHardcover()==0)
      os << "Cover: Hardcover" << endl;
   os << "Price: $" << book.getPrice() << endl;
   os << "ISBN: " << book.getIsbn() << endl;
   os << "Copies: " << book.getCopies() << endl;
   return os;
} // end << overload


Book::Book(string title, string authors[], int authorCount, string publisher, short yearPublish, bool hardcover, 
float price, string isbn, long copies) {
   this->title=title;
   this->authorCount = authorCount;
   for (int i=0; i < authorCount; ++i) {
      this->authors[i]=authors[i];
   } // end for
   this->publisher = publisher;
   this->yearPublish = yearPublish;
   this->hardcover = hardcover;
   this->price = price;
   this->isbn = isbn;
   this->copies = copies;
} // end book constructor

Book::Book() {
} // end book default constructor

//getters and setters

string Book::getIsbn() const {
   return isbn;
}
string Book::getTitle() const {
   return title;
}
int Book::getAuthorCount () const {
   return authorCount;
}
string Book::getAuthors(int i) const {
   return authors[i];
}
string Book::getPublisher() const {
   return publisher;
}
short Book::getYearPublish() const {
   return yearPublish;
}
bool Book::getHardcover() const {
   return hardcover;
}
float Book::getPrice() const {
   return price;
}
long Book::getCopies() const {
   return copies;
}
