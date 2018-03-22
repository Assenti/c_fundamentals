#include <iostream>
#include <ctime>
using namespace std;

//Найти максимальные 3 числа, чтобы они не повторялись
int main()
{
	srand(time(0));
	int const n = 6;
	int arr[n][n] = { 0 };
	int max1 = -2, max2 = -2, max3 = -2;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 50;
			cout << arr[i][j] << "\t";
			if (arr[i][j] > max1 && arr[i][j] != max3 && arr[i][j] != max2)
			{
				max3 = max2;
				max2 = max1;
				max1 = arr[i][j];
			}
			else if (arr[i][j] > max2 && arr[i][j] != max1 && arr[i][j] != max3)
			{
				max3 = max2;
				max2 = arr[i][j];
			}
			else if (arr[i][j] > max3 && arr[i][j] != max2 && arr[i][j] != max1)
				max3 = arr[i][j];
		}
		cout << endl;
	}
	cout << max1 << " " << max2 << " " << max3 << endl;
	
	system("pause");
	return 0;
}
