#ifndef AHPSET_H
#define	AHPSET_H

#include "Criterion.h"
#include "Alternative.h"
#include "Mat.h"

using namespace std;

class AHPSet {
public:
  AHPSet();
  AHPSet(const AHPSet& orig);
  AHPSet(vector<Criterion*>& criteria, vector<Alternative*>& alternatives, Mat& criteriaRating);
  AHPSet(string path);
  virtual ~AHPSet();
  
  void exportSet(string path);
  
  void setCriteriaRating(Mat criteriaRating);
  Mat& getCriteriaRating();
  
  void setAlternativesRating(Mat criteriaRating);
  Mat& getAlternativesRating();
  
  void setCriteria(vector<Criterion*> criteria);
  vector<Criterion*>& getCriteria();
  
  void setAlternatives(vector<Alternative*> alternatives);
  vector<Alternative*>& getAlternatives();

private:
  vector<Criterion*> criteria;
  vector<Alternative*> alternatives;
  Mat criteriaRating;
  Mat alternativesRating;
  
  string getExport();
};

#endif	/* AHPSET_H */

