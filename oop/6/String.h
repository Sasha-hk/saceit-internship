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
    String();
    String(string str);

    string getString();

    void setString(string node);

    friend istream& operator>>(std::istream, const String& str);

    friend ostream& operator<<(std::ostream, const String& str);

    friend string operator+(String left, String right);

    friend string operator-(String left, String right);

    friend int operator*(String left, String right);
};

#endif
