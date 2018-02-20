//#include <iostream>
//#include <time.h>
//using namespace std;
//
//
//void fill_array(int *&arr, int size) {
//	for (int i = 0; i < size; i++) {
//		arr[i] = rand() % 20;
//	}
//}
//
//void show_array(int *&arr, int size) {
//	for (int i = 0; i < size; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//}
//
////Delete last element in array
//void pop_back(int *&arr, int &size) {
//	int *new_array = new int[size - 1];
//	for (int i = 0; i < size; i++) {
//		new_array[i] = arr[i];
//	}
//	size--;
//	delete[] arr;
//	arr = new_array;
//}
//
////Delete first element in array
//void pop_back2(int *&arr, int &size) {
//	int *new_array = new int[size-1];
//	for (int i = 0; i < size-1; i++) {
//		new_array[i] = arr[i];
//	}
//	size--;
//	delete[] arr; 
//	arr = new_array;
//}
//
////Add element to the end of array
//void push_back(int *&arr, int &size, const int value) {
//	int *new_array = new int[size + 1];
//	for (int i = 0; i < size; i++) {
//		new_array[i] = arr[i];
//	}
//	new_array[size] = value;
//	size++;
//	delete[] arr;
//	arr = new_array;
//}
//
////Add element to the beginning of array
//void push_back2(int *&arr, int &size, const int value) {
//	int *new_array = new int[size + 1];
//	for (int i = 0; i < size; i++) {
//		new_array[i+1] = arr[i];
//	}
//	new_array[0] = value;
//	size++;
//	delete[] arr;
//	arr = new_array;
//}
//
//
///***************************Main*******************************/
//void main() {
//	srand(time(0));
//	int size;
//	cin >> size;
//
//	int *arr = new int[size];
//
//	fill_array(arr, size);
//	show_array(arr, size);
//	
//	pop_back2(arr, size);
//	cout << "Calling pop_back function" << endl;
//
//	//push_back2(arr, size, 777);
//	//cout << "Calling push_back function" << endl;
//	show_array(arr, size);
//	
//
//	system("pause");
//}