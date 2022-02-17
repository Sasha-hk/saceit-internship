#include "include/VariadicTable.h"
#include <string>
#include <iostream>


using namespace std;

float rod_square = 28.3;
float rod_funt = 1000;

int main()
{
    int count;

    cout << "Enter cont of rows:";
    cin >> count;
    
    VariadicTable<float, float, float> vt({"rod", "square", "funts"}, count);

    for (int i = 1; i < count; i++) {
      vt.addRow(i, i * rod_square, i * rod_funt);
    }

    vt.print(cout);
}
