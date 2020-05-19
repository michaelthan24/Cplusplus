#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(float b, float h) {
   base_=b;
   height_=h;
}

float Triangle::area() {
   return base_*height_*.5;
}

float Triangle::getBase() {
   return base_;
}

float Triangle::getHeight() {
   return height_;
}

Triangle* Triangle::getNext() {
   return next_;
}

void Triangle::setNext(Triangle* next) {
   next_=next;
}

