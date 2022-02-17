#include <iostream>


using namespace std;

// 1 rod - - 
float rod_square = 28.3;
float rod_funt = 1000;

void drawTable(int count) {
  for (int i = 1; i < count; i++) {
    cout << "|" << i << " rod |\t" <<  i * rod_square << " square |\t" << i * rod_funt << " funt |\t" << endl;
  }
}


int main() {
  int count;

  cout << "Enter count of rows: ";
  cin >> count;

  drawTable(count);

  return 0;
}



