#include <iostream>
#include <time.h>
using namespace std;

//Filling array by randoms and sort ascending by Choices_sort method

void rand_fill_array(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand()%50;
		cout << arr[i] << " ";
	}
}

void sort_ascending(int *arr, int size)
{
	int min = 0;
	for (int i = 0; i < size; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}					   
		if (min != i)
		{
			swap(arr[i], arr[min]);
		}
		cout << arr[i] << " ";
	}

}


void main()
{
	srand(time(0));
	int const size = 10;
	int arr[size];

	rand_fill_array(arr, size);
	cout << endl;
	sort_ascending(arr, size);
	cout << endl;
	
	system("pause");
}
