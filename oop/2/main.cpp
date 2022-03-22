#include "date.cpp"
#include <iostream>
#include <string>

using namespace std;

Date makeDate(string date) {
  return Date(date);
}

int  main() {
  srand(time(NULL));

  Date date = makeDate("2022.01.01");

  date.display();

  return 0;
}
