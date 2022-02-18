#include "../include/VariadicTable.h"
#include <iostream>
#include <cmath>
#include <string>


using namespace std;

float calculateIncome(int k, int i) {
  return k * (random() % 100) - i * (random() % 50);
}

int main() {
  srand(time(NULL));
  VariadicTable<int, float> vt({"year", "income"}, 2022 - 1991);
  int maxIncomeYear = 0, maxIncomeValue = 0;
  int minIncomeYear = 0, minIncomeValue = 0;
  int income;


  for (int i = 1991; i < 2022; i++) {
    income = calculateIncome(16, i);
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
    vt.addRow(i, income);
  }

  vt.print(cout);

  if (maxIncomeValue != 0) {
    cout << endl;

    cout << "  Max income:\n";
    cout << "     year  - " << maxIncomeYear << endl;
    cout << "     value - " << maxIncomeValue << endl;
  }

  if (minIncomeValue != 0) {
    cout << endl;

    cout << "  Min income:\n";
    cout << "     year  - " << minIncomeYear << endl;
    cout << "     value - " << minIncomeValue << endl;
  }

  return 0;
}
