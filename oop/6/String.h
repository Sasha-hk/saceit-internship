#pragma once
#ifndef STRING_H
#define STRING_H

#include <string>

using namespace std;

class String {
  private:

  protected:
    string str;

  public:
    String() {}
    String(string str):str(str) {}

    string getString() {
      return str;
    }

    void setString(string node) {
      str = node;
    }

    friend istream& operator>>(std::istream& is, String& str) {
      string node;
      is >> node;
      str.setString(node);
      return is;
    }

    friend ostream& operator<<(ostream& out, String& str) {
      out << str.getString();
      return out;
    }

    friend string operator+(String left, String right) {
      return left.getString() + right.getString();
    }

    friend string operator-(String left, String right) {
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

    friend int operator*(String left, String right) {
      int p = left.str.find(right.str[0]);

      return p;
    }
};

#endif
