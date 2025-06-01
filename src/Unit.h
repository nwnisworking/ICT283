#ifndef UNIT_H
#define UNIT_H

#include <iostream>

using namespace std;

const unsigned UNIT_NAME_SIZE = 50;
const unsigned UNIT_ID_SIZE = 7;

class Unit{
  public:
  Unit();
  Unit(const char* name, const char* uid, unsigned credits);

  unsigned GetCredits() const;
  void SetCredits(unsigned credits);

  friend ostream& operator <<(ostream& output, const Unit& unit);
  friend istream& operator >>(istream& input, Unit& unit);

  private:
  char m_name[UNIT_NAME_SIZE + 1]; // Unit name, C style string. not a C++ string object
  char m_id[UNIT_ID_SIZE + 1];
  unsigned m_credits; // number of credits
};

#endif