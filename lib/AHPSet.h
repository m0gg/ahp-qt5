#ifndef AHPSET_H
#define	AHPSET_H

#include "Criterion.h"
#include "Mat.h"

using namespace std;

class AHPSet {
public:
  AHPSet();
  AHPSet(const AHPSet& orig);
  AHPSet(vector<Criterion>& criteria, Mat& criteriaRating);
  AHPSet(string path);
  virtual ~AHPSet();
  
  void exportSet(string path);
  
  void setCriteriaRating(Mat criteriaRating);
  Mat& getCriteriaRating();
  
  void setCriteria(vector<Criterion> criteria);
  vector<Criterion>& getCriteria();

private:
  vector<Criterion> criteria;
  Mat criteriaRating;
  
  string getExport();
};

#endif	/* AHPSET_H */

