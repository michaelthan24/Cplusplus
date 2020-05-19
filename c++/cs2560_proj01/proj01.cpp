#include "book.h"
#include<iostream>
#include<fstream>
#include <string>
using namespace std;

int main (int argc, char** argv) {
   const int NUM_OF_BOOKS = 35;
   Book listBooks[NUM_OF_BOOKS]; // array of books that will be read from file
   int booksInFile; // found by using read function
   string input = argv[2];
//handles the user entering no function
   if (argc==1) {
      cout << ".//proj01 <inputfile> find <id>" << endl;
      cout << ".//proj01 <inputfile> list" << endl;
      return 0;
   } //end if

//handles user inputing the list command
   if ( argc == 3 && input =="list")  {
      booksInFile = read ( argv[1], listBooks ); 
      for (int index = 0; index < booksInFile; ++index) {
         cout << "Title: " << listBooks[index].title << endl;
         for (int author = 0; author < listBooks[index].authorCount; ++author) {
            cout << "Author: " << listBooks[index].authors[author ] << endl;
         } //end for
         cout << "Publisher: " << listBooks[index].publisher << endl;
         cout << "Year: " << listBooks[index].yearPublish << endl;
         if (listBooks[index].hardcover== 0) 
            cout << "Cover: Paperback" << endl;
         if (listBooks[index].hardcover== 1)
            cout << "Cover: Hardcover" << endl;
         cout << "Price: $" << listBooks[index].price << endl;
         cout << "ISBN: " << listBooks[index].isbn << endl;
         cout << "Copies: " << listBooks[index].copies << endl;
      } // end for
   }// end if

// handles the find function 
   if ( argc == 4 && input  =="find") {
      booksInFile = read ( argv[1], listBooks ); // reads all the books in the file
      int index = find( argv[3], listBooks, booksInFile); // looks for the book using the index
      cout <<"ISBN: " << argv[3] << "--FOUND" << endl;
      cout << "Title: " << listBooks[index].title << endl;
      for (int author = 0; author < listBooks[index].authorCount; ++author) {
         cout << "Author: " << listBooks[index].authors[author] << endl;
      } //end for
      cout << "Publisher: " << listBooks[index].publisher << endl;
      cout << "Year: " << listBooks[index].yearPublish << endl;
      if (listBooks[index].hardcover == 0)
         cout << "Cover: Paperback" << endl;
      if (listBooks[index].hardcover == 1)
         cout << "Cover: Hardcover" << endl;
      cout << "Price: $" << listBooks[index].price << endl;
      cout << "ISBN: " << listBooks[index].isbn << endl;
      cout << "Copies: " << listBooks[index].copies << endl;      
   } //end if
   return 0;
} // end main function
