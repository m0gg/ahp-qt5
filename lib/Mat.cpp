#include "Mat.h"

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
  push_back_y();
  push_back_x();
}

void Mat::push_back_y() {
  vector<double> tmp;
  for(int i = 0; i < data.size(); i++) {
    tmp.push_back(1.0);
  }
  data.push_back(tmp);
}

void Mat::push_back_y(unsigned int min_x_size) {
  vector<double> tmp;
  for(int i = 0; i < min_x_size; i++) {
    tmp.push_back(1.0);
  }
  data.push_back(tmp);
}

void Mat::push_back_x() {
  for(int i = 0; i < data.size(); i++) {
    data[i].push_back(1.0);
  }
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
