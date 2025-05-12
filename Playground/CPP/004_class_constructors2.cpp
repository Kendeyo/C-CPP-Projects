/**
 * The public keyword is an access specifier. Access specifiers define how 
 * the members (attributes and methods) of a class can be accessed. In the example
 *  above, the members are public - which means that they can be accessed
 *  and modified from outside the code.
 * 
 * However, what if we want members to be private and hidden from the outside world?
 * 
 * In C++, there are three access specifiers:
 *      public - members are accessible from outside the class
 *      private - members cannot be accessed (or viewed) from outside the class
 *      protected - members cannot be accessed from outside the class,
 *                  however, they can be accessed in inherited classes.
 *                  You will learn more about Inheritance later.
 * 
 */

#include <string.h>
#include <iostream>
using namespace std;


class Car {        // The class
    public:          // Access specifier
      string brand;  // Attribute
      string model;  // Attribute
      int year;      // Attribute
      Car(string x, string y, int z); // Constructor declaration
  };
  
  // Constructor definition outside the class
  Car::Car(string x, string y, int z) {
    brand = x;
    model = y;
    year = z;
  }
  
  int main() {
    // Create Car objects and call the constructor with different values
    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Ford", "Mustang", 1969);
  
    // Print values
    cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
    cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
    return 0;
  }
  