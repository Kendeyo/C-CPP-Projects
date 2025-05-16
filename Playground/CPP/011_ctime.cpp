/**
 * The <ctime> library allows us to work with dates and times.
 * To use it, you must import the <ctime> header file
 * 
 * source: https://www.w3schools.com
 */

#include <iostream>
#include <ctime>  // Import the ctime library
using namespace std;
 
int main () {
  // Get the timestamp for the current date and time
  time_t timestamp;
  time(&timestamp);

  // Display the date and time represented by the timestamp
  cout << ctime(&timestamp);
  return 0;
}
