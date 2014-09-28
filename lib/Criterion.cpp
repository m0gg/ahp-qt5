#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <iterator>
#include <stdlib.h> 

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

void Criterion::serialize(ostringstream *os) {
  *os << this->name << ';';
}

Criterion Criterion::deserialize(string data) {
  return Criterion(data);
}
