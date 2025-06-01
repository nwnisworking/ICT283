#include "Result.h"

Result::Result(){

}

float Result::GetMarks() const{
  return m_marks;
}

void Result::SetMarks(float marks){
  m_marks = marks;
}

void Result::GetUnit(Unit& unit) const{
  unit = m_unit;
}

void Result::SetUnit(const Unit& unit){
  m_unit = unit;
}

ostream& operator <<(ostream& output, const Result& result){
  Unit temp_unit;
  result.GetUnit(temp_unit);

  output << temp_unit << '\n'
         << " Marks: " << result.GetMarks() << '\n';

  return output;
}

istream& operator >>(istream& input, Result& result){
  Unit temp_unit;
  float marks;

  input >> temp_unit >> marks;
  
  result.SetMarks(marks);
  result.SetUnit(temp_unit);

  return input;
}

