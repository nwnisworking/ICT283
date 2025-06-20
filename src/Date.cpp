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
