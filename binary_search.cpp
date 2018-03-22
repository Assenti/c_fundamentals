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

}

void bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size-i-1; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}

}

//Binary search
int binary_search(int sorted_arr[], int left_side, int right_side, int value)
{
	if (left_side > right_side)
		return -1;
	else
	{
		cout << "Called BS" << endl;
		int mid_point = left_side + ((right_side - left_side) / 2);
		if (sorted_arr[mid_point] == value)
			return mid_point;
		else if (value > sorted_arr[mid_point]) //in the right side
			return binary_search(sorted_arr, mid_point + 1, right_side, value);
		else if (value < sorted_arr[mid_point]) //in the left side
			return binary_search(sorted_arr, left_side, mid_point - 1, value);
	}
}

int main()
{
	int const size = 50;
	int arr[size];
	fill_arr(arr, size);
	bubble_sort(arr, size);
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << binary_search(arr,0,size-1,10) << endl;

	system("pause");
	return 0;
}
