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
//void swap_elems_in_matrix(int arr[][4], int size, int *i_index, int *j_index) {
//	int i, j;
//	for (i = 0, j = 0; i < size; i++, j++) {
//		swap(arr[i][*j_index], arr[*i_index][j]);
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
//void main() {
//	srand(time(0));
//	int const size = 4;
//	int matrix[size][size];
//	int i_index, j_index;
//	fill_2d_array(matrix, size);
//	cout << "=====================" << endl;
//	//It is necessary to enter the same indices in the i-row and j-row
//	cout << "Enter i-index: ";
//	cin >> i_index;
//	cout << "Enter j-index: ";
//	cin >> j_index;
//
//	swap_elems_in_matrix(matrix, size, &i_index, &j_index);
//	print_arr(matrix, size);
//		
//	system("pause");
//}