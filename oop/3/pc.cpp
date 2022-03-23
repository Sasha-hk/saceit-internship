#include "pc.h"
#include <iostream>

using namespace std;

HDD::HDD(int Mb):Mb(Mb) {}

int HDD::getSize() {
  return Mb;
}

HDD::~HDD() {
  // no need to free any date
}

PC::PC(
  HDD storage,
  string* model,
  int price
) {
  this->storage = storage;
  this->model = model;
  this->price = price;
}

PC::~PC() {
  delete model;
}

PCExtended::PCExtended(
  HDD storage,
  string* model,
  int price,
  float screenDiagonal
) {
  this->storage = storage;
  this->model = model;
  this->price = price;
  this->screenDiagonal = screenDiagonal;
}

int PCExtended::getScreenDiagonal() {
  return screenDiagonal;
}

PCExtended::~PCExtended() {
  // no need to free any date
}
