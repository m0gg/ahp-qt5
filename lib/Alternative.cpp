#include "Alternative.h"

Alternative::Alternative(AHPSet& ahpSet) : ahpSet(ahpSet) {
  criteriaChanged();
}

Alternative::Alternative(string name, AHPSet& ahpSet)
: name(name), ahpSet(ahpSet), ratingType(RATING_SIMPLE) {
  criteriaChanged();
}

void Alternative::setName(string name) {
  this->name = name;
}

string Alternative::getName() const {
  return name;
}

int Alternative::getRatingType() const {
  return ratingType;
}

void Alternative::criteriaChanged() {
  switch(this->ratingType) {
    case RATING_SIMPLE:
      this->criteriaRating.resize(this->ahpSet.getCriteria().size());
      break;
    case RATING_COMPLEX:
      throw "now implemented";
      break;
  }
}

vector<double>& Alternative::getCriteriaRating() {
  return criteriaRating;
}
