#include <iostream>
#include <cmath>


using namespace std;

int main() {
  int x, y;

  cout << "Enter x: ";
  cin >> x;

  cout << "Enter y != x: ";
  cin >> y;

  if (x == y) {
    cout << "You enter x == y";
    exit(1);
  }

  float c, d, z;

  c = sqrt(x + y);
  d = cos(x * y);
  z = (atan(x + y) - 1.5 * exp(x) * c + sqrt(abs(d)));

  cout << "Result = " << z;

  return 0;
}