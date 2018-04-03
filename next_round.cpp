#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	int participants, places, points, size_counter = 0, counter = 0;
	cin >> participants >> places;
	int * points_storage = new int[participants];
	bool zero_detect = false;

	for (int i = 0; i < participants; i++)
	{
		cin >> points;
		if (points > 0)
		{
			points_storage[i] = points;
			size_counter++;
		}
		else
		{
			zero_detect = true;
		}
		
	}
	
	if (zero_detect && size_counter < places)
	{
		counter = size_counter;
	}
	else
	{
		counter = places;
	}

	for (int i = counter; i < participants; i++)
	{
		if (points_storage[counter - 1] == points_storage[i])
		{
			counter++;
		}
	}
	
	cout << counter << endl;

	return 0;
}