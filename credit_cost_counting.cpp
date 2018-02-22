//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int total_cost_of_loan(int *p, double *i, int *n) {
//	double upper_side = (*p * *i) * pow((1 + *i), 12 * *n);
//	double downer_side = (pow((1 + *i), 12 * *n)) - 1;
//
//	return ((upper_side / downer_side) * 12 * *n) - *p;
//}
//
//void main() {
//	double r;
//	int n, p;
//	cout << "Remember: 1% is equal 0.01, 10% is equal 0.1 and etc." << endl;
//	cout << "Enter the rate (%)" << endl;
//	cin >> r;
//	cout << "Enter the period the loan to be paid back (years)" << endl;
//	cin >> n;
//	cout << "Enter the starting principle amount (USD)" << endl;
//	cin >> p;
//	double i = r / 12;
//	cout << "The total cost of a loan: " << total_cost_of_loan(&p, &i, &n) << " USD" << endl;
//
//	system("pause");
//}
