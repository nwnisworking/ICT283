#include "Unit.h"

#include <string.h>

Unit::Unit(){
  m_name[0] = '\0';
  m_id[0] = '\0';
  m_credits = 0;
}

Unit::Unit(const char* name, const char* uid, unsigned credits){
  strncpy(m_name, name, UNIT_NAME_SIZE);
  strncpy(m_id, uid, UNIT_ID_SIZE);
  m_credits = credits;
}

unsigned Unit::GetCredits() const{
  return m_credits;
}

void Unit::SetCredits(unsigned credits){
  m_credits = credits;
}

istream& operator >>(istream& input, Unit& unit){
  input >> unit.m_name >> unit.m_id >> unit.m_credits;
  return input;
}

ostream& operator <<(ostream& output, const Unit& unit){
  output << " Unit ID: " << unit.m_id << '\n'
         << " Unit Name:   " << unit.m_name << '\n'
         << " Credits: " << unit.m_credits;

  return output;
}