#pragma once
#ifndef SHIP_H
#define SHIP_H

#include <iostream>
#include <string>

using namespace std;

class Ship {
  private:
  protected:
    string name;
    string type;
    int loadCapacity;


  public:
    Ship();

    Ship(
      string name,
      string type,
      int loadCapacity
    );

    Ship(Ship *instance);

    void show();

    void set(
      string name,
      string type,
      int loadCapacity
    );

    ~Ship();
};

#endif
