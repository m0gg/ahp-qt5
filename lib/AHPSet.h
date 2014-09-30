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
  vector<double> getCriteriaRatings() const;
  
  void addCriterion(string name);
  void addAlternative(string name);

  void recalcCriterionRatings();
  
private:
  void resizeRatings();
  
  void criterionChanged();
  void alternativesChanged();
  
  vector<Criterion*> criteria;
  vector<Alternative*> alternatives;
  Mat criteriaRating;
  Mat alternativesRating;
  vector<double> criteriaRatings;
  
  
  string getExport();
};

#endif	/* AHPSET_H */

