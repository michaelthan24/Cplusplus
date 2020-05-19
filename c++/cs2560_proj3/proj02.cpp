#include<iostream>
#include<fstream>
#include<string>
#include "Warehouse.h"
#include "Book.h"
using namespace std;

int main (int argc, char** argv) {
   string input = argv[2]; // input command
   Warehouse bookRecords;
   //handles user entering no function
   if (argc==1) {
      cout << "./proj02 <inputfile> find <isbn>" << endl;
      cout << "./proj02 <inputfile> list"  << endl;
      return 0;
   } // end if
   ifstream inFile;
   inFile.open(argv[1]); // opens file
   while (true) {
   inFile >> bookRecords; // puts the books in file into the warehouse object;
   if (inFile.eof()) 
      break;
   } // end while
   inFile.close();
   // handles user inputing the list command
   if (argc==3 && input=="list") {
      bookRecords.list();
      return 0;
   } // end if
   // handles the user inputing find command
   if (argc==4 && input=="find") {
      string inIsbn = argv[3];
      bool found=false;
      for (int i=0; i<bookRecords.getSize(); ++i) {
         Book bookCheck = bookRecords.getBook(i);
         found = bookRecords.find(inIsbn, bookCheck);
         if (found==true) {
            cout << "ISBN: " << inIsbn << "----FOUND" << endl;
            cout << bookCheck;
            return 0;
         } // end if
      } // end for
      cout << "ISBN invalid" << endl;
      return 0;
   } // end if
} // end main function
