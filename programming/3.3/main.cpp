#include <iostream>
#include <cmath>


using namespace std;

float Yi(int x) {
  return sin(x);
}

int main() {
  float h = 0.1;
  float max = 16;
  int count;
  float sum = 1;
  float r;

  for (float i = 0; i < max; i+=h) {
    r = Yi(i);
    if (r < 0) {
      sum *= r;
      count += 1;
    }
  }

  cout << "Sum:   " << sum << endl;
  cout << "Count: " << count << endl;

  return 0;
}
