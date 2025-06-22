#include "StandardDeviation.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();
void Test2();

int main() {
  cout << "Standard Deviation Test Program" << endl << endl;

  Test1();
  cout << endl;
  Test2();
  cout << endl;

  cout << "All tests completed." << endl;

  return 0;
}

void Test1() {
  Vector<float> vec;
  StandardDeviation<float> sd(vec);
  
  vec.Insert(5.0f);
  vec.Insert(10.0f);
  vec.Insert(15.0f);
  vec.Insert(20.0f);
  vec.Insert(25.0f);

  cout << "Calculation Test" << endl;
  cout << "Mean: " << sd.Mean() << ", Sample: " << sd.Sample() << endl;
}

void Test2(){
  Vector<float> vec;
  StandardDeviation<float> sd(vec);

  cout << "Empty Vector Test" << endl;
  cout << "Mean: " << sd.Mean() << ", Sample: " << sd.Sample() << endl;
}