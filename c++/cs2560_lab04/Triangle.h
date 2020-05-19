//triangle
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <fstream>

using namespace std;

class Triangle {

   public:
      Triangle (float base, float height);
      
      float area();
      
      float getBase();
      
      float getHeight();
   
      Triangle* getNext();
   
      void setNext (Triangle* next);

   private:
      float base_;
      float height_;
      Triangle* next_;
};

#endif /* TRIANGLE_H */
