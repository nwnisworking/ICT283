#include "Date.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();
void Test2();
void Test3();
void Test4();

int main(){
  cout << "Date Test Program" << endl << endl;

  Test1();
  cout << endl;
  Test2();
  cout << endl;
  Test3();
  cout << endl;
  Test4();
  cout << endl;
  cout << "All tests completed." << endl;

  cout << endl;
  return 0;
}

void Test1() {
  Date date;

  cout << "Default Constructor Test" << endl;
  cout << "Day: " << date.GetDayOfMonth() << ", Month: " << date.GetMonth() << ", Year: " << date.GetYear() << endl;
}

void Test2(){
  Date date(15, 8, 2023);
  cout << "Parameterized Constructor Test" << endl;
  cout << "Day: " << date.GetDayOfMonth() << ", Month: " << date.GetMonth() << ", Year: " << date.GetYear() << endl;
}

void Test3() {
  Date date;
  date.SetDayOfMonth(25);
  date.SetMonth(12);
  date.SetYear(2023);

  cout << "Setters Test" << endl;
  cout << "Day: " << date.GetDayOfMonth() << ", Month: " << date.GetMonth() << ", Year: " << date.GetYear() << endl;
}

void Test4(){
  Date date(35, 13, 2023);

  cout << "Invalid Date Test" << endl;
  cout << "Day: " << date.GetDayOfMonth() << ", Month: " << date.GetMonth() << ", Year: " << date.GetYear() << endl;
}
