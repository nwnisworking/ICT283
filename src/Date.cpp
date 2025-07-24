#include "Date.h"

Date::Date(){
  m_day_of_month = 1;
  m_year = 1;
  m_month = 1;
}

Date::Date(unsigned day_of_month, unsigned month, unsigned year){
  m_day_of_month = day_of_month % 32 == 0 ? 1 : day_of_month % 32;
  m_month = month % 13 == 0 ? 1 : month % 13;
  m_year = year;
}

void Date::SetYear(unsigned year){
  m_year = year;
}

unsigned Date::GetYear() const{
  return m_year;
}

void Date::SetMonth(unsigned month){
  m_month = month % 13 == 0 ? 1 : month % 13;
}

unsigned Date::GetMonth() const{
  return m_month;
}

void Date::SetDayOfMonth(unsigned day_of_month){
  m_day_of_month = day_of_month % 32 == 0 ? 1 : day_of_month % 32;
}

unsigned Date::GetDayOfMonth() const{
  return m_day_of_month;
}

const string& Date::MonthToString(unsigned month){
  if(month < 1 || month > 12){
    throw std::out_of_range("Month must be between 1 and 12");
  }

  static const string months[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
  };

  return months[month - 1];
}

int Date::GetValue() const{
  return m_year * 372 + m_month * 31 + m_day_of_month;
}

bool Date::operator <(const Date& other) const{
  return GetValue() < other.GetValue();
}

bool Date::operator >(const Date& other) const{
  return GetValue() > other.GetValue();
}

bool Date::operator ==(const Date& other)const{
  return GetValue() == other.GetValue();
}

bool Date::operator <=(const Date& other) const{
  return GetValue() <= other.GetValue();
}

bool Date::operator >=(const Date& other) const{
  return GetValue() >= other.GetValue();
}
