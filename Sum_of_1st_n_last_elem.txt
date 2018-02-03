#include <iostream>
#include <ctime>
using namespace std;

//Сумма первого и последнего элемента 
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(0));
	int const n = 10;
	int const a = 5;
	int arr[n], arr2[a];

	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 21;
		cout << arr[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < n / 2; i++)
	{
		arr2[i] = arr[i] + arr[n - 1 - i];
		cout << arr2[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}
