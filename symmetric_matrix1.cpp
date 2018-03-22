#include <iostream>
#include <time.h>
using namespace std;

void is_symetric_matrix(int ** matrix, int size) {
	bool is_symetric = true;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (!(matrix[i][j] == matrix[j][i])) {
				is_symetric = false;
				break;
			}
		}
	}
	if (is_symetric) {
		cout << "Matrix is symetric" << endl;
	}
	else {
		cout << "Matrix is not symetric" << endl;
	}
}


int main() {
	int **matrix = new int *[3];

	for (int i = 0; i < 3; i++) {
		matrix[i] = new int[3];
		for (int j = 0; j < 3; j++) {
			int number;
			cin >> number;
			matrix[i][j] = number;
		}
		cout << endl;
	}


	is_symetric_matrix(matrix,3);

	
	system("pause");
	return 0;
}
