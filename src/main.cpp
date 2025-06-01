#include <iostream>
#include <fstream>

#include "Registration.h"

using namespace std;

int main(){
	ifstream infile("data/rinput.txt");

	if(!infile) return -1;
	Registration registration;

	infile >> registration;

	ofstream ofile("data/routput.txt");

	ofile << registration
	<< "Number of units   = " << registration.GetCount() << '\n'
	<< "Total credits     = " << registration.GetCredits() << '\n';

	// For Lab 3, you should comment out this line and the next 3 lines

  // Course aCourse( "MTH_3020", 'B', 2 );
  // aCourse.SetCredits( 5 );
  // cout << aCourse << endl; // the operator << for Course is called

	return 0;
}
