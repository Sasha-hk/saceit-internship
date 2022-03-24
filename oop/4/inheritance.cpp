#include "inheritance.h"
#include <iostream>

using namespace std;

B1::B1() {}
B1::B1(int b1):b1(b1) {}

B2::B2() {}
B2::B2(int b2):b2(b2) {}

D1::D1() {}
D1::D1(int d1, int b1):B1(b1) {
  this->d1 = d1;
}

D2::D2() {}
D2::D2(int d2):d2(d2) {}

B3::B3() {}
B3::B3(int b3):b3(b3) {}

D3::D3() {}
D3::D3(int d2, int d3):D2(d2) {
  this->d3 = d3;
}

