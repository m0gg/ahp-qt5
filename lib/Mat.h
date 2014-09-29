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
  void push_back_y();
  void push_back_y(unsigned int min_x_size);
  void push_back_x();
  
  unsigned int getRowCount();
  unsigned int getColCount();
  
  void resize(unsigned int rows, unsigned int cols);
  void swapRows(unsigned int fIdx, unsigned int sIdx);
  void swapCols(unsigned int fIdx, unsigned int sIdx);
  
  vector< vector<double> > getData() const;
  
private:
  vector< vector<double> > data;
  unsigned int colCount;
};

#endif	/* MAT_H */

