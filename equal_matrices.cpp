//#include <iostream>
//#include <time.h>
//using namespace std;
//
//void fill_2d_array(int arr[][4], int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			arr[i][j] = rand() % 10; //for convenience of counting
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//void are_two_matrices_equal(int arr1[][4], int arr2[][4], int size) {
//	bool equal = true;
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			if (arr1[i][j] != arr2[i][j]) {
//				equal = false;
//				break;
//			}
//		}	
//	}
//	if (equal) {
//		cout << "Two matrices are equal" << endl;
//	}
//	else {
//		cout << "Two matrices are NOT equal" << endl;
//	}
//}
//
//
//void main() {
//	srand(time(0));
//	int const size = 4;
//	int matrix_one[size][size];
//	int matrix_two[size][size];
//
//	fill_2d_array(matrix_one, size);
//	cout << "================" << endl;
//	fill_2d_array(matrix_two, size);
//	
//	are_two_matrices_equal(matrix_one, matrix_two, size);
//
//	system("pause");
//}
