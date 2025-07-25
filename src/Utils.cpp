#include "Utils.h"

void Utils::Trim(string& str){
  int size = str.size();
  int start = 0;
  int end = size - 1;

  while(start< size && str[start] == ' '){
    start++;
  }

  while(end > start && str[end] == ' '){
    end--;
  }

  if(start > end){
    str = "";
  }
  else{
    str = str.substr(start, end - start + 1);
  }
}

void Utils::Continue(){
  cout << endl << "Press Enter to continue...";
  ClearBuffer();
  cout << endl;
}

void Utils::ClearBuffer(){
  if(cin.fail()){
    cin.clear();
  }
  // Clear leftover characters in the input buffer
  while(cin.get() != '\n');
}