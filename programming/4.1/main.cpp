#include "../include/VariadicTable.h"
#include <iostream>
#include <cmath>
#include <string>


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

float calculateIncome(int k, int i) {
  return k * randint(-i * randint(0, 50), 100);
}

int main() {
  srand(time(NULL));
  VariadicTable<int, float, string> vt({"year", "income", "tag"}, 2022 - 1991);
  int maxIncomeYear = 0, maxIncomeValue = 0;
  int minIncomeYear = 0, minIncomeValue = 0;
  int income;
  int k = 1;
  string tag;


  for (int i = 1991; i < 2022; i++) {
    k = i % 10;

    income = calculateIncome(k, 16);
    if (income > 0) {
      tag = "income";
    }
    else {
      tag = "loss";
    }

    if (income < 0) {
      if (income < minIncomeValue) {
        minIncomeYear = i;
        minIncomeValue = income;
      }
    }

    if (income > 0) {
      if (income > maxIncomeValue) {
        cout << i << endl;
        maxIncomeYear = i;
        maxIncomeValue = income;
      }
    }
    vt.addRow(i, income, tag);
  }

  vt.print(cout);

  return 0;
}
