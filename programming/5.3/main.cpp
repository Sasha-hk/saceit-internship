#include <iostream>
#include <cmath>
#include <ctime>
#define n 11


using namespace std;

int randint(int min, int max) {
  srand(time(NULL));
  return rand() % (max + 1 - min) + min;
}

int main() {

  int arr[n][10];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }

  int topTriangle = n;
  for (int i = 0; i < n / 2 + 1; i++) {

    for (int j = 0; j < n; j++) {
      cout << topTriangle  << " ";
      if (j >= n - topTriangle && j <= n / 2 + topTriangle / 2) {
        arr[i][j] = 1;
      }
    }
    cout << endl;
    topTriangle -= 2;

  }

  cout << endl;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }



  


  return 0;
}
