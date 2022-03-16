#include <iostream>
#include <cmath>
#include <ctime>
#define n 9


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

void makeSomething(int **arr) {
  for (int i = 0; i < 10; i++) {
    arr[i] = new int[10];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = randint(0, 100);
    }
  }

  int maxValue = arr[0][0];
  int minValue = arr[0][0];

  int tt = 0;
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = tt; j < n - tt; j++) {
      if (arr[i][j] > maxValue) {
        maxValue = arr[i][j];
      }
    }
    tt += 1;
  }

  int bt = n / 2 - 1;
  for (int i = n / 2 + 1; i < n; i++) {
    for (int j = bt; j < n - bt; j++) {
      if (arr[i][j] > maxValue) {
        maxValue = arr[i][j];
      }
    }
    bt -= 1;
  }

  int rt = n;
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = rt; j < n; j++) {
      if (arr[i][j] > maxValue) {
        maxValue = arr[i][j];
      }
    }
    rt -= 1;
  }

  int lt = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < lt; j++) {
      if (arr[i][j] < minValue) {
        minValue = arr[i][j];
      }
    }
    if (i >= n / 2) {
      lt -= 1;
    }
    else {
      lt += 1;
    }
  }

  int rp = n / 2;
  for (int i = 0; i < n / 2 + 1; i++) {
    for (int j = rp; j < n; j++) {
      if (arr[i][j] > maxValue) {
        maxValue = arr[i][j];
      }
    }
    rp += 1;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  cout << " > Min value: " << minValue << endl;
  cout << " > Max value: " << maxValue << endl;

}

int main() {
  srand(time(NULL));
  int **arr = new int*[n];

  makeSomething(arr);

  return 0;
}
