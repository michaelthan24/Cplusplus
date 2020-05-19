#include <iostream>
#include <fstream>
#include "Triangle.h"

using namespace std;

int main () {
   float base, height;
   ifstream inputFile;
   inputFile.open("triangles.dat");
   inputFile >> base >> height;
   Triangle* firstNode = new Triangle(base ,height);
   int triNum = 1;
   Triangle* temp = firstNode;
   while (!inputFile.eof()) {
     inputFile >> base >> height;
     Triangle* myTri = new Triangle (base, height);
     temp->setNext(myTri);
     temp = temp->getNext();
     triNum++;
   }
   inFile.close();
   temp = firstNode;
   int count = 1;
   while(count < triNum) {
      cout<< "Triangle " << count << ": b= " << temp->getBase() << ", h= " << temp->getHeight() << ", area= " << temp->area() << endl;
      count++;
      temp = temp->getNext();
   }// end while
   return 0;
}
