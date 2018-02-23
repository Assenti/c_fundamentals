#include <iostream>
#include <string>

using namespace std;

int contains(char *arr, int size, char elem) {
	int return_index = -1;
	for (int i = 0; i < size; i++) {
		if (arr[i] == elem) {
			return_index = i;
		}
	}
	return return_index;
}


void main() {
	/*string str = "Apple";
	string str2("Banana");
	char my_str_array[] = { 'm','e','l','o','n', '\0' };
	string str3(my_str_array);

	cout << str << " " << str.size() << endl;
	cout << str2 << " " << str2.length() << endl;
	cout << str3 << " " << str3.length() << endl;
	cout << endl;

	for (int i = 0; i < str.length(); i++) {
		cout << (int) str[i] << " ";
	}
	cout << endl;*/

	/************************CEASER CRYPT***************************/
	/************************CRYPT**********************************/
	/*string input;
	int rotate_val;
	cin >> input >> rotate_val;

	for (int i = 0; i < input.size(); i++) {
		cout << (int) input[i] << " ";	
	}
	cout << endl;
	
	for (int i = 0; i < input.size(); i++) {
		
		if (i % 2 == 0) {
			input[i] += rotate_val;
			
		}
		else {
			input[i] -= rotate_val;
			
		}
		input[i] += (rotate_val + i);
		cout << (int)input[i] << " ";
	}
	cout << endl;

	for (int i = 0; i < input.size(); i++) {
		cout << input[i] << " ";
	}
	cout << endl;*/


	/************************ENCRYPT**********************************/
	/*string encrypt;
	int rotate_val;
	getline(cin, encrypt);
	cin >> rotate_val;

	for (int i = 0; i < encrypt.size(); i++) {
		cout << (int)encrypt[i] << " ";
	}

	for (int i = 0; i < encrypt.size(); i++) {
		encrypt[i] -= rotate_val;
	}
	cout << endl;
	for (int i = 0; i < encrypt.size(); i++) {
		cout << encrypt[i] << " ";
	}
	cout << endl;*/
	
	/*******************Find upper case letters*****************/
	/*string upperCase;
	getline(cin, upperCase);
	int i, j;

	for (int j = 0; j < upperCase.size(); j++) {
		if ((int)upperCase[j] >= 65 && (int)upperCase[j] <= 90) {
			cout << upperCase[j] << " ";
		}
	}
	cout << endl;*/

	/*******************Find lower case letters*****************/
	/*string lowerCase;
	getline(cin, lowerCase);
	int i, j;
	
	for (int j = 0; j < lowerCase.size(); j++) {
		if ((int)lowerCase[j] >= 97 && (int)lowerCase[j] <= 122) {
			cout << lowerCase[j] << " ";
		}
	}
	cout << endl;*/

	/*******************Print letters btwn x - y in ASCII*****************/
	//string letters_btwn;
	//int x, y;
	//getline(cin, letters_btwn);
	//cout << "Enter x and y range" << endl;
	//cin >> x >> y;
	//for (int i = 0; i < letters_btwn.size(); i++) {
	//	if ((int)letters_btwn[i] >= x && (int)letters_btwn[i] <= y) {
	//		cout << letters_btwn[i] << " ";
	//	}
	//}
	//cout << endl;
	
	/*******************Number of words in sentences*****************/
	/*string sentences;
	getline(cin, sentences);
	int counter = 1;
	for (int i = 0; i < sentences.size(); i++) {
		if (sentences[i] == ' ') {
			counter++;
		}
	}
	cout << "There are: "<< counter << " words"<< endl;*/
	
	/*******************How many times letter x appears*****************/
	/*string word;
	char x;
	int counter = 0;
	getline(cin, word);
	cout << "Enter the letter: ";
	cin >> x;
	for (int i = 0; i < word.size(); i++) {
		if (word[i] == x) {
			counter++;
		}
	}
	cout << "Letter " << x << " appears "<< counter << " times" << endl; */

	/*******************How many times each letter in word appears*****************/
	string word, temp_word;
	
	getline(cin, word);
	temp_word = word;
	int size = word.size();
	int index_iterator = 0;
	char *elems = new char[size];
	int *indecies = new int[size] {0};

	
	for (int i = 0; i < word.size(); i++) {
		int result = contains(elems, size, word[i]);
		if (result == -1) {
			elems[index_iterator] = word[i];
			indecies[index_iterator]++;
			index_iterator++;
		}
		else {
			indecies[result]++;
		}
	}
	for (int i = 0; i < index_iterator; i++) {
		cout << elems[i] << " " << indecies[i] << endl;
	}


	/*******************Palindrome*****************/
	/*string word;
	getline(cin, word);
	bool palindrome = true;

	for (int i = 0; i < word.size(); i++) {
		if (word[i] != word[(word.size()) - 1 - i]) {
			palindrome = false;
		}
	}

	if (palindrome)
		cout << "Palindrome!" << endl;
	else
		cout << "Not palindrome!" << endl;*/

	system("pause");
}