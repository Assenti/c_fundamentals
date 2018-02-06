#include <iostream>
#include <time.h>

using namespace std;

void fill_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 60-30;
		cout << arr[i] << " ";
	}
	cout << endl;
}

void numbers(int *arr, int size, int *plus, int *minus, int *zero)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > 0) (*plus)++;
		else if (arr[i] < 0) (*minus)++;
		else (*zero)++;
	}
	cout << "Quantity of positive numbers:\t" << *plus << endl;
	cout << "Quantity of negative numbers:\t" << *minus << endl;
	cout << "Quantity of zeros:\t\t" << *zero << endl;
}

void main()
{
	srand(time(0));
	const int size = 20;
	int arr[size];

	int plus = 0, minus = 0, zero = 0;
	fill_arr(arr,size);
	numbers(arr, size, &plus, &minus, &zero);

	system("pause");
}
