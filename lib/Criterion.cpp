#include <sstream>
#include <string.h>
#include <iterator>

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

CriterionSet::CriterionSet(string path) {
  FILE *f = fopen(path.c_str(), "rb");
  if(f != NULL) {
    
    fclose(f);
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
