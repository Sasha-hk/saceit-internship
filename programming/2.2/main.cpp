#include <iostream>
#include <cmath>


using namespace std;

int randint(int min, int max) {
  srand(time(NULL));
  return rand() % (max + 1 - min) + min;
}

int main() {
  int K = 2, x = randint(10, 20);
  float L = 7.39 * pow(10, 3);
  float x1, x3, a, b, y;

  a = (L * x) / (pow(x, 5) * (exp(K) - 1));
  b = sqrt(exp((x-1) / sin(x))) + cos(x);

  float condition = pow(a, 2) + pow(b, 2);
  if (condition > 0.1) {
    y = atan(a - 5 * b);
  }
  else if (condition <= 0.1) {
    y = atan(5 * a - 3 + b);
  }

  cout << "Result: " << y;

  
  return 0;
}