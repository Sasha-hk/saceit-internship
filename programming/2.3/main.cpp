#include <iostream>
#include <cmath>
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
  "nine",
  "ten"
};

string dozensNumberView[] = {
  "",
  "Ten",
  "Twenty",
  "Thirty",
  "Fourty",
  "Fifty",
  "Sixty",
  "Seventy",
  "Eighty",
  "Ninety"
};

string toTwenty[] = {
  "",
  "eleven",
  "twelve",
  "thirteen",
  "fuorteen",
  "fifteen",
  "sixteen",
  "seventenn",
  "eightenn",
  "ninetenn"
};

int randint(int min, int max) {
  return rand() % (max + 1 - min) + min;
}

string parseNaturalNumbers(int number) {
  // parse natural numbers 
  if (number % 10) {
    return naturalNumberView[number % 10] + ' ';
  }
  return "";
}

string parseNumberYear(int number) {
  string outString;
  int toHundred = floor(number / 10);

  // parse dozens number
  if (number >= 20) {
    outString += dozensNumberView[toHundred] + ' ';
    outString += parseNaturalNumbers(number);
  }
  else if (number <= 20 && number >= 11) {
    outString += toTwenty[number % 10] + ' ';
  }
  else if (number <= 10) {
    outString += naturalNumberView[number] + ' ';
  }
  
  return outString;
}

int main() {
  srand(time(NULL));
  
  int yearNumber = randint(20, 69);

  cout << "Year number: " << yearNumber << endl;

  cout << parseNumberYear(yearNumber) << endl;
 
  return 0;
}
