#include "Date.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
  Date date(24, 2, 2024);

  cout << "---- date -----" << endl;
  cout << "day of month: " << date.GetDayOfMonth() << endl;
  cout << "month: " << date.GetMonth() << endl;
  cout << "year: " << date.GetYear() << endl;
  cout << endl;


  date.SetDayOfMonth(20);
  date.SetMonth(12);
  date.SetYear(2025);

  cout << "---- date after modification -----" << endl;
  cout << "day of month: " << date.GetDayOfMonth() << endl;
  cout << "month: " << date.GetMonth() << endl;
  cout << "year: " << date.GetYear() << endl;

  return 0;
}
