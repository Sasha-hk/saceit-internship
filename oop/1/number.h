#pragma once
#ifndef COMPLEX_H
#define COMPLEX_H

class Number {
  private:
  protected:
    int first;
    int second;
  public:
    Number(int first, int second);
    double multiply(int multiplier, double other);
    int getFirst();
    int getSecond();
    void enter();
    void display();
};

#endif
