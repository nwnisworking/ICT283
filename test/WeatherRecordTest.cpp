#include "WeatherRecord.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();
void Test2();

int main() {
  cout << "Weather Record Test Program" << endl << endl;
  Test1();
  cout << endl;
  Test2();
  cout << endl;
  cout << "All tests completed." << endl;
  cout << endl;

  return 0;
}

void Test1() {
  WeatherRecord record;

  cout << "Default Constructor Test" << endl;
  cout << "Date: " << record.GetDayOfMonth() << "/"
       << record.GetMonth() << "/" << record.GetYear()
       << ", Temperature: " << record.GetTemperature()
       << ", Humidity: " << record.GetRadiation()
       << ", Wind Speed: " << record.GetSpeed()
       << ", Time: " << record.GetHours() << ":"
       << record.GetMinutes() << endl;
}

void Test2() {
  WeatherRecord record;
  record.SetSpeed(10);
  record.SetRadiation(200);
  record.SetTemperature(25.5f);
  record.SetDayOfMonth(15);
  record.SetMonth(8);
  record.SetYear(2023);
  record.SetHours(14);
  record.SetMinutes(30);

  cout << "Setters Test" << endl;
  cout << "Date: " << record.GetDayOfMonth() << "/"
       << record.GetMonth() << "/" << record.GetYear()
       << ", Temperature: " << record.GetTemperature()
       << ", Humidity: " << record.GetRadiation()
       << ", Wind Speed: " << record.GetSpeed()
       << ", Time: " << record.GetHours() << ":"
       << record.GetMinutes() << endl;
}
