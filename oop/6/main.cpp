#include "String.h"
#include <iostream>

using namespace std;

int  main() {
  String str = String("hello world");
  String str1 = String("wor");

  cout << str << endl;

  cout << str + str1 << endl;

  cout << "Sub: " << str - str1 << endl;

  cout << "Entering: " << str * str1 << endl;

  return 0;
}
