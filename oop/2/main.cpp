#include "date.cpp"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

Date makeDate(string date) {
  return Date(date);
}

int  main() {
  srand(time(NULL));

  // Date date = makeDate("2022.01.04 12:13:04");
  Date date = Date();
  Date date2 = Date(date);

  date.display();
  date2.display();

  cout << date << " << operator" << endl;

  cout << date.getString() << endl;


  return 0;
}
