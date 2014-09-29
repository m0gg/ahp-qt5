/* 
 * File:   Alternative.h
 * Author: marcel
 *
 * Created on 29. September 2014, 00:19
 */

#ifndef ALTERNATIVE_H
#define	ALTERNATIVE_H

#include "libahp.h"

#define RATING_SIMPLE  0x01
#define RATING_COMPLEX 0x10

using namespace std;

class Alternative {
public:
  Alternative(AHPSet& ahpSet);
  Alternative(string name, AHPSet& ahpSet);
  
  void setName(string name);
  string getName() const;

  int getRatingType() const;
  vector<double>& getCriteriaRating();
  
  void criteriaChanged();
  
  
private:
  string name;
  int ratingType;
  
  AHPSet& ahpSet;
  vector<double> criteriaRating;
  
  void setupAhpSet();
};

#endif	/* ALTERNATIVE_H */

