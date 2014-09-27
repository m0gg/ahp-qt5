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

CriterionMat::CriterionMat() {
}

vector< vector<double> > CriterionMat::getData() const {
  return data;
}

void CriterionMat::serialize(ostringstream* os) {
  int size = this->data.size();
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      *os << this->get(i, j) << ";";
    }
  }
}

CriterionMat CriterionMat::deserialize(string data) {
  //CriterionMat tmp();
  return CriterionMat();
}


void CriterionMat::push_back() {
  for(int i = 0; i < data.size(); i++) {
    data[i].push_back(1.0);
  }
  vector<double> tmp;
  for(int i = 0; i < data.size()+1; i++) {
    tmp.push_back(1.0);
  }
  data.push_back(tmp);
}

double CriterionMat::get(unsigned int row, unsigned int col) {
  return this->data.at(row).at(col);
}

void CriterionMat::set(unsigned int row, unsigned int col, double val) {
  this->data.at(row).at(col) = val;
}

CriterionSet::CriterionSet(vector<Criterion*> *criteria, CriterionMat* criteriaMat) : criteria(criteria), criteriaMat(criteriaMat) {
}

void tokenize(const string& str, vector<string>& tokens, const string& delimiters = " ") {
  // Skip delimiters at beginning.
  string::size_type lastPos = str.find_first_not_of(delimiters, 0);
  // Find first "non-delimiter".
  string::size_type pos     = str.find_first_of(delimiters, lastPos);
  
  while (string::npos != pos || string::npos != lastPos)
  {
    // Found a token, add it to the vector.
    tokens.push_back(str.substr(lastPos, pos - lastPos));
    // Skip delimiters.  Note the "not_of"
    lastPos = str.find_first_not_of(delimiters, pos);
    // Find next "non-delimiter"
    pos = str.find_first_of(delimiters, lastPos);
  }
}

CriterionSet::CriterionSet(string path) {
  ifstream fis(path.c_str());
  string buf;
  if(fis.is_open()) {
    vector<string> tokens;
    this->criteria = new vector<Criterion*>();
    this->criteriaMat = new CriterionMat();
    while(getline(fis, buf)) {
      tokenize(buf, tokens, ";");
    }
    int i, criteria_count = atoi(tokens[0].c_str());
    for(i = 1; i <= criteria_count; i++) {
      this->criteria->push_back(new Criterion(tokens[i]));
      this->criteriaMat->push_back();
    }
    for(int j = 0; j < criteria_count; j++) {
      for(int k = 0; k < criteria_count; k++) {
        this->criteriaMat->set(j, k, atof(tokens[i++].c_str()));
      }
    }
  }
}

void CriterionSet::exportSet(string path) {
  string outStruct = getExport();
  FILE *f = fopen(path.c_str(), "w");
  if(f != NULL) {
    fwrite(outStruct.c_str(), outStruct.length(), 1, f);
    fclose(f);
  } else {
    throw "Could not open File";
  }
}

CriterionMat* CriterionSet::getCriteriaMat() const {
  return criteriaMat;
}

vector<Criterion*>* CriterionSet::getCriteria() const {
  return criteria;
}

string CriterionSet::getExport() {
  ostringstream os;
  os << criteria->size() << ";";
  for(int i = 0; i < criteria->size(); i++) {
    criteria->at(i)->serialize(&os);
  }
  CriterionMat *data = this->criteriaMat;
  data->serialize(&os);
  return os.str();
}
