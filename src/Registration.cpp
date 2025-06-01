#include "Registration.h"

Registration::Registration(){
  m_count = 0;
  m_semester = 0;
  m_studentId = 0;
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

void Registration::SetCount(unsigned count){
  m_count = count;
}

unsigned Registration::GetCount() const{
  return m_count;
}

void Registration::SetStudentId(long id){
  m_studentId = id;
}

long Registration::GetStudentId() const{
  return m_studentId;
}

void Registration::SetSemester(unsigned semester){
  m_semester = semester;  
}

unsigned Registration::GetSemester() const{
  return m_semester;
}

void Registration::SetResult(const Result& result, unsigned index){
  m_results[index] = result;
}

void Registration::GetResult(Result& result, unsigned index) const{
  result = m_results[index];
}

istream & operator >>(istream & input, Registration & registration){
  string temp_str;
  
  getline(input, temp_str, ',');
  registration.SetStudentId(stol(temp_str));
  
  getline(input, temp_str, ',');
  registration.SetSemester(stoi(temp_str));

  getline(input, temp_str);
  registration.SetCount(stoi(temp_str));

  Result temp_result;
  for(unsigned i = 0; i < registration.GetCount(); i++){
    input >> temp_result;
    registration.SetResult(temp_result, i);
  }

  return input;
}

ostream & operator <<(ostream& output, const Registration& registration){
  output << "Student ID: " << registration.GetStudentId() << '\n'
         << "Semester:   " << registration.GetSemester() << '\n';

  Result temp_result;
  for(unsigned i = 0; i < registration.GetCount(); i++){
    registration.GetResult(temp_result, i);
    output << temp_result << '\n';
  }

  return output;
}
