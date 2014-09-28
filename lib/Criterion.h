#ifndef CRITERION_H
#define	CRITERION_H

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Mat {
public:
  Mat();
  
  void set(unsigned int row, unsigned int col, double val);
  double get(unsigned int row, unsigned int col);
  
  vector<double> getNormalizedEigenvalues();
  
  Mat operator*(Mat& right);
  
  void push_back();
  
  vector< vector<double> > getData() const;
  
private:
  vector< vector<double> > data;
};

class Criterion {
public:
  Criterion();
  Criterion(string name);
  Criterion(const Criterion& orig);
  virtual ~Criterion();
  
  void setName(string name);
  string getName() const;
  
  void serialize(ostringstream *os);
  static Criterion deserialize(string data);
  
private:
  string name;
};


class CriterionMat {
public:
  CriterionMat();
  void push_back();
  Mat getData() const;
  
  void set(unsigned int row, unsigned int col, double val);
  double get(unsigned int row, unsigned int col);
  
  void serialize(ostringstream *os);
  static CriterionMat deserialize(string data);
  
private:
  Mat data;
};

class CriterionSet {
public:
  CriterionSet(vector<Criterion*>*, CriterionMat*);
  CriterionSet(string path);
  void exportSet(string path);
  CriterionMat* getCriteriaMat() const;
  vector<Criterion*>* getCriteria() const;
  
private:
  vector<Criterion*> *criteria;
  CriterionMat *criteriaMat;
  
  string getExport();
};

#endif /* CRITERION_H */