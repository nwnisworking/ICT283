#include "Vector.h"

#include <iostream>

using std::cout;
using std::endl;

// Forward declarations of test functions
void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void Test9();
void Test10();
void Test11();

int main(){
  cout << "Vector Test Program" << endl << endl;

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
  Test7();
  cout << endl;
  Test8();
  cout << endl;
  Test9();
  cout << endl;
  Test10();
  cout << endl;
  Test11();
  cout << endl;
  cout << "All tests completed." << endl;

  cout << endl;
  return 0;
}

void Test1() {
  Vector<int> vec;

  cout << "Default Constructor Test" << endl;
  cout << "Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
}

void Test2(){
  Vector<int> vec(-10);

  cout << "Parameterized Constructor Test with negative size" << endl;
  cout << "Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
}

void Test3() {
  Vector<int> vec(5);
  
  cout << "Parameterized Constructor Test with size 5" << endl;
  cout << "Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;

  for (int i = 0; i < 5; ++i) {
    vec.Insert(i);
  }
  
  cout << "After inserting elements: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
}

void Test4() {
  Vector<int> vec(2);
  
  cout << "Insert elements into vector" << endl;
  vec.Insert(1);
  vec.Insert(2);
  vec.Insert(3);
  
  cout << "After inserting elements: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }
}

void Test5() {
  Vector<int> vec(5);
  
  cout << "Insert elements at specific indices" << endl;
  vec.Insert(10, 0);
  vec.Insert(20, 1);
  vec.Insert(30, 2);
  
  cout << "After inserting elements: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }
}

void Test6() {
  Vector<int> vec(5);
  
  cout << "Insert elements at specific indices twice" << endl;
  vec.Insert(1, 0);
  vec.Insert(2, 1);
  vec.Insert(3, 2);
  vec.Insert(4, 3);
  vec.Insert(5, 4);
  vec.Insert(6, 2);
  
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }
}

void Test7(){
  Vector<int> vec(5);

  cout << "Insert elements at specific indices with invalid index" << endl;

  if(!vec.Insert(10, -1)){
    cout << "Failed to insert at index -1" << endl;
  }

  if(!vec.Insert(20, 6)){
    cout << "Failed to insert at index 6" << endl;
  }
}

void Test8() {
  Vector<int> vec(5);
  
  cout << "Delete elements from vector" << endl;
  vec.Insert(1);
  vec.Insert(2);
  vec.Insert(3);
  
  cout << "Before deletion: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }
  vec.Delete(1);
  
  cout << "After deleting element at index 1: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }
}

void Test9() {
  Vector<int> vec(5);
  
  cout << "Delete elements at invalid indices" << endl;
  vec.Insert(1);
  vec.Insert(2);
  
  cout << "Before deletion: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  
  if (!vec.Delete(-1)) {
    cout << "Failed to delete at index -1" << endl;
  }
  
  if (!vec.Delete(5)) {
    cout << "Failed to delete at index 5" << endl;
  }
  
  cout << "After attempting invalid deletions: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
}

void Test10() {
  Vector<int> vec(5);
  
  cout << "Access elements using subscript operator" << endl;
  try{
    vec[3] = 10;
  }
  catch(std::out_of_range& e){
    cout << "Caught exception: " << e.what() << endl;
  }
}

void Test11(){
  cout << "Modify elements using subscript operator" << endl;

  Vector<int> vec(5);
  vec.Insert(1);
  vec.Insert(2);
  vec.Insert(3);
  
  cout << "Before modification: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }

  try{
    vec[1] = 10;
  }
  catch(std::out_of_range& e){
    cout << "Caught exception: " << e.what() << endl;
  }

  cout << "After modification: Size: " << vec.GetSize() << ", Capacity: " << vec.GetCapacity() << endl;
  for (int i = 0; i < vec.GetSize(); ++i) {
    cout << "Element at index " << i << ": " << vec[i] << endl;
  }
}