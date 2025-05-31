#ifndef COURSE_H
#define COURSE_H

#include <iostream>

using namespace std;

const unsigned COURSE_NAME_SIZE = 10;

class Course{
  public:
  Course();
  Course(const char* nam, char sect, unsigned cred);

  unsigned GetCredits() const;
  void SetCredits(unsigned cred);

  friend istream& operator >>(istream& input, Course& C);
  friend ostream& operator <<(ostream& os, const Course& C);

  private:
  char name[COURSE_NAME_SIZE]; // course name, C style string. not a C++ string object
  char section; // section (letter) can be enrolment mode
  unsigned credits; // number of credits
};

#endif
