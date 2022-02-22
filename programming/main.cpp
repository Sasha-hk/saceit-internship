#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

int  main() {
  srand(time(NULL));

  return 0;
}
