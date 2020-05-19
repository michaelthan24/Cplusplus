/*Michael Than
**Partner: 
**cs2560_02 
**Lab 2
**
**
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
   float triNum=1;
   float base,height;
   ifstream triangleFile;
   triangleFile.open("triangles.dat");
   if (!triangleFile) {
      cout<<"file failed opening"<<endl;
      return 1;
      }
   while(triangleFile>>base>>height) {
      triangleFile>>base>>height;
      cout<< "triangle "<<triNum<<" b= "<<base<<" height= "<<height<<" area= "<<(base*height)/2<<endl;
      triNum++;
   }
   triangleFile.close();


}

