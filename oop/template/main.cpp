#include "template.cpp"
#include <iostream>

using namespace std;

Template make() {
  return Template();
}

int  main() {
  srand(time(NULL));

  Template tpm = make();

  tpm.display();

  return 0;
}
