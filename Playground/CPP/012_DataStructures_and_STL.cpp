/**
 * Data structures are used to store and organize data. An array 
 * is an example of a data structure, which allows multiple elements to be stored in a single variable.
 * C++ includes many other data structures as well, each is used to handle data in different ways.
 * These are part of the C++ STL, which stands for The Standard Template Library.
 * 
 * 
 * source: https://www.w3schools.com
 * 
 * STL is a library that consist of different data structures and algorithms 
 * to effectively store and manipulate data.
 */

// Include the vector library
#include <vector>

// Include the list library
#include <list>

// Include the set library
#include <set>

// Include the map library
#include <map>

// Include the stack library
#include <stack>

// Include the queue library
#include <queue>

// Create a vector called cars that will store strings
vector<string> cars = {"Volvo", "BMW", "Ford", "Mazda"};

// Print vector elements
for (string car : cars) {
  cout << car << "\n";
}