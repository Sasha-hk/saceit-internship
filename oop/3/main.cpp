#include "window.cpp"
#include <iostream>

using namespace std;

Window make() {
  return Window();
}

int  main() {
  srand(time(NULL));

  Window tpm = make();

  tpm.display();

  return 0;
}
