#ifndef CRITERION_H
#define	CRITERION_H

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

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
  vector< vector<double> > getData() const;
  
  void set(unsigned int, unsigned int, double);
  double get(unsigned int, unsigned int);
  
  void serialize(ostringstream *os);
  static CriterionMat deserialize(string data);
  
private:
  vector< vector<double> > data;
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