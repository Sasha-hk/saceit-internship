#include "number.cpp"
#include <iostream>

using namespace std;

Number makeNumber(int first, int second) {
  return Number(first, second);
}

int  main() {
  srand(time(NULL));

  Number num = makeNumber(3, 1);

  num.display();

  cout << "Run multiply result: " << num.multiply(num.getFirst(), 3.1123) << endl;

  num.enter();

  cout << "Run multiply result: " << num.multiply(num.getSecond(), 1.32812) << endl;

  return 0;
}
