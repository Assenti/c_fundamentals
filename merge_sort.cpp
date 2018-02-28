#include <iostream>
#include <time.h>
using namespace std;

void fill_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 20;
	}
}
void print_arr(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}
void merge(int *arr, int left, int right) {
	int i = left,
		mid = left + (right - left) / 2,
		j = mid + 1,
		k = 0;
	int* temp_arr = new int[right];

	while (i <= mid && j <= right) {
		if (arr[i] <= arr[j]) {
			temp_arr[k] = arr[i];
			i++;
		}
		else {
			temp_arr[k] = arr[j];
			j++;
		}
		k++;
	}

	while (i <= mid) {
		temp_arr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= right) {
		temp_arr[k] = arr[j];
		j++;
		k++;
	}
	
	for (i = 0; i < k; i++) {
		arr[left + i] = temp_arr[i];
	}
	//delete[] temp_arr;
}
void merge_sort(int *arr, int left, int right) {
	int temp = 0;
	int mid = left + (right - left) / 2;
	if (left < right) {
		if (right - left == 1) {
			if (arr[left] > arr[right]) {
				temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
		}
		else {
			merge_sort(arr, left, mid);
			merge_sort(arr, mid + 1, right);
			merge(arr, left, right);
		}
	}
}

void main() {
	srand(time(0));
	int const size = 20;
	int arr[size];
	/*********Random filling and printing array************/
	fill_arr(arr, size);
	print_arr(arr, size);
	/*************Calling merge_sort function**************/
	merge_sort(arr, 0, size-1);
	print_arr(arr, size);
	

	system("pause");
}