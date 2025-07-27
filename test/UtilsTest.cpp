#include "Utils.h"
#include <iostream>

using std::cout;
using std::endl;

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();

int main(){
  cout << "Utils Test Program" << endl << endl;

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
  Test6();
  cout << endl;
  cout << "All tests completed." << endl;

  cout << endl;
  return 0;
}

void Test1() {
  Vector<int> vec;
  vec.Insert(1);
  vec.Insert(2);
  vec.Insert(3);

  cout << "Mean Test" << endl;
  cout << "Mean: " << Utils::Mean(vec) << endl;
}

void Test2() {
  Vector<float> vec;
  vec.Insert(1.5f);
  vec.Insert(2.5f);
  vec.Insert(3.5f);

  cout << "Sample Standard Deviation Test" << endl;
  cout << "Sample Standard Deviation: " << Utils::Sample(vec) << endl;
}

void Test3() {
  Vector<int> vec1;
  vec1.Insert(1);
  vec1.Insert(2);
  vec1.Insert(3);

  Vector<int> vec2;
  vec2.Insert(4);
  vec2.Insert(5);
  vec2.Insert(6);

  cout << "Pearson Correlation Test" << endl;
  cout << "Pearson Correlation: " << Utils::PearsonCorrelation(vec1, vec2) << endl;
}

void Test4(){
  Vector<float> mean_abs_dev_vec;
  mean_abs_dev_vec.Insert(13.0f);
  mean_abs_dev_vec.Insert(43.0f);
  mean_abs_dev_vec.Insert(42.0f);
  mean_abs_dev_vec.Insert(3.0f);

  cout << "Mean Absolute Deviation Test" << endl;
  cout << "Mean Absolute Deviation: " << Utils::MeanAbsoluteDeviation(mean_abs_dev_vec) << endl;
}

void Test5(){
  Vector<int> total;

  total.Insert(10);
  total.Insert(20);
  total.Insert(30);
  total.Insert(40);

  cout << "Sum Test" << endl;
  cout << "Sum: " << Utils::Sum(total) << endl;
}

void Test6(){
  string str = "   Hello, World!   ";
  string str_1 = "C++ Programming ";
  string str_2 = "  Utils Test";
  string str_3 = "     ";
  
  cout << "Trim Test" << endl;
  Utils::Trim(str);
  Utils::Trim(str_1);
  Utils::Trim(str_2);
  Utils::Trim(str_3);

  cout << "Trimmed String 1: '" << str << "'" << endl;
  cout << "Trimmed String 2: '" << str_1 << "'" << endl;
  cout << "Trimmed String 3: '" << str_2 << "'" << endl;
  cout << "Trimmed String 4: '" << str_3 << "'" << endl;
}