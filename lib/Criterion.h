#ifndef CRITERION_H
#define	CRITERION_H

#include <string>

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

#endif /* CRITERION_H */