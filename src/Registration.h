#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <iostream>

#include "Course.h"

using namespace std;

const unsigned MAX_COURSES = 10;

class Registration{
  public:
  Registration();

  unsigned GetCredits() const;
  unsigned GetCount() const;

  friend ostream& operator <<(ostream& os, const Registration& R);
  friend istream& operator >>(istream& input, Registration& R);

  private:
  long studentId; // student ID number
  unsigned semester; // semester year, number
  unsigned count; // number of courses
  Course courses[MAX_COURSES]; // array of courses
};

#endif
