#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(float b, float h) {
   base_=b;
   height_=h;
}

float Triangle::area() {
   return base_*height_*5;
}
