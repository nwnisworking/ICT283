#include "Model.h"
#include "View.h"
#include "Controller.h"

#include <iostream>

using std::cout;
using std::endl;
using std::runtime_error;

// Forward declarations of test functions
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();

int main(){

  int app_test = 0;

  while(app_test != 6){
    cout << "Application Test Program" << endl << endl;
    cout << "1. Missing Data source" << endl;
    cout << "2. Missing CSV source" << endl;
    cout << "3. Invalid values (including N/A) in CSV source" << endl;
    cout << "4. Different column naming in CSV source" << endl;
    cout << "5. Incorrect column naming in CSV source" << endl;
    cout << "6. Exit" << endl << endl;

    cout << "Please select a test to run (1-5): ";
    cin >> app_test;
    cout << endl;

    switch(app_test){
      case 1:
        cout << "Running Test 1: Missing Data source" << endl;
        Test1();
        break;
      case 2:
        cout << "Running Test 2: Missing CSV source" << endl;
        Test2();
        break;
      case 3:
        cout << "Running Test 3: Invalid values in CSV source" << endl;
        Test3();
        break;
      case 4:
        cout << "Running Test 4: Different column naming in CSV source" << endl;
        Test4();
        break;
      case 5 :
        cout << "Running Test 5: Incorrect column naming in CSV source" << endl;
        Test5();
        break;
      case 6 :
        break;
      default:
        cout << "Invalid choice. Please select a valid test." << endl;
        app_test = 0;
    }

    cout << endl;
  }

  return 0;
}

void Test1() {
  try{
    cout << "Missing Data source" << endl;
    Model model("data/data_source_nonexistent.txt");
    View view;
    Controller controller(view, model);

    controller.Init();
  }
  catch(const runtime_error& e){
    cout << "Error during application initialization: " << e.what() << endl;
    return;
  }
}

void Test2(){
  try{
    cout << "Missing CSV source" << endl;
    Model model("data/data_source_1.txt");
    View view;
    Controller controller(view, model);

    controller.Init();
  }
  catch(const runtime_error& e){
    cout << "Error during application initialization: " << e.what() << endl;
    return;
  }
}

void Test3(){
  // Following column contains invalid values:
  // WAST,DP,Dta,Dts,EV,QFE,QFF,QNH,RF,RH,S,SR,ST1,ST2,ST3,ST4,Sx,T

  // 31/03/2016 9:00,14.6,175,17,0,1013.4,1016.9,1017,0,68.2,-5,1512,22.7,24.1,25.5,26.1,8,140.41
  // 31/03/2016 9:10,14.6,194,22,0.1,1013.4,1016.9,1017,0,67.2,N/A,offline,22.7,24.1,25.5,26.1,8,NaN
  // 31/03/2016 9:20,14.8,198,30,0.1,1013.4,1016.9,1017,0,68.2,,,22.7,24,25.5,26.1,8,20.92

  try{
    cout << "Invalid values in CSV source" << endl;
    Model model("data/data_source_2.txt");
    Vector<WeatherRecord*> data;

    model.FindDate(data, 3, 2016); // March 2016

    for(int i = 0; i < 3; i++){
      WeatherRecord* record = data[i];
      cout << "Record " << i + 1 << ": "
           << "Date: " << record->GetDayOfMonth() << "/"
           << record->GetMonth() << "/" << record->GetYear()
           << ", Temperature: " << record->GetTemperature()
           << ", Wind Speed: " << record->GetSpeed()
           << ", Solar Radiation: " << record->GetRadiation()
           << endl;
    }

    View view;
    Controller controller(view, model);

    controller.Init();
  }
  catch(const runtime_error& e){
    cout << "Error during application initialization: " << e.what() << endl;
    return;
  }
}

void Test4(){
  try{
    cout << "Different column naming in CSV source" << endl;

    Model model("data/data_source_3.txt");
    View view;
    Controller controller(view, model);
    controller.Init();
  }
  catch(const runtime_error& e){
    cout << "Error during application initialization: " << e.what() << endl;
    return;
  }
}

void Test5(){
  try{
    cout << "Incorrect column naming in CSV source" << endl;

    Model model("data/data_source_4.txt");
    View view;
    Controller controller(view, model);
    controller.Init();
  }
  catch(const runtime_error& e){
    cout << "Error during application initialization: " << e.what() << endl;
  }
}
