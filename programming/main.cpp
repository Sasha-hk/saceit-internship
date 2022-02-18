#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

int randint(int min, int max) {
  srand(time(NULL));
  return rand() % (max + 1 - min) + min;
}

int  main() {

  return 0;
}
