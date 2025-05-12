/**
 * C++ is an object-oriented programming language.
 * Everything in C++ is associated with classes and objects, 
 * along with its attributes and methods. For example: in real life, a car is an object. 
 * The car has attributes, such as weight and color, and methods, such as drive and brake.
 * 
 * Attributes and methods are basically variables and functions that belongs to the class.
 *  These are often referred to as "class members".
 * A class is a user-defined data type that we can use in our program, and it works as an object constructor,
 *  or a "blueprint" for creating objects.
 * 
 * source: https://www.w3schools.com
 * 
 */


#include <string.h>
#include <iostream>
using namespace std;


class MyClass {       // The class
    public:             // Access specifier
      int myNum;        // Attribute (int variable)
      string myString;  // Attribute (string variable)
  };
  
  int main() {
    MyClass myObj;  // Create an object of MyClass
  
    // Access attributes and set values
    myObj.myNum = 15; 
    myObj.myString = "Some text";
  
    // Print attribute values
    cout << myObj.myNum << "\n";
    cout << myObj.myString;
    cin.get(); // Wait for user input before closing the console window
    return 0;
  }