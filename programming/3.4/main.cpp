#include <iostream>
#include <cmath>


using namespace std;

int main() {
  float sum = 0;
  int x = 16;

  for (int i = 1; i < 16; i++) {
    sum += (pow(x, i) / -i) + pow(i * x, 1.0/i);
  }

  cout << "Sum: " << sum << endl;
 
  return 0;
}