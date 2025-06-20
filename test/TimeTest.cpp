#include "MTime.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();
void Test2();
void Test3();
void Test4();

int main(){
  cout << "Time Test Program" << endl << endl;

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
  MTime time;

  cout << "Default Constructor Test" << endl;
  cout << "Hour: " << time.GetHours() << ", Minute: " << time.GetMinutes() << endl;
}

void Test2(){
  MTime time(10, 30);
  cout << "Parameterized Constructor Test" << endl;
  cout << "Hour: " << time.GetHours() << ", Minute: " << time.GetMinutes() << endl;
}

void Test3() {
  MTime time;
  time.SetHours(12);
  time.SetMinutes(30);

  cout << "Setters Test" << endl;
  cout << "Hour: " << time.GetHours() << ", Minute: " << time.GetMinutes() << endl;
}

void Test4(){
  MTime time(24, 61); // Invalid time
  cout << "Invalid Time Test" << endl;
  cout << "Hour: " << time.GetHours() << ", Minute: " << time.GetMinutes() << endl;
}
