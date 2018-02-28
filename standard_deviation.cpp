#include <iostream>
#include <time.h>
#include <cmath>
using namespace std;

void fill_array(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 9+1;
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "=========================" << endl;
}

double arrays_elems_mean(int *arr, int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += arr[i];
	}
	return (double)sum/size;
}

double standard_deviation(int *arr, int size, double *mean) {
	double sum = 0;
	int const size_temp = 10;
	double temp_arr[size_temp];
	for (int i = 0; i < size; i++) {
		temp_arr[i] = pow((arr[i] - *mean),2);
		sum += temp_arr[i];
	}
	
	return sqrt(sum / (size - 1));
}

void main() {
	srand(time(0));
	int const size = 10;
	int arr[size];
	fill_array(arr, size);
	double mean = arrays_elems_mean(arr,size);
	cout << "Mean is " << mean << endl;
	cout << "Standard deviaton is: " << standard_deviation(arr, size, &mean) << endl;

	system("pause");
}
