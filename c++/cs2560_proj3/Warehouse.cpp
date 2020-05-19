#include <iostream>
#include <string>
#include <fstream>
#include "Warehouse.h"
using namespace std;

Warehouse::Warehouse() : bookCount(0) {
   head = nullptr;
} // end constructor

Book* Warehouse::find (string isbn) const {
   Book* temp = this->head;
   for (int i=0; i < getSize()-1;++i) {
      if (temp->getIsbn()==isbn) {
         return temp;
       } //end if
      temp = temp->getNext();
   } //  end for
   return nullptr;
} // end find

void Warehouse::list() const {
   cout << *this;
} // end list

int Warehouse::getSize() const { // created to get the number of books in the warehouse
   return bookCount;
} // end get size

istream& operator >> (istream& is, Warehouse& warehouse) {
   Book *bookIn = new Book;
   if (warehouse.getSize()==0) {
      is >> *bookIn;
      warehouse.head=bookIn;
      warehouse.end=bookIn;
      warehouse.bookCount++;
   } // end if
      else {
         is >> *bookIn;
         warehouse.end->setNext(bookIn);
         warehouse.end = bookIn;
         warehouse.bookCount++;
      } //  end else
   
   return is;   
} // end >> overload

ostream& operator << (ostream& os, const Warehouse& warehouse) {
   int size = warehouse.bookCount;
   Book* ptr = warehouse.head;
   if (warehouse.bookCount<1) {
      os << "no books in warehouse" << endl;
      return os;
   } // end if
   for (int i=1; i <= size; ++i) {
      os << *ptr;
      ptr = ptr->getNext();
   } // end for
   return os;
} // end << overload
