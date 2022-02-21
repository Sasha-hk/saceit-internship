#include <iostream>
#include <cmath>
#include <ctime>
#define n 10
#define k 10


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

float generateDataItem() {
  return n * k * randint(-16 * n * randint(0, 10), 10);
}

void fillData(float **data) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      data[i][j] = generateDataItem();
    }
  }
}

int main() {
  srand(time(NULL));
  float **data = new float*[n];

  for (int i = 0; i < n; i++) {
    data[i] = new float[k];
  }

  fillData(data);

  cout << "Array: " << endl;
  for (int i = 0; i < n; i++) {
    cout << "| ";
    for (int j = 0; j < k; j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }

  // task 16
  int 
    minIndexN = 0,
    minIndexK = 0,
    minValue = data[0][0],

    maxIndexN = 0,
    maxIndexK = 0,
    maxValue = data[0][0];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      if (minValue > data[i][j]) {
        minValue = data[i][j];
        minIndexN = i;
        minIndexK = j;
      }

      if (maxValue < data[i][j]) {
        maxValue = data[i][j];
        maxIndexN = i;
        maxIndexK = j;
      }
    }
  }

  cout << endl;
  cout << "Min index\n  n: " << minIndexN << "\n  k: " << minIndexK << endl;
  cout << "Max index\n  n: " << maxIndexN << "\n  k: " << maxIndexK << endl;
  

  return 0;
}