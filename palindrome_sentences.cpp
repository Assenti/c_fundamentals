#include <iostream>
#include <string>
using namespace std;

void main() {
	string str;
	getline(cin, str);
	bool is_palindrome = true;
	int h_s_size = str.length();
	string helper_str = new char[h_s_size];
	int space_counter = 0;
	
	for (int i = 0, j = 0; i < str.length(); i++, j++) {
		if (str[i] == ' ') {
			helper_str[j] = str[i + 1];
			space_counter++;
			i++;
		}
		else {
			helper_str[j] = str[i];
		}
	}
	
	int helper_size = h_s_size - space_counter;
	for (int i = 0; i < helper_size / 2; i++) {
		if (helper_str[i] != helper_str[helper_size - 1 - i]) {
			is_palindrome = false;
		}
	}

	if (is_palindrome) {
		cout << "YES" << endl;
	} 
	else {
		cout << "NO" << endl;
	}



	system("pause");
}