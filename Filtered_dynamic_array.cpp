#include <iostream>
#include <time.h>
using namespace std;

//Напишите функцию для фильтрации определенных элементов из массива. В частности,
//функция создаст новый массив, содержащий только элементы, которые больше или
//равный некоторому порогу x.

void fill_dynamic_array(int *&arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 50;
	}
}

void show_array(int *&arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void filtered_array(int *&arr, int &size, int &x) {
	int *temp_array = new int[size];
	int counter = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] >= x) {
			temp_array[counter] = arr[i];
			counter++;
		}
	}
	size = counter;
	delete[]arr;
	arr = temp_array;
}


void main() {
	srand(time(0));
	cout << "Enter a certain threshold" << endl;
	int size = 10;
	int x;
	cin >> x;
	int *arr = new int[size];

	fill_dynamic_array(arr, size);
	show_array(arr, size);
	filtered_array(arr, size, x);
	show_array(arr, size);

	system("pause");
}