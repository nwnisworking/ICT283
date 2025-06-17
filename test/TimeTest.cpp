#include "Time.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

int main(){
  Time time(23,59);

  cout << "---- time -----" << endl;
  cout << "hours: " << time.getHours() << endl;
  cout << "minutes: " << time.getMinutes() << endl;
  cout << endl;


  time.setHours(20);
  time.setMinutes(12);

  cout << "---- time after modification -----" << endl;
  cout << "hours: " << time.getHours() << endl;
  cout << "minutes: " << time.getMinutes() << endl;


  return 0;
}
