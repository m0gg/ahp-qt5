#ifndef CRITERION_H
#define	CRITERION_H

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
  
private:
  string name;
};


class CriterionMat {
public:
  CriterionMat();
  void push_back();
  vector<vector<double>*> getData() const;
  
  void set(unsigned int, unsigned int, double);
  double get(unsigned int, unsigned int);
  
private:
  vector< vector<double>* > data;
};

#endif /* CRITERION_H */