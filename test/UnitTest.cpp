#include "Unit.h"

using std::cout;
using std::endl;

int main(){
  Unit unit;
  string temp_str;

  unit.SetName("Foundation of Programming");
  unit.SetId("ICT159");
  unit.SetCredits(3);

  cout << "Unit name matches 'Foundation of Programming': ";
  unit.GetName(temp_str);
  
  if(temp_str == "Foundation of Programming")
    cout << "passed" << endl;
  else
    cout << "failed" << endl;
  
  cout << "Unit id matches 'ICT159': ";
  unit.GetId(temp_str);

  if(temp_str == "ICT159")
    cout << "passed" << endl;
  else
    cout << "failed" << endl;


  cout << "Unit id credits is 3: ";

  if(unit.GetCredits() == 3)
    cout << "passed" << endl;
  else
    cout << "failed" << endl;

  cout << "Unit Test complete";

  return 0;
}
