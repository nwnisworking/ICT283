#include "Unit.h"

Unit::Unit(){
  m_name = "";
  m_id = "";
  m_credits = 0;
}

Unit::Unit(const string& name, const string& uid, unsigned credits){
  m_name = name;
  m_id = uid;
  m_credits = credits;
}

void Unit::GetName(string &name) const{
  name = m_name;
}

void Unit::SetName(const string& name){
  m_name = name;
}

void Unit::GetId(string &id) const{
  id = m_id;
}

void Unit::SetId(const string& id){
  m_id = id;
}

unsigned Unit::GetCredits() const{
  return m_credits;
}

void Unit::SetCredits(unsigned credits){
  m_credits = credits;
}

istream& operator >>(istream& input, Unit& unit){
  string temp_str;

  getline(input, temp_str, ',');
  unit.SetName(temp_str);

  getline(input, temp_str, ',');
  unit.SetId(temp_str);
  
  getline(input, temp_str, ',');
  unit.SetCredits(stoi(temp_str));

  return input;
}

ostream& operator <<(ostream& output, const Unit& unit){
  string name;
  string id;

  unit.GetName(name);
  unit.GetId(id);

  output << " Unit ID: " << id << '\n'
         << " Unit Name:   " << name << '\n'
         << " Credits: " << unit.GetCredits();

  return output;
}
