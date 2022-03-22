#include "number.h"
#include <iostream>

using namespace std;

Number::Number(int first, int second) {
  this->first = first;
  this->second = second;
}

double Number::multiply(int multiplier, double other) {
  return multiplier * other;
}

int Number::getFirst() {
  return first;
}

int Number::getSecond() {
  return second;
}

void Number::enter() {
  cout << "Enter first: ";
  cin >> first;

  cout << "Enter second: ";
  cin >> second;
}

void Number::display() {
  cout << "Math fields view:" << endl;
  cout << "  first: " << first << endl;
  cout << "  second: " << second << endl;
}
