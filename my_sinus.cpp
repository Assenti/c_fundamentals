//#include <iostream>
//#include <cmath>
//#include <valarray>
//using namespace std;
//
//int factorial(int n) {
//	if (n < 0)
//		return 0;
//	if (n == 0)
//		return 1;
//	else
//		return n  * factorial(n - 1);
//}
//
//double sinus(double *x) {
//	return *x - (pow(*x, 3) / factorial(3)) + (pow(*x, 5) / factorial(5)) - (pow(*x, 7) / factorial(7));
//}
//
//void main() {
//	double x;
//	cout << "Enter value: ";
//	cin >> x;
//	cout << "Sine approx.: " << sinus(&x) << endl;
//	cout << "Sine value: " << sin(x) << endl;
//	cout << "Difference is: " << sin(x) - sinus(&x) << endl; //strange
//	system("pause");
//}
