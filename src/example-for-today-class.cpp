#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
  set<int> n1{7,6,3,2,1,6,7,3};
  set<int> n2{3,4,5,8,3,4,5,6};

//  for(int num : n1){
//    cout << num << endl;
//  }


  set<int> result;

  set_intersection(n1.begin(), n1.end(), n2.begin(), n2.end(), inserter(result, result.begin()));

  for(int num : result){
    cout << num << endl;
  }

  return 0;
}
