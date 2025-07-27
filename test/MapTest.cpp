#include "Map.h"
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

void Test1();
void Test2();
void Test3();
void Test4();

int main(){
  cout << "Map Test Program" << endl << endl;

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

void Test1(){
  Map<int, string> map;

  map.Insert(1, "One");
  map.Insert(2, "Two");
  map.Insert(3, "Three");

  cout << "Insert Test" << endl;
  cout << "Map 1: " << *map.Get(1) << endl;
  cout << "Map 2: " << *map.Get(2) << endl;
  cout << "Map 3: " << *map.Get(3) << endl;
}

void Test2(){
  Map<int, string> map;

  map.Insert(1, "One");
  map.Insert(2, "Two");
  map.Insert(3, "Three");

  cout << "Search Test" << endl;
  cout << "Search for key 1: " << (map.Search(1) ? "Found" : "Not Found") << endl;
  cout << "Search for key 4: " << (map.Search(4) ? "Found" : "Not Found") << endl;
}

void Test3(){
  Map<int, string> map;
  Map<int, string> map_1;

  map.Insert(1, "One");
  map.Insert(2, "Two");
  map.Insert(3, "Three");

  map_1 = map;

  cout << "Assignment Operator Test" << endl;
  cout << "Map 1:" <<  *map_1.Get(1) << endl;
  cout << "Map 2:" <<  *map_1.Get(2) << endl;
  cout << "Map 3:" <<  *map_1.Get(3) << endl;
}

void Test4(){
  Map<int, string> map;

  map.Insert(1, "One");
  map.Insert(2, "Two");
  map.Insert(3, "Three");

  cout << "Remove Test" << endl;
  cout << "Before removal: " << *map.Get(2) << endl;
  
  map.Remove(2);
  
  cout << "After removal: " << (map.Get(2) ? *map.Get(2) : "Not Found") << endl;
}