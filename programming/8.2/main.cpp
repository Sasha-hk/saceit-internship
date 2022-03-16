#include <iostream>
#include <string>

#define M 5
#define N 10

using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

void fillData(int **data) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      data[i][j] = randint(0, 100);
    }
  }
}

void showData(int **data) {
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      cout << data[i][j] << " ";
    }
    cout << endl;
  }
}

int  main() {
  srand(time(NULL));
  int **numbers1 = new int*[M];
  int **numbers2 = new int*[M];
  int **numbers3 = new int*[M];
  int **numbers4 = new int*[M];

  for (int i = 0; i < M; i++) {
    numbers1[i] = new int[N];
    numbers2[i] = new int[N];
    numbers3[i] = new int[N];
    numbers4[i] = new int[N];
  }
  
  fillData(numbers1);
  fillData(numbers2);
  fillData(numbers3);
  fillData(numbers4);

  cout << "\nNumbers: 1\n";
  showData(numbers1);
  cout << "\nNumbers: 2\n";
  showData(numbers2);
  cout << "\nNumbers: 3\n";
  showData(numbers3);
  cout << "\nNumbers: 4\n";
  showData(numbers4);

  // has all
  int hasAll[101];

  for (int i = 0; i < 101; i++) {
    hasAll[i] = 0;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      hasAll[numbers1[i][j]] += 1;
      hasAll[numbers2[i][j]] += 1;
      hasAll[numbers3[i][j]] += 1;
      hasAll[numbers4[i][j]] += 1;
    }
  }

  cout << endl << "Has all:" << endl;

  for (int i = 0; i < 101; i++) {
    if (hasAll[i] >= 4) {
      cout << i << " ";
    }
  }

  cout << endl << endl;

  // has no one
  bool hasNoOne[101];

  for (int i = 0; i < 101; i++) {
    hasNoOne[i] = false;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      hasAll[numbers1[i][j]] = true;
      hasAll[numbers2[i][j]] = true;
      hasAll[numbers3[i][j]] = true;
      hasAll[numbers4[i][j]] = true;
    }
  }

  cout << "Has no one:" << endl;

  for (int i = 0; i < 101; i++) {
    if (!hasNoOne[i]) {
      cout << i << " ";
    }
  }

  cout << endl << endl;

  // has in second and third
  int hasFew[101];

  for (int i = 0; i < 101; i++) {
    hasNoOne[i] = 0;
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      hasFew[numbers2[i][j]] += 1;
      hasFew[numbers4[i][j]] += 1;
    }
  }

  cout << "Has few 2 and 4: " << endl;

  for (int i = 0; i < 101; i++) {
    if (hasFew[i] >= 2) {
      cout << i << " ";
    }
  }

  cout << endl;

  return 0;
}
