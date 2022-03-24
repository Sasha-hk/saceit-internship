#include "String.h"
#include <iostream>

using namespace std;

String::String() {}

String::String(string str):str(str) {}

string String::getString() {
  return str;
}

void String::setString(string node) {
  str = node;
}

istream& operator>>(istream& is, String& str) {
  string node;
  is >> node;
  str.setString(node);
  return is;
}

ostream& operator<<(ostream& out, String& str) {
  out << str.getString();
  return out;
}

string operator+(String left, String right) {
  return left.getString() + right.getString();
}

string operator-(String left, String right) {
  string node;
  string leftStr = left.str;
  string rightStr = right.str;
  int startIndex = 0;
  int endIndex = 0;
  int hit = 0;

  for (int i = 0; i < leftStr.length(); i++) {
    if (leftStr[i] == rightStr[hit] || hit == rightStr.length()) {
      if (hit == 0) {
        startIndex = i;
      }

      hit++;

      if (hit == rightStr.length()) {
        endIndex = i;
        break;
      }
    }
    else {
      hit = 0;
    }
  }

  return leftStr.substr(0, startIndex) + leftStr.substr(endIndex, -1);
}

int operator*(String left, String right) {
  int p = left.str.find(right.str[0]);

  return p;
}
