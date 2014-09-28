#ifndef MAT_H
#define	MAT_H

#include <vector>

using namespace std;

class Mat {
public:
  Mat();
  
  void set(unsigned int row, unsigned int col, double val);
  double get(unsigned int row, unsigned int col);
  
  vector<double> getNormalizedEigenvalues();
  
  Mat operator*(Mat& right);
  
  void push_back();
  
  vector< vector<double> > getData() const;
  
private:
  vector< vector<double> > data;
};

#endif	/* MAT_H */

