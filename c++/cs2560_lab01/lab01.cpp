/*Author: Michael Than
*Partner: Jeane Taruc
*cs2560-01, Spring 2019
*Lab assignment #1
*Description
*    A simple C++ program
*/
#include <iostream>
#include <iomanip>
#include <string>

//function for output formatting
void output (std::ostream&, std::string, double);

//main function
int main (int argc, char* argv[]) {

 //variable
 double item1;
 double item2;

 std::cout << "Enter amount for item 1\n";
 std::cin >> item1;

 std::cout << "Enter amount for item 2\n";
 std::cin >> item2;
 std::cout << "\n";
 //compute subtotal and sales and store values into local variables
 //store values into local variables
 
 double subTotal = item1+item2;
 double tax = subTotal * .0825;

 output (std::cout, "Item 1:  $", item1);
 output (std::cout, "Item 2:  $", item2);
 std:: cout << "\n";
 output (std::cout, "Sub total: $", subTotal);
 output (std::cout, "Tax: $", tax);
 output (std::cout, "Total: $", subTotal + tax);
 return 0;
}


void output (std::ostream& writer, std::string tag, double value) {
 //configure output format
 writer << std::setprecision(2) << std::fixed;
 writer << tag << std::setw(7) << value << "\n";
}
