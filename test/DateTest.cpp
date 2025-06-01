#include "Date.h"

using std::cout;
using std::endl;

int main(){
  Date date;
  string temp_str;

  date.SetDayOfMonth(11);
  date.SetMonth(5);
  date.SetYear(2025);
  cout << "Day of month matches 11: ";

  if(date.GetDayOfMonth() == 11)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  cout << "Month matches 5: ";

  if(date.GetMonth() == 5)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  cout << "Year matches 2025: ";

  if(date.GetYear() == 2025)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  return 0;
}
