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
  
  Mat& getCriteriaRating();
  Mat& getAlternativesRating();
  vector<Alternative*>& getAlternatives();
  vector<Criterion*>& getCriteria();
  
  void addCriterion(string name);
  void addAlternative(string name);
  
private:
  void resizeRatings();
  
  void criterionChanged();
  void alternativesChanged();
  
  vector<Criterion*> criteria;
  vector<Alternative*> alternatives;
  Mat criteriaRating;
  Mat alternativesRating;
  
  
  
  string getExport();
};

#endif	/* AHPSET_H */

