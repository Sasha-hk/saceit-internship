#include <iostream>
#include <cmath>
#include <ctime>


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

void makeSomething(int *duration) {
  for (int i = 0; i < 25; i++) {
    duration[i] = randint(0, 10);
    cout << duration[i] << " ";
  }
  cout << endl;

  int minAverage = duration[0];

  for (int i = 0; i < 25; i++) {
    if (minAverage > duration[i]) {
      minAverage = duration[i];
    }
  }

  cout << "Min avarage time: " << minAverage << endl;
}

int  main() {
  srand(time(NULL));
  int duration[25];

  makeSomething(duration);

  return 0;
}
