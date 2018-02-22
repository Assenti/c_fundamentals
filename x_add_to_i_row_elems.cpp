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
//void x_add_to_i_row_elems(int arr[][4], int size, int *index, int x) {
//	for (int j = 0; j < size; j++) {
//		arr[*index][j] = arr[*index][j] + x;
//	}
//}
//
//void print_arr(int arr[][4], int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < size; j++) {
//			cout << arr[i][j] << " ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//}
//
//
//void main() {
//	srand(time(0));
//	int const size = 4;
//	int x, index;
//	int matrix[size][size];
//	fill_2d_array(matrix, size);
//	cout << "========================" << endl;
//	cout << "Enter the number that will be added to elements of i-row: ";
//	cin >> x;
//	cout << "Enter a row index i: ";
//	cin >> index;
//		
//	x_add_to_i_row_elems(matrix, size, &index, x);
//	print_arr(matrix, size);
//
//	system("pause");
//}
