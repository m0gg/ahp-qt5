#ifndef CRITERION_H
#define	CRITERION_H

#include <stdio.h>
#include <string>
#include <vector>

#include "Mat.h"

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

#endif /* CRITERION_H */