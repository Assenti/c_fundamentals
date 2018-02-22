#include <iostream>
#include <cmath>
using namespace std;

double speed_of_sound(double *t) {
	double num_under_sqrt = ((5 * *t) + 297) / 247;
	double sec_num_to_mult = sqrt(num_under_sqrt);
	return 1086 * sec_num_to_mult;
}


void main() {
	double fahr_temp;
	cout << "Fahrenheit temp: ";
	cin >> fahr_temp;
	cout << "Speed of sound: " << speed_of_sound(&fahr_temp) << " feet-per-second" << endl;

	system("pause");
}
