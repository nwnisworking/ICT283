#ifndef RESULT_H
#define RESULT_H

#include <iostream>
#include "Unit.h"
#include "Date.h"

class Result{
  public:
  Result();
  Result(float marks, const Unit& unit, const Date& date);
  virtual ~Result(){};
  
  void SetMarks(float marks);
  float GetMarks() const;

  void SetUnit(const Unit& unit);
  void GetUnit(Unit& unit) const;

  void SetDate(const Date& date);
  void GetDate(Date& date) const;
  
  private:
  Unit m_unit;
  float m_marks;
  Date m_date;
};

ostream& operator <<(ostream& output, const Result& result);
istream& operator >>(istream& input, Result& result);

#endif