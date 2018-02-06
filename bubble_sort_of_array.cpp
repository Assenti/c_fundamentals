#include <iostream>
#include <time.h>

using namespace std;

void fill_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 50;
		cout << arr[i] << " ";
	}
	cout << endl;
}


void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}


void main() {
	srand(time(0));
	const int size = 10;
	int arr[size];
	fill_arr(arr, size);
	bubbleSort(arr, size);
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	
	system("pause");
}
