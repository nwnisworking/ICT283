#include "StandardDeviation.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();

int main() {
  cout << "Standard Deviation Test Program" << endl << endl;

  Test1();
  cout << endl;
  cout << "All tests completed." << endl;

  return 0;
}

void Test1() {
  Vector<float> vec;
  vec.Insert(5.0f);
  vec.Insert(10.0f);
  vec.Insert(15.0f);
  vec.Insert(20.0f);
  vec.Insert(25.0f);

  StandardDeviation<float> sd(vec);

  cout << "Calculation Test" << endl;
  cout << "Mean: " << sd.Mean() << ", Sample: " << sd.Sample() << ", Population: " << sd.Population() << endl;
  cout << "Sample Result: 7.9056941504209, Population Result: 7.0710678118655" << endl;
}