#include "Alternative.h"

Alternative::Alternative() {
}

Alternative::Alternative(string name) : name(name) {
}

Alternative::Alternative(const Alternative& orig) {
}

Alternative::~Alternative() {
}

void Alternative::setName(string name) {
  this->name = name;
}

string Alternative::getName() const {
  return name;
}

