#include <iostream>
#include <string>
using namespace std;

void main() {
	string fio;
	getline(cin, fio);
	int fio_size = fio.length();
	int pre_initials_size = fio.length();
	int initials_size = fio.length();
	int last_name_size = fio.length();
	string pre_initials = new char[pre_initials_size];
	string initials = new char[initials_size];
	string last_name = new char[last_name_size];
	int length_counter = 0;
	//Sultanov Asset Kozhabekovich => A.K. Sultanov
	
	int i;
	for (i = 0; i < fio_size; i++) {
		if (fio[i] == ' ') {
			break;
		}
		last_name[i] = fio[i];
	}
	last_name_size = i;

	for (int i = 1, j = 0; i < fio_size; i++) {
		if ((int)fio[i] >= 65 && (int)fio[i] <= 90) {
			pre_initials[j] = fio[i];
			length_counter++;
			j++;
		}
	}
	pre_initials_size = length_counter;
	initials_size = length_counter * 2;

	for (int i = 1, j = 0, k = 0; j < initials_size; i+=2, j++, k+=2) {
		initials[k] = pre_initials[j];
		initials[i] = '.';
	}

		
	/*****************OUTPUT**********************/
	//Initials
	
	for (int i = 0; i < initials_size; i++) {
		cout << initials[i];
	}
	cout << " ";

	//Lastname
	for (int i = 0; i < last_name_size; i++) {
		cout << last_name[i];
	}
	cout << endl;

	
	system("pause");
}