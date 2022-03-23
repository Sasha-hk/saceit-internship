#include "date.cpp"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

// Date makeDate(string date) {
//   return Date(date);
// }

int  main() {
  srand(time(NULL));

  Date date = Date("2000.01.04 12:05:04");
  Date otherDate = Date("2000.01.04 12:05:04");

  // Date date = Date();
  // Date otherDate = Date();

  cout << date << endl;
  cout << otherDate << endl << endl;


  if (date == otherDate) {
    cout << "date == other date" << endl;
  }
  else {
    cout << "date != other date" << endl;
  }

  return 0;
}
