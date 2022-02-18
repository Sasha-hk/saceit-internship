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
  float a, z, b = 1, x = 10;

  for (int i = 0; i < 16 + 8; i++) {
    a += f2(x);
  }

  for (int i = 0; i < 16 + 8; i++) {
    b = b * f3(x);
  }

  cout << "Result a: " << a << endl;
  cout << "Result b: " << b << endl;

  z = exp(3 * a * b);

  cout << "Reslut z: " << z << endl;
  
  return 0;
}
