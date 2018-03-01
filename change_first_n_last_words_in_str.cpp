#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main() {
	string original_value = "Today I ate an ice-cream";
	string arr[10];
	int iterator = 0;
	int i = 0, j = 0, last_point = 0;
	string word = "";

	for (i = 0; i <= original_value.size(); i++)
	{
		if (isspace(original_value[i]) || original_value[i] == '\0')
		{
			for (j = last_point; j < i; j++)
			{
				word += original_value[j];
			}
			cout << word << endl;
			last_point = j;
			arr[iterator] = word;
			iterator++;
			word = "";
		}
	}
	iterator--;

	string temp = arr[0];
	arr[0] = arr[iterator];
	arr[iterator] = temp;
	for (int i = 0; i <= iterator; i++) {
		cout << arr[i] << endl;
	}
	system("pause");
	return 0;
}