/* 
 * File:   Alternative.h
 * Author: marcel
 *
 * Created on 29. September 2014, 00:19
 */

#ifndef ALTERNATIVE_H
#define	ALTERNATIVE_H

#include <string>

using namespace std;

class Alternative {
public:
  Alternative();
  Alternative(string name);
  Alternative(const Alternative& orig);
  virtual ~Alternative();
  
  void setName(string name);
  string getName() const;
  
private:
  string name;

};

#endif	/* ALTERNATIVE_H */

