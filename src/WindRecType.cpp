#include "WindrecType.h"

void WindRecType::SetDayOfMonth(unsigned day_of_month){
  m_date.SetDayOfMonth(day_of_month);
}

unsigned WindRecType::GetDayOfMonth() const{
  return m_date.GetDayOfMonth();
}

void WindRecType::SetMonth(unsigned month){
  m_date.SetMonth(month);
}

unsigned WindRecType::GetMonth() const{
  return m_date.GetMonth();
}

void WindRecType::SetYear(unsigned year){
  m_date.SetYear(year);
}

unsigned WindRecType::GetYear() const{
  return m_date.GetYear();
}

void WindRecType::SetHours(unsigned hours){
  m_time.SetHours(hours);
}

unsigned WindRecType::GetHours() const{
  return m_time.GetHours();
}

void WindRecType::SetMinutes(unsigned minutes){
  m_time.SetMinutes(minutes);
}

unsigned WindRecType::GetMinutes() const{
  return m_time.GetMinutes();
}

void WindRecType::SetSpeed(float speed){
  m_speed = speed;
}

float WindRecType::GetSpeed() const{
  return m_speed;
}

void WindRecType::SetDate(const Date& date){
  m_date = date;
}

void WindRecType::SetTime(const Time& time){
  m_time = time;
}

void WindRecType::GetDate(Date &date) const{
  date = m_date;
}

void WindRecType::GetTime(Time &time) const{
  time = m_time;
}

istream& operator >>(istream& input, WindRecType& rec){
  Date date;
  Time time;
  string temp_str;

  getline(input, temp_str, '/');
  date.SetDayOfMonth(stoi(temp_str));

  getline(input, temp_str, '/');
  date.SetMonth(stoi(temp_str));

  getline(input, temp_str, ' ');
  date.SetYear(stoi(temp_str));

  getline(input, temp_str, ':');
  time.SetHours(stoi(temp_str));

  getline(input, temp_str, ',');
  time.SetMinutes(stoi(temp_str));

  getline(input, temp_str);
  rec.SetSpeed(stof(temp_str));

  rec.SetDate(date);
  rec.SetTime(time);

  return input;
}

ostream& operator <<(ostream& output, const WindRecType& rec){
  Date date;
  Time time;

  rec.GetDate(date);
  rec.GetTime(time);

  output << date << time << ',' << rec.GetSpeed();

  return output;
}
