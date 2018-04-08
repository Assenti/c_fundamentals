#include <iostream>
#include <string>

using namespace std;

int main()
{
	string word;
	cin >> word; //zeus
	int counter = 0, steps = 0, decrease_to_alphabet = 96;
	int start_point = 0, end_point = 0;
	
	start_point = (int)'a';
	end_point = (int)word[0];
	if (start_point == end_point)
	{
		steps = 0;
	}
	else if (abs(start_point - end_point) == 1)
	{
		steps = 1;
	}
	else if (start_point <= 110)
	{
		if ((end_point > 110 && start_point > 110) || (end_point <= 110 && start_point <= 110))
		{
			steps = abs((end_point - decrease_to_alphabet) - (start_point - decrease_to_alphabet));
		}
		else
		{
			steps = 26 - abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet));
		}
	}
	else
	{
		if (end_point < start_point)
		{
			if ((end_point > 110 && start_point > 110) || (end_point <= 110 && start_point <= 110))
			{
				steps = abs((end_point - decrease_to_alphabet) - (start_point - decrease_to_alphabet));
			}
			else
			{
				steps = 26 - abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet));
			}
		}
		else
		{
			steps = (end_point - decrease_to_alphabet) - (start_point - decrease_to_alphabet);
		}
	}
	counter += steps;

	for (int i = 1; i < word.length(); i++)
	{
		start_point = (int)word[i-1];
		end_point = (int)word[i];

		if (start_point == end_point)
		{
			steps = 0;
		}
		else if (abs(start_point - end_point) == 1)
		{
			steps = 1;
		}
		else if (start_point <= 110)
		{
			if ((end_point > 110 && start_point > 110) || (end_point <= 110 && start_point <= 110))
			{
				steps = abs((end_point - decrease_to_alphabet) - (start_point - decrease_to_alphabet));
			}
			else if (abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet)) <
				26 - abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet)))
			{
				steps = abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet));
			}
			else
			{
				steps = 26 - abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet));
			}
		}
		else
		{
			if (end_point < start_point)
			{
				if ((end_point > 110 && start_point > 110) || (end_point <= 110 && start_point <= 110))
				{
					steps = abs((end_point - decrease_to_alphabet) - (start_point - decrease_to_alphabet));
				}
				else if (abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet)) <
					26 - abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet)))
				{
					steps = abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet));
				}
				else
				{
					steps = 26 - abs((start_point - decrease_to_alphabet) - (end_point - decrease_to_alphabet));
				}
			}
			else
			{
				steps = (end_point - decrease_to_alphabet) - (start_point - decrease_to_alphabet);
			}
		}
		counter += steps;
	}

	cout << counter << endl;
	
	return 0;
}