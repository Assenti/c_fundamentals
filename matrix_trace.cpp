#include <iostream>
#include <time.h>
using namespace std;


void fill_2d_array(int **arr, int const rows, int const cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			arr[i][j] = rand() % 10; //for convenience of counting
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}


int matrix_trace(int **&arr, int const rows, int const cols) {
	int sum = 0;
	if (rows > cols) {
		for (int i = 0; i < cols; i++) {
			sum += arr[i][i];
		}
	}
	else {
		for (int i = 0; i < rows; i++) {
			sum += arr[i][i];
		}
	}
	
	return sum;
}

void main() {
	srand(time(0));
	int rows, cols;
	cout << "Enter the matrixs sizes:\nSize of rows: ";
	cin >> rows;
	cout << "Size of cols: ";
	cin >> cols;
	cout << "==============================" << endl;
	int **arr = new int*[rows]; 
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols]; 
	}
	
	fill_2d_array(arr,rows,cols);
	
	cout << "Sum of main diagonal (trace of a matrix): " << matrix_trace(arr, rows, cols) << endl;
	cout << "==============================" << endl;
	for (int i = 0; i < rows; i++) {
		delete[] arr[i];        
	}
	delete[] arr;
	system("pause");
}