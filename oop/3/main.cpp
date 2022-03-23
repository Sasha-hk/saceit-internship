#include "pc.cpp"
#include <iostream>

using namespace std;

int  main() {
  srand(time(NULL));

  HDD hdd = HDD(256 * 1024);
  PCExtended pc = PCExtended(
    hdd,
    "IBM",
    "1200 USD",
    24.5
  );

  cout << "Screen diagonal: " << pc.getScreenDiagonal() << endl;
  cout << "HDD size: " << pc.getStorage().getSize() << "Mb" << endl;

  return 0;
}
