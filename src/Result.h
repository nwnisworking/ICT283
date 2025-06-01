#ifndef RESULT_H
#define RESULT_H

#include <iostream>

#include "Unit.h"

class Result{
  public:
  Result();
  virtual ~Result(){};
  
  float GetMarks() const;
  void SetMarks(float marks);

  void GetUnit(Unit& unit) const;
  void SetUnit(const Unit& unit);

  friend ostream& operator <<(ostream& output, const Result& result);
  friend istream& operator >>(istream& input, Result& result);
  
  private:
  Unit m_unit;
  float m_marks;
};

#endif