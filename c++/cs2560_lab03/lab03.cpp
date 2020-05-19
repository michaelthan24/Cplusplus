#include <iostream>
#include <fstream>
#include "Triangle.h"

using namespace std;


int main () {
   float base, height;
   int line = 1;
   ifstream inputFile;
   inputFile.open("triangles.dat");
   while (!inputFile.eof()) {
      inputFile >> base >> height;
      Triangle myTri(base,height);
      cout << "Triangle " << line << ": " << "b= " << base << ", h= " << height << ", area= " << myTri.area() 
<< endl;
      line++;
   }   

}
