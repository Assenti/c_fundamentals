//Search for element in array which sum of 10 sequence is minimum

#include <iostream>
#include <time.h>
using namespace std;

void fill_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 30;
		cout << i << "] " << arr[i] << endl;
	}
}

int min_elem(int *arr, int size, int elem = 0, int min = INT_MAX, int req_item = 0)
{
	int sum = 0;
	if (elem == size - 10) return req_item;
	for (int j = elem; j < elem + 10; j++)
		sum += arr[j];
	
	if (sum < min) 
	{
		min = sum;
		req_item = elem;
	}
	return (min_elem(arr, size, elem+1, min, req_item));
}

void main()
{
	srand(time(0)); rand();
	int arr[100];

	fill_arr(arr,100);
	cout<< "The minimum 10 numbers begin with element #" << min_elem(arr, 100);
	cout << endl;
	system("pause");
}
