#ifndef CRITERION_H
#define	CRITERION_H

#include <stdio.h>
#include <string>
#include <vector>

#include "libahp.h"

using namespace std;

class Criterion {
public:
  Criterion(AHPSet& ahpSet);
  Criterion(string name, AHPSet& ahpSet);
  
  void setName(string name);
  string getName() const;
  
  /*void serialize(ostringstream *os);
  static Criterion deserialize(string data);*/
    
private:
  string name;
  AHPSet& ahpSet;
  
  void setupAhpSet();
};

#endif /* CRITERION_H */