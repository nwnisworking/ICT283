#include "Result.h"

using std::cout;
using std::endl;

int main(){
  Result result;
  Unit unit;
  Date date;
  string temp_str;

  result.SetMarks(23.45);
  result.SetUnit(Unit("System Analysis and Design", "ICT284", 3));
  result.SetDate(Date(25, 5, 2019));

  cout << "Result marks matches 23.45: ";
  
  if(result.GetMarks() == (float) 23.45)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  string u_name, u_id;
  cout << "Unit matches 'System Analysis and Design', 'ICT284', 3: ";
  result.GetUnit(unit);
  unit.GetName(u_name);
  unit.GetId(u_id);
  
  if(
    u_name == "System Analysis and Design" && 
    u_id == "ICT284" && 
    unit.GetCredits() == 3
  )
    cout << "passed" << endl;
  else
    cout << "failed" << endl;


  cout << "Date matches 25/5/2019: ";
  result.GetDate(date);

  if(
    date.GetDayOfMonth() == 25 && 
    date.GetMonth() == 5 && 
    date.GetYear() == 2019
  )
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  return 0;
}
