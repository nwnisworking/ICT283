#include "Date.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

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
  Test5();
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

void Test5(){
  Date date1(15, 8, 2023);
  Date date2(16, 8, 2023);

  cout << "Comparison Operators Test" << endl;
  cout << date1.GetDayOfMonth() << '/' << date1.GetMonth() << '/' << date1.GetYear() << endl;
  cout << date2.GetDayOfMonth() << '/' << date2.GetMonth() << '/' << date2.GetYear() << endl;
  cout << "Date1 < Date2: " << (date1 < date2) << endl;
  cout << "Date1 > Date2: " << (date1 > date2) << endl;
  cout << "Date1 == Date2: " << (date1 == date2) << endl;
  cout << "Date1 <= Date2: " << (date1 <= date2) << endl;
  cout << "Date1 >= Date2: " << (date1 >= date2) << endl;
}
