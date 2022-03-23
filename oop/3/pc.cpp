#include "pc.h"
#include <iostream>

using namespace std;

HDD::HDD() {}

HDD::HDD(int Mb):Mb(Mb) {}

int HDD::getSize() {
  return Mb;
}

HDD::~HDD() {
  // no need to free any date
}

PC::PC(
  HDD storage,
  string model,
  string price
) {
  this->storage = storage;
  this->model = model;
  this->price = price;
}

HDD PC::getStorage() {
  return storage;
}

PC::~PC() {
  // no need to free any date
}

PCExtended::PCExtended(
  HDD storage,
  string model,
  string price,
  float screenDiagonal
):PC(storage, model, price) {
  this->screenDiagonal = screenDiagonal;
}

int PCExtended::getScreenDiagonal() {
  return screenDiagonal;
}

PCExtended::~PCExtended() {
  // no need to free any date
}
