/**
 * A constructor in C++ is a special method that is automatically called 
 * when an object of a class is created.
 * To create a constructor, use the same name as the class, 
 * followed by parentheses ():
 * 
 * source: https://www.w3schools.com
 */

#include <string.h>
#include <iostream>
using namespace std;

class Car {        // The class
    public:          // Access specifier
      string brand;  // Attribute
      string model;  // Attribute
      int year;      // Attribute
      Car(string x, string y, int z) { // Constructor with parameters
        brand = x;
        model = y;
        year = z;
      }
  };
  
  int main() {
    // Create Car objects and call the constructor with different values
    Car carObj1("BMW", "X5", 1999);
    Car carObj2("Ford", "Mustang", 1969);
  
    // Print values
    cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
    cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
    return 0;
  }