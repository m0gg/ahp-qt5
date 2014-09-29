#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <iterator>
#include <stdlib.h> 

#include "Criterion.h"

Criterion::Criterion(AHPSet& ahpSet) : ahpSet(ahpSet) {
  setupAhpSet();
}

Criterion::Criterion(string name, AHPSet& ahpSet) 
  : name(name), ahpSet(ahpSet) {
  setupAhpSet();
}

void Criterion::setupAhpSet() {
}

void Criterion::setName(string name) {
  this->name = name;
}

string Criterion::getName() const {
  return name;
}

/*void Criterion::serialize(ostringstream *os) {
  *os << this->name << ';';
}

Criterion Criterion::deserialize(string data) {
  return Criterion(data);
}*/
