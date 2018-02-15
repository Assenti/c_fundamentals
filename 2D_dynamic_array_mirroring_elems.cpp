#include<iostream>
#include<time.h>
using namespace std;

int max_length_of_subarray = 0;

void fill_jagged_array(int **&arr, int *&temp_arr, int &size) {
	for (int i = 0; i < size; i++) {
		int sub_length = rand() % 5+1;
		arr[i] = new int[sub_length];
		temp_arr[i] = sub_length;
		for (int j = 0; j < sub_length; j++) {
			arr[i][j] = rand() % 9+1;
			
			if (j > max_length_of_subarray) {
				max_length_of_subarray = j;
			}
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
}

void jagged_array_to_full_array_with_zeros(int **&array_with_zeros, int &size) {
	for (int i = 0; i < size; i++) {
		array_with_zeros[i] = new int[max_length_of_subarray * 2];
		for (int j = 0; j < max_length_of_subarray * 2; j++) {
			array_with_zeros[i][j] = 0;
		}
	}
}

void copy_array(int **&source_array, int **&insert_array, int *temp_arr, int &size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < temp_arr[i]; j++) {
			insert_array[i][j] = source_array[i][j];
		}
	}
}

void show_second_array(int **&second_array, int &size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < max_length_of_subarray * 2; j++) {
			cout << second_array[i][j] << "\t";
		}
		cout << endl;
	}
}


void mirror_array(int **&second_array, int &size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (max_length_of_subarray * 2) / 2; j++) {
			int opposite_index = (max_length_of_subarray * 2) - j - 1;
			int base_value = second_array[i][j];
			int opposite_value;
			if (base_value != 0) {
				opposite_value = 10 - base_value;
			}
			else {
				opposite_value = 10;
			}
			second_array[i][opposite_index] = opposite_value;
		}
	}
}

/**************************Main***************************/
void main() {
	srand(time(0));
	//set the number of rows
	int size; 
	cin >> size;
	cout << "============================================================"<< endl;
	
	int ** jagged_array = new int *[size];
	int * temple_helper_array = new int[size];
	int ** second_arr = new int *[size];

	//Calling fill jagged array function
	fill_jagged_array(jagged_array, temple_helper_array, size);
	cout << "============================================================" << endl;
	
	//Calling jagged_array_to_full_array_with_zeros function
	jagged_array_to_full_array_with_zeros(second_arr,size);
		
	//Calling copy elements from jagged array to second array function
	copy_array(jagged_array, second_arr, temple_helper_array, size);

	//Calling mirroring the elements of an array function
	mirror_array(second_arr, size);

	//Calling show second array's elements function
	show_second_array(second_arr, size);
	cout << "============================================================" << endl;
	
	delete[] jagged_array;
	delete[] temple_helper_array;
	delete[] second_arr;
	system("pause");
}