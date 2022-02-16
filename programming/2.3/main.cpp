#include <iostream>
#include <string> 


using namespace std;

string naturalNumberView[] = {
  "zero",
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eigth",
  "nine"
};

string bigNumberView[] = {
  "Twenty",
  "Thirty",
  "Fourty",
  "Fifty",
  "Sixty"
};

int randint(int min, int max) {
  srand(time(NULL));
  return rand() % (max + 1 - min) + min;
}

int divizion(int one, int divider) {
  return one / divider;
}

string prepareNaturalNumbers(int number) {
  if (number % 10) {
    return naturalNumberView[number % 10];
  }
  return "";
}

void withIf(int year) {
  int pointr = divizion(year, 10);


}

void withSwitch(int year) {

}

int main() {
  int yearNumber = randint(20, 69);

  cout << "Year number: " << yearNumber << endl;

  withIf(yearNumber);

  withSwitch(yearNumber);
 
  return 0;
}