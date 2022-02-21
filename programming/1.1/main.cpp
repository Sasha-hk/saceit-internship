#include <iostream>
#include <cmath>


using namespace std;

int main() {
  float v16;
  int x;

  cout << "Enter x: ";
  cin >> x;

  v16 = (pow(x, 2) + sqrt(pow(sin(x), 2) - log(pow(x, 2)))) / pow(log10(x + pow(5.5 * x + log(x), 1.3)), 2) - exp(2.5 + pow(x, 2));

  cout << v16;
  
  return 0;
}
