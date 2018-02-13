#include<iostream>
#include<time.h>
using namespace std;


int main() {
	srand(time(0));
	rand();
	int h;
	cin >> h;
	int max_length = 0;
	int ** array2d = new int *[h];
	int ** second_arr = new int *[h];
	int * temple_helper_array = new int[h];
	for (int i = 0; i < h; i++) {
		int sub_length = rand() % 3 + 1;
		array2d[i] = new int[sub_length];
		temple_helper_array[i] = sub_length;
		if (sub_length > max_length) {
			max_length = sub_length;
		}
		int subarray_sum = 0;
		for (int j = 0; j < sub_length; j++) {
			array2d[i][j] = rand() % 10;
			subarray_sum += array2d[i][j];
			cout << array2d[i][j] << " ";
		}
		cout << endl;
	}
	int second_arr_length = max_length * 2;
	for (int i = 0; i < h; i++) {
		second_arr[i] = new int[second_arr_length];
		for (int j = 0; j < second_arr_length; j++) {
			second_arr[i][j] = 0;
			cout << second_arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < temple_helper_array[i]; j++) {
			second_arr[i][j] = array2d[i][j];
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < second_arr_length; j++) {
			cout << second_arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < second_arr_length / 2; j++) {
			int opposite_index = second_arr_length - j - 1;
			int base_value = second_arr[i][j];
			int opposite_value;
			if (base_value != 0) {
				opposite_value = 10 - base_value;
			}
			else {
				opposite_value = 0;
			}
			second_arr[i][opposite_index] = opposite_value;
		}
	}
	cout << endl;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < second_arr_length; j++) {
			cout << second_arr[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}