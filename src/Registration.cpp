#include "Registration.h"

Registration::Registration(){
  m_count = 0;
}

unsigned Registration::GetCredits() const{
  unsigned sum = 0;
  Unit temp_unit;

  for(unsigned i = 0; i < m_count; i++){
    m_results[i].GetUnit(temp_unit);
    sum+= temp_unit.GetCredits();
  }

  return sum;
}

unsigned Registration::GetCount() const{
  return m_count;
}

istream & operator >>(istream & input, Registration & registration){
   input >> registration.m_studentId >> registration.m_semester >> registration.m_count;

   for(unsigned i = 0; i < registration.m_count; i++)
     input >> registration.m_results[i];

  return input;
}


ostream & operator <<(ostream& output, const Registration& registration){
  output << "Student ID: " << registration.m_studentId << '\n'
         << "Semester:   " << registration.m_semester << '\n';

  for(unsigned i = 0; i < registration.m_count; i++)
    output << registration.m_results[i] << '\n';

  return output;
}
