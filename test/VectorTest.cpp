#include "Vector.h"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::string;
using std::out_of_range;

void display(const Vector<int> &data);

int main(){
  Vector<int> numbers(-5);

  cout << "---- vector unit test ---- " << endl;
  cout << "Negative size instantiation: " << numbers.GetSize() << endl;

  numbers.Insert(5, 1);
  cout << "Size after insert at index 1 " << numbers.GetSize() << endl;

  numbers.Insert(10, 0);
  cout << "Size after insert at index 0 " << numbers.GetSize() << endl;

  numbers.Insert(50, 0);
  cout << "Insert at index 0 after a valid insert: " << numbers[0] << endl;

  display(numbers);

  numbers.Insert(12);
  numbers.Insert(4);
  numbers.Insert(59);
  numbers.Delete(1);

  cout << "Delete index 1: " << numbers[1] << endl;

  display(numbers);
  numbers.Erase();
  cout << "Erase data and catching out-of-range error: " << numbers.GetSize() << endl;

  try{
    cout << numbers[1] << endl;
  }
  catch(const out_of_range& e){
    cout << "[Error]: " << e.what() << endl;
  }

	return 0;
}

void display(const Vector<int> &data){
  for(int i = 0; i < data.GetSize(); i++){
    cout << i << ": " << data[i] << endl;
  }
}
