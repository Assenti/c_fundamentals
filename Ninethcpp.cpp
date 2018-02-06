#include <iostream>
#include<time.h>
using namespace std;

void fill_arr(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 30;
		cout << arr[i] << " ";
	}
	cout << endl;
}
void fill_arr(double arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = double(rand())/RAND_MAX*30;
		cout << arr[i] << " ";
	}
	cout << endl;
}

int average(int arr[], int size)
{
	int sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

double average(double arr[], int size)
{
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
	}
	return sum / size;
}

void main()
{
	srand(time(0)); rand();
	int const size = 10;
	//int arr[size];
	double arr[size];
	cout << "Original array:\t";
	fill_arr(arr, size);
	cout << "Average number of array: ";
	cout << average(arr, size) << endl;

	system("pause");
}
