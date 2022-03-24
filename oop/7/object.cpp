#pragma once
#include <iostream>
#include <cmath>

using namespace std;

class Formula {
  private:
  protected:
    float x = 0;
    float a = 1.67;
    float R = 2.31;
    float L = 0.89;
  public:
    Formula() {
      x = (sqrt(M_PI)) / (a * R * L) + sin(a * 2);
    }

    float getX() {
      return x;
    }
};
