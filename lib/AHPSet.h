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
  vector<double> getAlternativesRatings() const;
  
  void addCriterion(string name);
  void addAlternative(string name);

  void recalcCriteriaRatings();
  void recalcAlternativesRatings();
  
private:
  void resizeRatings();
  
  void criterionChanged();
  void alternativesChanged();
  
  vector<Criterion*> criteria;
  vector<Alternative*> alternatives;
  Mat criteriaRating;
  //Mat alternativesRating;
  vector<double> criteriaRatings;
  vector<double> alternativesRatings;
  
  
  string getExport();
};

#endif	/* AHPSET_H */

