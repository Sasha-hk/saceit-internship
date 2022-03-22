#include "date.cpp"
#include <iostream>
#include <string>
#include <chrono>

using namespace std;

Date makeDate(string date) {
  return Date();
}

int  main() {
  srand(time(NULL));

  Date date = makeDate("2022.01.01");

  return 0;
}
