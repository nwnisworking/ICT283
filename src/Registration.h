#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

#include "Unit.h"
#include "Result.h"

using namespace std;

const unsigned MAX_RESULTS = 10;

class Registration{
  public:
  Registration();

  unsigned GetCredits() const;
  unsigned GetCount() const;

  friend ostream& operator <<(ostream& output, const Registration& registration);
  friend istream& operator >>(istream& input, Registration& registration);

  private:
  long m_studentId; // student ID number
  unsigned m_semester; // semester year, number
  unsigned m_count; // number of results
  Result m_results[MAX_RESULTS]; // array of results
};

#endif
