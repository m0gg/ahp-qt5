#include "Criterion.h"

Criterion::Criterion() {
}

Criterion::Criterion(string name) : name(name) {
}

Criterion::Criterion(const Criterion& orig) {
}

Criterion::~Criterion() {
}

void Criterion::setName(string name) {
  this->name = name;
}

string Criterion::getName() const {
  return name;
}

