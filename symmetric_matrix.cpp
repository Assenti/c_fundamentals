#include <iostream>
#include <time.h>
using namespace std;

void fill_2d_array(int arr[][3], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 2; //for convenience of counting
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void is_symmetric(int arr[][3], int size) {
	bool symmetric = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (arr[i][j] != arr[j][i]) {
				symmetric = false;
				break;
			}
		}
	}
	if (symmetric) {
		cout << "Matrix is symmetric" << endl;
	}
	else {
		cout << "Matrix is NOT symmetric" << endl;
	}
}

int main() {
	int const size = 3;
	int matrix[size][size];

	fill_2d_array(matrix, size);
	is_symmetric(matrix, size);

	system("pause");
  return 0;
}
