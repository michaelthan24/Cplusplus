#include<iostream>
#include<fstream>
#include<string>
#include "Warehouse.h"
#include "Book.h"
using namespace std;

int main (int argc, char** argv) {
   if (argc < 3 || argc > 4) { // handles user inputting any invalid input
      cout << "please enter one of the following input" << endl;
      cout << "./proj3 <inputfile> find <isbn> " << endl;
      cout << "./proj3 <inputfile> list " << endl;
      return 0;
   } // end if

   string firstCom = argv[0]; // proj3 command
   string fileName = argv[1];
   string input = argv[2]; // input command
   Warehouse* bookRecords = new Warehouse;

   if (argc==3 && input=="list") { // handles user entering list command
      ifstream inFile;
      inFile.open(fileName); // opens file
      while (!inFile.eof()) {
         inFile >> *bookRecords; // puts the books in file into the warehouse object;
         if (inFile.eof()) break;
      } // end while
      inFile.close();
      bookRecords->list();
      delete bookRecords;
      return 0;
   } // end if
   else if (argc==4 && input=="find") { // handles user entering find command
      string inIsbn = argv[3]; // isbn entered in to be searched
      ifstream inFile;
      inFile.open(fileName); // opens file
      while (!inFile.eof()) {
         inFile >> *bookRecords; // puts the books in file into the warehouse object;
         if (inFile.eof()) break;
      } // end while
      inFile.close();
      Book* bookSearched = bookRecords->find(inIsbn);
         if (bookSearched!=nullptr) {
            cout << "ISBN: " << inIsbn << "----FOUND" << endl;
            cout << *bookSearched;
            return 0;
         } // end if
      cout << "ISBN invalid" << endl;
      delete bookSearched;
      return 0;
   } // end else if
   else if (firstCom=="./proj3") {
       cout << "./proj3 <inputfile> find <isbn> " << endl;
       cout << "./proj3 <inputfile> list " << endl;
       return 0;
   } // end else
   return 0;
} // end main function
