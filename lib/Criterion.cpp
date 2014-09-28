#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <iterator>
#include <stdlib.h> 

#include "Criterion.h"

Mat::Mat() {
}

double Mat::get(unsigned int row, unsigned int col) {
  return this->data.at(row).at(col);
}

void Mat::set(unsigned int row, unsigned int col, double val) {
  this->data.at(row).at(col) = val;
}

vector< vector<double> > Mat::getData() const {
  return data;
}

void Mat::push_back() {
  for(int i = 0; i < data.size(); i++) {
    data[i].push_back(1.0);
  }
  vector<double> tmp;
  for(int i = 0; i < data.size()+1; i++) {
    tmp.push_back(1.0);
  }
  data.push_back(tmp);
}

vector<double> Mat::getNormalizedEigenvalues() {
  vector<double> result, tmp;
  double colSum = 0.0;
  for(int row = 0; row < data.size(); row++) {
    double sum = 0.0;
    for(int col = 0; col < data.size(); col++) {
      sum += get(row, col);
    }
    colSum += sum;
    tmp.push_back(sum);
  }
  for(int row = 0; row < data.size(); row++) {
    result.push_back(tmp[row]/colSum);
  }
  return result;
}

Mat Mat::operator*(Mat& right) {
  Mat result;
  for(int i = 0; i < data.size(); i++) result.push_back();
  for(int row = 0; row < data.size(); row++) {
    for(int col = 0; col < data.size(); col++) {
      result.set(row, col, get(row, 0)*right.get(0, col) + get(row, 1)*right.get(1, col) + get(row, 2)*right.get(2, col));
    }
  }
  return result;
}


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

Mat CriterionMat::getData() const {
  return data;
}

void CriterionMat::serialize(ostringstream* os) {
  int size = data.getData().size();
  for(int i = 0; i < size; i++) {
    for(int j = 0; j < size; j++) {
      *os << data.get(i, j) << ";";
    }
  }
}

CriterionMat CriterionMat::deserialize(string data) {
  //CriterionMat tmp();
  return CriterionMat();
}

double CriterionMat::get(unsigned int row, unsigned int col) {
  return data.get(row, col);
}

void CriterionMat::set(unsigned int row, unsigned int col, double val) {
  data.set(row, col, val);
}

void CriterionMat::push_back() {
  data.push_back();
}

CriterionSet::CriterionSet(vector<Criterion*> *criteria, CriterionMat* criteriaMat) : criteria(criteria), criteriaMat(criteriaMat) {
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
  ofstream fos(path.c_str());
  string outStruct = getExport();
  if(fos.is_open()) {
    fos.write(outStruct.c_str(), outStruct.length());
    fos.close();
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
