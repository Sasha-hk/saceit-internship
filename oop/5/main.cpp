#include "ship.cpp"
#include <iostream>

using namespace std;

int  main() {
  Ship ship = Ship(
    "Irland",
    "Cruiser",
    100
  );

  ship.show();

  return 0;
}
