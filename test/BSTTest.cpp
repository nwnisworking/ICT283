#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();

int main(){
  cout << "BST Test Program" << endl << endl;

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

  cout << "All tests completed." << endl;
  cout << endl;

  return 0;
}

void Test1(){
  BST<int> bst;

  bst.Insert(5);
  bst.Insert(3);
  bst.Insert(7);

  cout << "Insert Test" << endl;
  cout << "Is number 5 in BST? " << (bst.Search(5) ? "Yes" : "No") << endl;
  cout << "Is number 3 in BST? " << (bst.Search(3) ? "Yes" : "No") << endl;
  cout << "Is number 7 in BST? " << (bst.Search(7) ? "Yes" : "No") << endl;
  cout << "Is number 10 in BST? " << (bst.Search(10) ? "Yes" : "No") << endl;
}

void Test2(){
  BST<int> bst;

  bst.Insert(34);
  bst.Insert(23);
  bst.Insert(45);
  bst.Insert(12);
  bst.Insert(67);

  cout << "PreOrder Test" << endl;
  bst.PreOrder([](const int& data){
    cout << data << " ";
    return true;
  });

  cout << endl;
}

void Test3(){
  BST<int> bst;

  bst.Insert(34);
  bst.Insert(23);
  bst.Insert(45);
  bst.Insert(12);
  bst.Insert(67);

  cout << "InOrder Test" << endl;
  bst.InOrder([](const int& data){
    cout << data << " ";
    return true;
  });

  cout << endl;
}

void Test4(){
  BST<int> bst;

  bst.Insert(34);
  bst.Insert(23);
  bst.Insert(45);
  bst.Insert(12);
  bst.Insert(67);

  cout << "PostOrder Test" << endl;
  bst.PostOrder([](const int& data){
    cout << data << " ";
    return true;
  });

  cout << endl;
}

void Test5(){
  BST<int> bst;

  bst.Insert(34);
  bst.Insert(23);

  cout << "Delete Node Test" << endl;
  bst.DeleteNode(23);
  cout << "Is number 23 in BST? " << (bst.Search(23) ? "Yes" : "No") << endl;
  cout << "Is number 34 in BST? " << (bst.Search(34) ? "Yes" : "No") << endl;
}

void Test6(){
  BST<int> bst;

  bst.Insert(34);
  bst.Insert(23);
  bst.Insert(45);

  cout << "Destroy Tree Test" << endl;
  cout << "Is BST empty? " << (bst.IsEmpty() ? "Yes" : "No") << endl;
  bst.InOrder([](const int& data){
    cout << data << " ";
    return true;
  });

  bst.DestroyTree();
  cout << "Is BST empty after destroy? " << (bst.IsEmpty() ? "Yes" : "No") << endl;
}

void Test7(){
  BST<int> bst;

  bst.Insert(10);
  bst.Insert(20);
  bst.Insert(5);

  BST<int> bst_copy(bst);

  cout << "Copy Constructor Test" << endl;
  bst_copy.InOrder([](const int& data){
    cout << data << " ";
    return true;
  });
  cout << endl;
}

void Test8(){
  BST<int> bst;

  bst.Insert(10);
  bst.Insert(20);
  bst.Insert(5);

  BST<int> bst_assignment_op;
  bst_assignment_op = bst;

  cout << "Assignment Operator Test" << endl;
  bst_assignment_op.InOrder([](const int& data){
    cout << data << " ";
    return true;
  });
  cout << endl;
}