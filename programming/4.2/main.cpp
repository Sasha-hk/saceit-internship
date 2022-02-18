#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

// int randint(int min, int max) {
//   return rand() % (max + 1 - min) + min;
// }

// float generateDataItem() {
//   return 1.12 * randint(0, 100) - 16 * randint(0, 50);
// }

// void fillData(int count, float *data) {
//   // for (int i = 0; i < count; i++) {
//   //   cout << i << endl;
//   //   // data[i] = generateDataItem();
//   // }
// }

int main() {
  // srand(time(NULL));

  // int count;

  // count = randint(10, 20);
  // cout << count << endl;

  // float *data[count];
  // float *dataPointer;
  
  // *dataPointer = new int[count];

  // fillData(count, *data);
  // *data[0] = 1;
  // cout << *data[0] << endl;
  // for (int i = 0; i < count; i++) {
  //   cout << i << ": " << data[i] << endl;
  // }

  int count;

  count = 10;

  int* dataPointer[count];

  // int x = 12;

  // dataPointer = &x;
  dataPointer[0] = 1;

  cout << *dataPointer << endl;




  return 0;
}
