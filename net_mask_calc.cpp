#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int binary_to_decimal(int *n) {
	int temp[8];
	for (int i = 7, j = 0; i >= 7, j < 8; i--, j++) {
		int power_of_two = pow(2, j);
		if (n[i] == 0) {
			temp[j] = 0;
		}
		else {
			temp[j] = power_of_two;
		}
	}

	int result = 0;
	for (int i = 0; i < 8; i++) {
		result += temp[i];
	}
	return result;
}
int* netmask_calc(int *n) {
	
	int binaries_1st_interval[8];
	int binaries_2nd_interval[8];
	int binaries_3rd_interval[8];
	int binaries_4th_interval[8];
	
	for (int i = 0; i < 8; i++) {
		binaries_1st_interval[i] = *(n++);
	}
	for (int i = 0; i < 8; i++) {
		binaries_2nd_interval[i] = *(n++);
	}
	for (int i = 0; i < 8; i++) {
		binaries_3rd_interval[i] = *(n++);
	}
	for (int i = 0; i < 8; i++) {
		binaries_4th_interval[i] = *(n++);
	}

	int numbers[4];
	numbers[0] = binary_to_decimal(binaries_1st_interval);
	numbers[1] = binary_to_decimal(binaries_2nd_interval);
	numbers[2] = binary_to_decimal(binaries_3rd_interval);
	numbers[3] = binary_to_decimal(binaries_4th_interval);
	return numbers;
}
int* decimal_to_netmasks_units(int n) {
	int binary[32];

	for (int i = 0; i < 32; i++) {
		if (i > n-1) {
			binary[i] = 0;
		}
		else {
			binary[i] = 1;
		}
	}
	return binary;
}
void netmask_binary(int *arr) {
	string binary_netmask[35];
	for (int i = 0; i < 35; i++) {
		if (i == 8 || i == 16 || i == 24) {
			binary_netmask[i] = '.';
		}
		else if (arr[i] == 0) {
			binary_netmask[i] = '0';
		}
		else if (arr[i] == 1) {
			binary_netmask[i] = '1';
		}
	}
	for (int i = 0; i < 35; i++) {
		cout << binary_netmask[i];
	}
	cout << endl;
}

/****************************Main***********************************/
void main() {
	
	int number;
	cout << "Enter the number to calculate netmask: ";
	cin >> number;
	int helper_array[32];

	for (int i = 0; i < 32; i++) {
		helper_array[i] = decimal_to_netmasks_units(number)[i];
	}

	cout << "Netmask in binary: ";
	netmask_binary(helper_array);
	

	cout << "Netmask: ";
	for (int i = 0; i < 4; i++) {
		cout << netmask_calc(helper_array)[i] << ".";
	}
	cout << endl;

	system("pause");
}