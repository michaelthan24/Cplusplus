#include "book.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int read (string fileName, Book books[]) {
   ifstream inFile;
   inFile.open(fileName); // opens user inputed file
   int index=0;
   if (inFile.fail()) return -1;
   while (true) {
      getline(inFile, books[index].title);
      inFile >> books[index].authorCount;
      inFile.ignore();
      for( int i =0; i < books[index].authorCount; i++) {
         getline(inFile, books[index].authors[i]);
      }
      getline(inFile, books[index].publisher);
      inFile >> books[index].yearPublish;
      inFile >> books[index].hardcover;
      inFile >> books[index].price;
      inFile.ignore();
      getline(inFile, books[index].isbn);
      inFile >> books[index].copies;
      inFile.ignore();
      index++;
      if (inFile.eof()) break;
   } // end while
   inFile.close();
   return index -1;
}  // end read

int find (string id, Book books[], int length) {
   int index = 0;
   string isbn;
   while(index < length) {
      isbn = books[index].isbn;
      if (!id.compare(isbn)) {
         return index;
      } // end if
      index++;
   }// end while
   cout << "Invalid ISBN" << endl;
   return -1;
} //end find
