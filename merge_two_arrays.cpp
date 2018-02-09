#include <iostream>
#include <time.h>
using namespace std;

void fill_arr(int *arr, int size) {
	for (int i = 0; i < size; i++)
		*(arr++) = rand() % 15;
}

void merge_arrays(int *arr1, int *arr2, int *merge_arr, int aSize, int bSize) {
	for (int i = 0; i < aSize; i++) {
		*(merge_arr++) = *(arr1++);
	}
	for (int i = 0; i < bSize; i++) {
		*(merge_arr++) = *(arr2++);
	}
		
}

void main() {
	srand(time(0));
	int arr1[20];
	int arr2[20];
	int merge_arr[40];
	int aSize, bSize, counter = 0;
	cin >> aSize >> bSize;

	fill_arr(arr1, aSize);
	fill_arr(arr2, bSize);
	
	for (int i = 0; i < aSize; i++) {
		cout << arr1[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < bSize; i++) {
		cout << arr2[i] << " ";
	}
	cout << endl;
	merge_arrays(arr1, arr2, merge_arr, aSize, bSize);

	for (int i = 0; i < (aSize + bSize); i++) {
		cout << merge_arr[i] << " ";
	}

	cout << endl;
	system("pause");
}
