#include "AHPSet.h"

#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>
#include <iostream>

AHPSet::AHPSet() {
}

AHPSet::AHPSet(const AHPSet& orig) {
}

AHPSet::AHPSet(vector<Criterion*>& criteria, vector<Alternative*>& alternatives, Mat& criteriaRating)
: criteria(criteria), alternatives(alternatives), criteriaRating(criteriaRating) {
}

AHPSet::~AHPSet() {
}

Mat& AHPSet::getCriteriaRating() {
  return criteriaRating;
}

Mat& AHPSet::getAlternativesRating() {
  return alternativesRating;
}

vector<Alternative*>& AHPSet::getAlternatives() {
  return alternatives;
}

vector<Criterion*>& AHPSet::getCriteria() {
  return criteria;
}

void AHPSet::addCriterion(string name) {
  this->criteria.push_back(new Criterion(name, *this));
  criterionChanged();
}

void AHPSet::criterionChanged() {
  resizeRatings();
  recalcCriterionRatings();
}

void AHPSet::addAlternative(string name) {
  this->alternatives.push_back(new Alternative(name, *this));
  //alternativesChanged();
}

vector<double> AHPSet::getCriteriaRatings() const {
  return criteriaRatings;
}

void AHPSet::alternativesChanged() {
  throw "alternativesChanged() not implemented!";
}

void AHPSet::resizeRatings() {
  unsigned int cSize = criteria.size();
  this->criteriaRating.resize(cSize, cSize);
  
  for(int i = 0; i < alternatives.size(); i++) {
    this->alternatives[i]->criteriaChanged();
  }
}

void AHPSet::recalcCriterionRatings() {
  this->criteriaRatings = (criteriaRating*criteriaRating*
      criteriaRating*
      criteriaRating).getNormalizedEigenvalues();
}


void serialize(ostringstream& os, Mat& data) {
  int size = data.getData().size();
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      os << data.get(i, j) << ";";
    }
  }
}

void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ") {
  // Skip delimiters at beginning.
  string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  // Find first "non-delimiter".
  string::size_type pos = str.find_first_of(delimiters, lastPos);
  
  while(string::npos != pos || string::npos != lastPos) {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);
    // Find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
}

string AHPSet::getExport() {
  ostringstream os;
  os << criteria.size() << ";";
  for(int i = 0; i < criteria.size(); i++) {
    //criteria[i]->serialize(&os);
  }
  serialize(os, criteriaRating);
  return os.str();
}

void AHPSet::exportSet(string path) {
  ofstream fos(path.c_str());
  string outStruct = getExport();
  if(fos.is_open()) {
    fos.write(outStruct.c_str(), outStruct.length());
    fos.close();
  } else {
    throw "Could not open File";
  }
}

AHPSet::AHPSet(string path) {
  ifstream fis(path.c_str());
  string buf;
  if(fis.is_open()) {
    vector<string> tokens;
    while(getline(fis, buf)) {
      tokenize(buf, tokens, ";");
    }
    int i, criteria_count = atoi(tokens[0].c_str());
    for(i = 1; i <= criteria_count; i++) {
      //this->criteria.push_back(new Criterion(tokens[i]));
      //this->criteriaRating.push_back();
    }
    for(int j = 0; j < criteria_count; j++) {
      for(int k = 0; k < criteria_count; k++) {
        this->criteriaRating.set(j, k, atof(tokens[i++].c_str()));
      }
    }
  }
}
