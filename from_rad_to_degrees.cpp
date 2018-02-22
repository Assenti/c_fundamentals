//#include <iostream>
//using namespace std;
//
//bool checking_input(int *radians) {
//	bool correct = true;
//	if (*radians<0 || *radians >(2 * 3.141592)) {
//		correct = false;
//	}
//	else {
//		correct = true;
//	}
//	return correct;
//}
//
//double from_R_to_D(int *radians) {
//	if (!(checking_input(radians))) {
//		cout << "Invalid value. Please enter the valid value" << endl;
//		return 0;
//	}
//	else {
//		return 180 * *radians / 3.141592;
//	}
//}
//
//
//void main() {
//	int radians;
//	
//	cout << "Radians value: ";
//	cin >> radians;
//	checking_input(&radians);
//	cout << "Degrees value: " << from_R_to_D(&radians) <<  endl;
//
//	system("pause");
//}
