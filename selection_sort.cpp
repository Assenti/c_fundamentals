#include <iostream>
#include <ctime>
using namespace std;

//Сортировка методом выбора - Choices (Selection) Sort
//Принцип заключается в том, что мы сразу находим самый меньший(больший) элемент в массиве и ставим его в начало массива, затем на каждой итерации проделывается то же самое, таким образом сортируется массив
int main()
{
	srand(time(0));
	int const size = 10;
	int arr[size];

	//Заполнение массива рандомом
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100-20;
		cout << arr[i] << " ";
	}
	cout << endl;
	
	//Если по возрастанию, то ищем минимальный элемент (если по убыванию соответственно максимальный)
	int min = 0;
	for (int i = 0; i < size-1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min]) min = j; //проверяем каждый элемент массива с переменной min
		}					    //и перезаписываем его на самый минимальный элемент
		if (min!=i) swap(arr[i], arr[min]); //если min не равен i то меняем их местами и так с каждым элементом
	}
	
	//Output
	for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
	cout << endl;

	system("pause");
	return 0;
}
