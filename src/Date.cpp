#include "Date.h"

Date::Date(){
  m_day_of_month = 0;
  m_year = 0;
  m_month = 0;
}

Date::Date(unsigned day_of_month, unsigned month, unsigned year){
  m_day_of_month = day_of_month;
  m_month = month;
  m_year = year;
}

void Date::SetYear(unsigned year){
  m_year = year;
}

unsigned Date::GetYear() const{
  return m_year;
}

void Date::SetMonth(unsigned month){
  m_month = month;
}

unsigned Date::GetMonth() const{
  return m_month;
}

void Date::SetDayOfMonth(unsigned day_of_month){
  m_day_of_month = day_of_month;
}

unsigned Date::GetDayOfMonth() const{
  return m_day_of_month;
}

ostream& operator <<(ostream& output, const Date& date){
  output << date.GetDayOfMonth() << '/' << date.GetMonth() << '/' << date.GetYear();
  return output;
}

istream& operator >>(istream& input, Date& date){
  string temp_str;

  getline(input, temp_str, '/');
  date.SetDayOfMonth(stoi(temp_str));

  getline(input, temp_str, '/');
  date.SetMonth(stoi(temp_str));

  getline(input, temp_str);
  date.SetYear(stoi(temp_str));

  return input;
}
