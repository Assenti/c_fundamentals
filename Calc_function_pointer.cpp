#include <iostream>

using namespace std;

double sum(double, double);
double diff(double, double);
double mult(double, double);
double div(double, double);


void main() {
	double(*calc_func)(double, double) = NULL;
	cout << "Enter 1st value, then 2nd value, then enter command code: 1 - '+' , 2 - '-', 3 - '*', 4 - '/'" << endl;
	
	int code;
	double a, b;
	
	cin >> a >> b >> code;

	switch (code)
	{
	case 1:
		calc_func = sum;
		break;
	case 2:
		calc_func = diff;
		break;
	case 3:
		calc_func = mult;
		break;
	case 4:
		calc_func = div;
		break;
	case 0:
		return;
	default:
		break;
	}
	
	cout << calc_func(a, b) << endl;
	system("pause");
}

double sum(double a, double b) {
	return a + b;
}
double diff(double a, double b) {
	return a - b;
}
double mult(double a, double b) {
	return a*b;
}
double div(double a, double b) {
	return a / b;
}