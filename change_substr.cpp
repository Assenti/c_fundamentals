#include <iostream>
#include <string>
using namespace std;

void change_substr(string str, string str1, string str2) {
	for (int i = 0, j = 0; i < str.length() || j < str1.length(); i++) {
		if (str[i] == str1[j]) {
			str[i] = str2[j];
			j++;
		}
	}
	for (int i = 0; i < str.length(); i++) {
		cout << str[i];
	}
	cout << endl;
}


void main() {
	string str, str1, str2;
	cin >> str >> str1 >> str2;

	change_substr(str, str1, str2);

	system("pause");
}