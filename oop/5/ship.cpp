#include "ship.h"
#include <iostream>
#include <string>

using namespace std;

Ship::Ship() {}

Ship::Ship(
  string name,
  string type,
  int loadCapacity
) {
  this->name = name;
  this->type = type;
  this->loadCapacity = loadCapacity;
}

Ship::Ship(Ship *instance) {
  this->name = instance->name;
  this->type = instance->type;
  this->loadCapacity = instance->loadCapacity;
}

void Ship::show() {
  cout << "Name: " << name << endl;
  cout << "Type: " << type << endl;
  cout << "Load capacity: " << loadCapacity << endl;
}

void Ship::set(
  string name,
  string type,
  int loadCapacity
) {
  this->name = name;
  this->type = type;
  this->loadCapacity = loadCapacity;
}



Ship::~Ship() {
  // no need to free some date
}
