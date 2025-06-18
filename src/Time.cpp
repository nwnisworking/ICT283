#include "Time.h"

Time::Time(){
  m_hours = 0;
  m_minutes = 0;
}

Time::Time(unsigned hours, unsigned minutes){
  m_hours = hours;
  m_minutes = minutes;
}

unsigned Time::GetHours() const{
  return m_hours;
}

void Time::SetHours(unsigned hours){
  m_hours = hours % 24;
}

unsigned Time::GetMinutes() const{
  return m_minutes;
}

void Time::SetMinutes(unsigned minutes){
  m_minutes = minutes % 60;
}
