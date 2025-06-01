#include "Registration.h"

using std::cout;
using std::endl;

int main(){
  Registration registration;
  string temp_str;

  registration.SetCount(2);
  registration.SetStudentId(253);
  registration.SetSemester(5);
  registration.SetResult(
    Result(
      80, 
      Unit(
        "Foundation of Programming", 
        "ICT159", 
        3
      ), 
      Date(2, 10, 2014)
    ), 
    0
  );

  registration.SetResult(
    Result(
      93, 
      Unit(
        "Software Architecture", 
        "ICT373", 
        3
      ), 
      Date(2, 10, 2018)
    ), 
    1
  );

  cout << "Result count is 2: ";
  if(registration.GetCount() == 2)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  cout << "Student Id is 2: ";
  if(registration.GetStudentId() == 253)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  cout << "Semester is 5: ";
  if(registration.GetSemester() == 5)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  return 0;
}
