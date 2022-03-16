#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

float generateDataItem() {
  return 1.12 * randint(0, 100) - 16 * randint(0, 50);
}

void fillData(int count, float *data) {
  for (int i = 0; i < count; i++) {
    data[i] = generateDataItem();
  }
}

int findIndexMaxElement(int count, float *dataPointer) {
  int maxIndex;
  int maxValue = dataPointer[0];

  for (int i = 0; i < count; i++) {
    if (dataPointer[i] > maxValue) {
      maxValue = dataPointer[i];
      maxIndex = i;
    }
  }

  return maxIndex;
}

void showArray(int count, float *dataPointer) {
  for (int i = 0; i < count; i++) {
    cout << dataPointer[i] << endl;
  }
}

int main() {
  srand(time(NULL));

  int count = randint(10, 20);
  float *dataPointer = new float[count];

  fillData(count, dataPointer);

  cout << "Show array before swap: \n";
  showArray(count, dataPointer);

  int maxIndex = findIndexMaxElement(count, dataPointer);
  int swap;

  swap = dataPointer[4];
  dataPointer[4] = dataPointer[maxIndex];
  dataPointer[maxIndex] = swap;

  cout << "\nShow array after swap: \n";
  for (int i = 0; i < count; i++) {
    if (i == maxIndex) {
      cout << dataPointer[i] << " <<< swapred\n";
    }
    else if (i == 4) {
      cout << dataPointer[i] << " <<< swapred\n";
    }
    else {
      cout << dataPointer[i] << endl;
    }
  }

  return 0;
}
