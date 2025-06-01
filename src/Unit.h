#ifndef UNIT_H
#define UNIT_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;
using std::stoi;
using std::getline;

class Unit{
  public:
  Unit();
  Unit(const string& name, const string& uid, unsigned credits);

  void GetName(string& name) const;
  void SetName(const string& name);

  void GetId(string& id) const;
  void SetId(const string& id);

  unsigned GetCredits() const;
  void SetCredits(unsigned credits);

  private:
  string m_name; // Unit name
  string m_id; // Unit ID
  unsigned m_credits; // number of credits
};

ostream& operator <<(ostream& output, const Unit& unit);
istream& operator >>(istream& input, Unit& unit);

#endif
