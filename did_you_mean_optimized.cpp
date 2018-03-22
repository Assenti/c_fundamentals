#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;


int levenstain(string str1, string str2);

void possible_var(string words_base[], int size_of_words_base, string inputed_string);


int main() {
		
	string input;
	
	while (true)
	{
		cout << "Enter the word or sentence" << endl;
		getline(cin, input);

		string path = "20k.txt"; //input the path to your file with words
		//in my case the directory of my file is the same with this project directory
		string words[20001];
		int i = 0;

		ifstream fin;
		fin.open(path);
		int words_size = sizeof(words) / sizeof(words[0]);

		string check_msg = !fin.is_open() ? "Error" : "File successfully opened";
		cout << check_msg << endl;

		string temp;
		while (!fin.eof())
		{
			temp = " ";
			fin >> temp;
			words[i] = temp;
			i++;
		}

		cout << "Did you mean: ";
		possible_var(words, words_size, input);
		cout << endl;
		
		fin.close();
	}
	
	return 0;
}

#pragma region Functions
int levenstain(string str1, string str2) {
	int height = str1.length() + 1;
	int length = str2.length() + 1;
	int** matrix = new int*[height];
	for (int i = 0; i < height; i++) {
		matrix[i] = new int[length];
	}

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < length; j++) {
			if (i == 0 && j == 0) {
				matrix[i][j] = 0;
			}
			else if (i == 0) {
				matrix[i][j] = matrix[i][j - 1] + 1;
			}
			else if (j == 0) {
				matrix[i][j] = matrix[i - 1][j] + 1;
			}
			else {
				if (str1[i - 1] == str2[j - 1]) {
					matrix[i][j] = matrix[i - 1][j - 1];
				}
				else {
					matrix[i][j] = 1 + min(matrix[i - 1][j - 1], min(matrix[i - 1][j], matrix[i][j - 1]));
				}
			}
		}
	}
	return matrix[height - 1][length - 1];
}

void possible_var(string words_base[], int size_of_words_base, string inputed_string) {
	string temp;
	int iwa_size = 100;
	string* inputed_words_arr = new string[iwa_size];
	int last_point = 0, i = 0, j = 0, k = 0, iter = 0;

	//transfer all words from inputed string to array of words
	do
	{
		if (!(isspace(inputed_string[k])) || inputed_string[k] == '\0')
		{
			if (inputed_string[j] == ' ') {
				j++;
			}
			else {
				j = last_point;
			}

			while (inputed_string[j] != ' ' && j < inputed_string.length())
			{
				temp += inputed_string[j];
				j++;
			}
		}
		last_point = j;
		k = last_point + 1;
		inputed_words_arr[iter] = temp;
		i++;
		iter++;
		temp = "";
	} while (inputed_string[j] != '\0');

	iwa_size = iter;
	
	int index_of_min = 0;
	string output, checking_word;
	
	//compare each word in our array of words with words base 
	for (int i = 0; i < iwa_size; i++)
	{
		int min = INT_MAX;
		int comparison_result = 0;

		for (int j = 0; j < size_of_words_base; j++)
		{
			comparison_result = levenstain(inputed_words_arr[i], words_base[j]);

			if (comparison_result == 0) //same word
			{
				output += inputed_words_arr[i];
				output += " ";
				break;
			}
			else 
			{
				if (comparison_result < min)
				{
					min = comparison_result;
					index_of_min = j;
				}
			}
		}
		
		if (checking_word != words_base[index_of_min] && comparison_result != 0)
		{
			output += words_base[index_of_min];
			output += " ";
		}
		checking_word = words_base[index_of_min];
		
	}

	cout << output << endl;
}
#pragma endregion