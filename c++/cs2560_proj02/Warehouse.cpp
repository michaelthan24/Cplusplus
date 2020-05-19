#include <iostream>
#include <string>
#include <fstream>
#include "Warehouse.h"
using namespace std;

Warehouse::Warehouse() : bookCount(0) {

} // end constructor

bool Warehouse::find (string isbn, Book& book) const {
   if (isbn==book.getIsbn()) {
      return true;
      } // end if
   return false;
} // end find

void Warehouse::list() const {
   cout << *this;
} // end list

istream& operator >> (istream& is, Warehouse& warehouse) {
   is >> warehouse.books[warehouse.bookCount];
   warehouse.bookCount++;
   return is;   
} // end >> overload

ostream& operator << (ostream& os, const Warehouse& warehouse) {
   Book obook;
   int size = warehouse.getSize();
   for (int index= 0; index < size-1; ++index) {
      obook = warehouse.getBook(index);
      os << obook;
   } // end if
   return os;
} // end << overload

Book Warehouse::getBook(int i) const { // created to get book from warehouse to compare in find function
   return books[i];
} // end get book

int Warehouse::getSize() const { // created to get the number of books in the warehouse
   return bookCount;
} // end get size
