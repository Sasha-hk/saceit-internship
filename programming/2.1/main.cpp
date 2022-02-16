#include <iostream>
#include <cmath>


using namespace std;

float f1(int x) {
  return 3 + x / (x + 3);
}

float f2(int x) {
  return pow(2 - x, 3) + pow(x, -4) + 3 * pow(x, 1/2);
}

float f3(int x) {
  return pow(sin(x), 2) + 25 * cos(x) - 2 / (pow(x, -3) + 2);
}

int main() {
  int x;
  float result;

  cout << "Enter x: ";
  cin >> x;

  result = f1(x) - 2 * f2(x) / f3(x);

  cout << "Result: " << result;
  
  return 0;
}