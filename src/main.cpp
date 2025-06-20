#include <stdexcept>

#include "Controller.h"
#include "Model.h"
#include "View.h"

using std::cout;
using std::endl;
using std::runtime_error;

const string DATA_SOURCE = "data/data_source.txt";

int main(){
  try{
    View view;
    Model model(DATA_SOURCE);
    Controller controller(view, model);

    controller.Init();
  }
  catch(const runtime_error& e){
    cout << "Error during application initialization: " << e.what() << endl;
    return 1;
  }

  return 0;
}
