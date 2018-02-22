//#include <iostream>
//#include <time.h>
//using namespace std;
//
//void fill_array(int *arr, int size) {
//	for (int i = 0; i < size; i++) {
//		arr[i] = rand() % 10;
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//	cout << "========================================" << endl;
//}
//
//
//bool x_between_i_n_j(int *arr, int *i_index, int *j_index, int *x) {
//	bool exist;
//	for (int i = *i_index; i < *j_index; i++) {
//		if (!(arr[i] == *x)) {
//			exist = false;
//			
//		}
//		else {
//			exist = true;
//			
//		}
//	}
//	return exist;
//}
//
//
//
//void main() {
//	srand(time(0));
//	int const size = 20;
//	int arr[size];
//	fill_array(arr, size);
//	cout << "Enter x: ";
//	int x, i_index, j_index;
//	cin >> x;
//	cout << "Begin from: ";
//	cin >> i_index;
//	cout << "Finish at: ";
//	cin >> j_index;
//	
//	cout << x_between_i_n_j(arr, &i_index, &j_index, &x) << endl;
//	
//	system("pause");
//}
