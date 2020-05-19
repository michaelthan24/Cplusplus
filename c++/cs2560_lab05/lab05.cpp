#include <iostream>
#include <fstream>
#include "Triangle.h"
using namespace std;


int main () {
   float base, height;
   ifstream inputFile;
   inputFile.open("triangles.dat");
   Stack<Triangle*> triStack;
   while (inputFile >> base >> height) {
     triStack.push( new Triangle (base, height) );
   }
   inputFile.close();
   Triangle* triPtr = nullptr;
   int triNum =1;
   while(triStack.pop (triPtr)) {
      cout<< "Triangle " << triNum << ": b= " << triPtr->getBase() << ", height "<< triPtr->getHeight() << ", area= " << triPtr->area() << endl;
      triNum++;
      delete triPtr;
   }   
   return 0;
}
