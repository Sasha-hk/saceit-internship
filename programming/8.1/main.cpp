#include <iostream>
#include <cmath>
#include <ctime>
#include <string>


using namespace std;

struct weapon {
  int licenseNumber;
  string fullName;
  string dateOfIssue;
  string veaponType;
  string price;
};

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

void fillData(int count, weapon *data) {
  int licenseNumber;
  string fullName;
  string dateOfIssue;
  string veaponType;
  string price;

  for (int i = 0; i < count; i++) {
    licenseNumber = randint(10000, 99999);
    cout << "Enter full name: ";
    // getline(cin, fullName);
    cin >> fullName;

    cout << "Enter date of issue: ";
    // getline(cin, dateOfIssue);
    cin >> dateOfIssue;

    cout << "Enter veapon type: ";
    cin >> veaponType;
    // getline(cin, veaponType);

    cout << "Enter price: ";
    // getline(cin, price);
    cin >> price;

    cout << endl;

    data[i].licenseNumber = licenseNumber;
    data[i].fullName = fullName;
    data[i].dateOfIssue = dateOfIssue;
    data[i].veaponType = veaponType;
    data[i].price = price;
  }
}

void showData(int count, weapon *data) {
  for (int i = 0; i < count; i++) {
    cout << "License number: " << data[i].licenseNumber << endl;
    cout << "Full name: " << data[i].fullName << endl;
    cout << "Data of issue: " << data[i].dateOfIssue << endl;
    cout << "Veapon type: " << data[i].veaponType << endl;
    cout << "Price: " << data[i].price << endl;
    cout << endl;
  }
}

void sortByLicenseNumber(int count, weapon *data) {
  weapon node;

  for (int i = 0; i < count; i++) {
    for (int j = 0; j < count; j++) {
      if (data[i].licenseNumber < data[j].licenseNumber) {
        node = data[j];
        data[j] = data[i];
        data[i] = node;
      }
    }
  }
}

void getWIthType(int count, weapon *data) {
  string type;

  cout << "Enter weapon type: ";
  cin >> type;

  for (int i = 0; i < count; i++) {
    if (data[i].veaponType == type) {
      cout << endl;
      cout << "License number: " << data[i].licenseNumber << endl;
      cout << "Full name: " << data[i].fullName << endl;
      cout << "Data of issue: " << data[i].dateOfIssue << endl;
      cout << "Veapon type: " << data[i].veaponType << endl;
      cout << "Price: " << data[i].price << endl;
      cout << endl;
    }
  }
}

void makeSomething(int count) {
  cout << "Enter count of weaponse: ";
  cin >> count;

  weapon *weapons = new weapon[count];

  cout << "Fill data" << endl;
  fillData(count, weapons);
  cout << endl;

  cout << "Show data: " << endl;
  showData(count, weapons);

  sortByLicenseNumber(count, weapons);

  cout << "\n\nData after sort: \n\n";
  showData(count, weapons);

  getWIthType(count, weapons);
}

int  main() {
  srand(time(NULL));
  int count;

  makeSomething(count);

  return 0;
}
