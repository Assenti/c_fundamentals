#include<iostream>
#include<string>
using namespace std;

int binary_to_decimal(int* binary, int size) {
	int* temp = new int[size];
	
	for (int i = size-1, j = 0; i >= size, j < size; i--, j++) {
		int power_of_two = pow(2, j);
		if (binary[i] == 0) {
			temp[j] = 0;
		}
		else {
			temp[j] = power_of_two;
		}
	}

	int result = 0;
	
	for (int i = 0; i < size; i++) {
		result += temp[i];
	}
	return result;
}

int decimal_converter(string str) {
	int length = str.length();
	int* helper = new int [length];
	int n;
	for (int i = 0; i < str.length(); i++)
	{
		n = (int)str[i];
		switch (n)
		{
		case 48: n = 0; break;
		case 49: n = 1; break;
		default: break;
		}
		helper[i] = n;
	}
	int result = binary_to_decimal(helper,length);

	return result;
}


int main() {
	string str;
	cout << "Enter number in binary" << endl;
	cin >> str;

	cout << decimal_converter(str) << endl;


	system("pause");
	return 0;
}