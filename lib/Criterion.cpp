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

CriterionMat::CriterionMat() {

}

vector<vector<double>*> CriterionMat::getData() const {
  return data;
}

void CriterionMat::push_back() {
  for(int i = 0; i < data.size(); i++) {
    data[i]->push_back(1.0);
  }
  int nSize = data.size()+1;
  vector<double> *nVec = new vector<double>();
  for(int i = 0; i < nSize; i++) {
    nVec->push_back(1.0);
  }
  data.push_back(nVec);
}

double CriterionMat::get(unsigned int row, unsigned int col) {
  return this->data.at(row)->at(col);
}

void CriterionMat::set(unsigned int row, unsigned int col, double val) {
  this->data.at(row)->at(col) = val;
}
