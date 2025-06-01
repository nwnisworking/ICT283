#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

#include "Unit.h"
#include "Result.h"

using std::stol;
using std::stoi;
using std::istream;
using std::ostream;

const unsigned MAX_RESULTS = 10;

class Registration{
  public:
  Registration();

  unsigned GetCredits() const;

  void SetCount(unsigned count);
  unsigned GetCount() const;

  void SetStudentId(long id);
  long GetStudentId() const;

  void SetSemester(unsigned semester);
  unsigned GetSemester() const;

  void SetResult(const Result& result, unsigned index);
  void GetResult(Result& result, unsigned index) const;

  private:
  long m_studentId; // student ID number
  unsigned m_semester; // semester year, number
  unsigned m_count; // number of results
  Result m_results[MAX_RESULTS]; // array of results
};

ostream& operator <<(ostream& output, const Registration& registration);
istream& operator >>(istream& input, Registration& registration);

#endif
