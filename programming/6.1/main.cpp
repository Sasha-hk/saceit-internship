#include <iostream>
#include <cmath>
#include <ctime>
#define Y 15
#define G 20


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

void generateWorkTime(int count, int *workers) {
  for (int i = 0; i < count; i++) {
    workers[i] = randint(0, 31);
  }
}

void generatePayment(int count, int *workers) {
  for (int i = 0; i < count; i++) {
    workers[i] = randint(10000, 15000) / 100 * 80;
  }
}

void makeSomethingElse() {
  int *yWorkTime = new int[Y];
  int *gWorkTime = new int[G];

  int *yPayment = new int[Y];
  int *gPayment = new int[G];

  generateWorkTime(Y, yWorkTime);
  generateWorkTime(G, gWorkTime);

  generatePayment(Y, yPayment);
  generatePayment(G, gPayment);

  cout << "Work time Y: " << endl;
  for (int i = 0; i < Y; i++) {
    cout << "> " << yWorkTime[i] << " ";
  }
  cout << endl;

  cout << "Work time G: " << endl;
  for (int i = 0; i < G; i++) {
    cout << "> " << gWorkTime[i] << " ";
  }
  cout << endl;

  cout << "Work payment Y: " << endl;
  for (int i = 0; i < Y; i++) {
    cout << yPayment[i] << " - ";
  }
  cout << endl;

  cout << "Work payment G: " << endl;
  for (int i = 0; i < G; i++) {
    cout << gPayment[i] << " - ";
  }
  cout << endl;

  // calculate middle payment
  int middlePaymentY;
  int middlePaymentG;

  for (int i = 0; i < G; i++) {
    middlePaymentY += yPayment[i];
  }
  middlePaymentY = middlePaymentY / Y;

  for (int i = 0; i < G; i++) {
    middlePaymentG += gPayment[i];
  }
  middlePaymentG = middlePaymentG / G;

  if (middlePaymentY > middlePaymentG) {
    cout << "Y had more averaga payment than G" << endl;
  }
  else {
    cout << "G had more averaga payment than Y" << endl;
  }

}

int main() {
  srand(time(NULL));

  makeSomethingElse();

  return 0;
}
