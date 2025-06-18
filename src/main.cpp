#include "Controller.h"
#include "Model.h"
#include "View.h"

#include <iostream>
//#include <fstream>
#include <string>
#include "StandardDeviation.h"
#include "Vector.h"

using std::string;
using std::ifstream;
using std::cout;
using std::endl;

const string DATA_SOURCE = "data/data_source.txt";

int main(){
 View view;
 Model model(DATA_SOURCE);
 Controller controller(view, model);

 controller.Init();
  return 0;
}
