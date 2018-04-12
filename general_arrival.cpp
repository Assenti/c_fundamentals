#include <iostream>

using namespace std;

int main()
{
	int soldiers, height, seconds = 0;
	cin >> soldiers;
	int * soldiers_row = new int[soldiers];
	int min = INT_MAX, min_index = 0, max = INT_MIN, max_index = 0;
	int to_high = 0, to_low = 0;

	for (int i = 0; i < soldiers; i++)
	{
		cin >> height;
		soldiers_row[i] = height;
	}

	for (int i = 0; i < soldiers; i++)
	{
		if (soldiers_row[i] <= min)
		{
			min = soldiers_row[i];
			min_index = i;
		}
		if (soldiers_row[i] <= min && ((soldiers - 1) - i) < ((soldiers - 1) - min_index))
		{
			min_index = i;
		}
		if (soldiers_row[i] > max)
		{
			max = soldiers_row[i];
			max_index = i;
		}
	}
	to_low = min_index == (soldiers - 1) ? 0 : (soldiers - 1) - min_index;
	to_high = max_index == 0 ? 0 : max_index;
	seconds = to_low + to_high;
	if (min_index < max_index)
	{
		cout << --seconds << endl;
	}
	else
	{
		cout << seconds << endl;
	}
	
	delete[] soldiers_row;
	return 0;
}