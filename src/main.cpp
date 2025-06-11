#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

double getMean(const double values[], int size);
double getStandardDeviation(const double values[], int size);
bool getValuesFromFile(string path, double** values, int& size);

int main(){
	double* values = nullptr;
	int size = 0;

	if(!getValuesFromFile("data.txt", &values, size))
		return 0;
	
	cout << "The standard deviation is: " << getStandardDeviation(values, size);

	delete[] values;

	return 0;
}

double getMean(const double values[], int size){
	double sum = 0;

	for(int i = 0; i < size; i++) sum+= values[i];

	return sum / size;
}

double getStandardDeviation(const double values[], int size){
	double mean = getMean(values, size);
	double sum = 0;

	for(int i = 0; i < size; i++){
		sum+= pow(values[i] - mean, 2);
	}

	return sqrt((sum / (size - 1)));
}

bool getValuesFromFile(string path, double** values, int& size){
	ifstream input(path);
	string temp;

	// File is non-existent
	if(!input){
		cout << "File cannot be found. Make sure the path is valid." << endl;
		return false;
	}

	getline(input, temp, ',');

	size = stoi(temp);
	*values = new double[size];

	// Unable to allocate memory
	if(*values == nullptr){
		cout << "Unable to allocate memory for some reason." << endl;
		return false;
	}

	for(int i = 0; i < size; i++){
		getline(input, temp, ',');
		(*values)[i] = stod(temp);
	}

	input.close();

	return true;
}
