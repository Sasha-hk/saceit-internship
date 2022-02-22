#include <iostream>
#include <cmath>
#include <ctime>
#include <string>


using namespace std;

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

int  main() {
  srand(time(NULL));

  string fullName;

  cout << "Enter full name: ";

  getline(cin, fullName);

  cout << "Lenght: " << fullName.length() << endl;

  int charCount = 0;
  for (int i = 0; i < fullName.length(); i++) {
    if (fullName[i] == 'a' || fullName[i] == 'A') {
      charCount++;
    }
  }

  cout << "Count of 'a' letter: " << charCount << endl;

  cout << "Full name: " << fullName << endl;

  int lastNameIndex = 0;
  int fatherNameIndex = 0;
  for (int i = 0; i < fullName.length(); i++) {
    if (lastNameIndex == 0 && fullName[i] == ' ') {
      lastNameIndex = i + 1;
    }
    else if (fatherNameIndex == 0 && fullName[i] == ' ') {
      fatherNameIndex = i;
    }
  }

  cout << "Name length: " << fatherNameIndex - lastNameIndex << endl;

  return 0;
}
