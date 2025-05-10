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