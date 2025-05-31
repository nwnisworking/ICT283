#include "Course.h"

#include <string.h>

Course::Course(){
  name[0] = '\0';
}

Course::Course(const char* nam, char sect, unsigned cred){
  strncpy(name, name, COURSE_NAME_SIZE);
  section = sect;
  credits = cred;
}

unsigned Course::GetCredits() const{
  return credits;
}

void Course::SetCredits(unsigned cred){
  credits = cred;
}

istream& operator >>(istream& input, Course& C){
  input >> C.name >> C.section >> C.credits;
  return input;
}

ostream& operator <<(ostream& os, const Course& C){
  os << " Course: " << C.name << '\n'
     << " Section: " << C.section << '\n'
     << " Credits: " << C.credits << '\n';

  return os;
}