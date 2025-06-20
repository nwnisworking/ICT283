#include "MTime.h"

MTime::MTime(){
  m_hours = 0;
  m_minutes = 0;
}

MTime::MTime(unsigned hours, unsigned minutes){
  m_hours = hours % 24;
  m_minutes = minutes % 60;
}

unsigned MTime::GetHours() const{
  return m_hours;
}

void MTime::SetHours(unsigned hours){
  m_hours = hours % 24;
}

unsigned MTime::GetMinutes() const{
  return m_minutes;
}

void MTime::SetMinutes(unsigned minutes){
  m_minutes = minutes % 60;
}
