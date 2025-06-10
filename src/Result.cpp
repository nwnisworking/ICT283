#include "Result.h"

Result::Result(){
  m_marks = 0;
}

Result::Result(float marks, const Unit& unit, const Date& date){
  m_marks = marks;
  m_unit = unit;
  m_date = date;
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

void Result::SetDate(const Date& date){
  m_date = date;
}

void Result::GetDate(Date& date) const{
  date = m_date;
}

ostream& operator <<(ostream& output, const Result& result){
  Unit temp_unit;
  Date temp_date;

  result.GetUnit(temp_unit);
  result.GetDate(temp_date);

  output << temp_unit << '\n'
         << " Marks: " << result.GetMarks() << '\n'
         << " Date: " << temp_date << '\n';

  return output;
}

istream& operator >>(istream& input, Result& result){
  Unit temp_unit;
  Date temp_date;
  string temp_str;

  input >> temp_unit;
  result.SetUnit(temp_unit);

  getline(input, temp_str, ',');
  result.SetMarks(stoi(temp_str));

  input >> temp_date;
  result.SetDate(temp_date);

  return input;
}
