#include <iostream>
#include <time.h>
using namespace std;

int max_y(int *y_points, int size) {
	int max_value = y_points[0];
	for (int i = 1; i < size; i++) {
		if (y_points[i] > max_value) {
			max_value = y_points[i];
		}
	}
	return max_value;
}

int parabola(int x) {
	return x * x;
}

int initialize_arrays(int *x_points, int *y_points, int from_x, int to_x) {
	int size = to_x - from_x;
	x_points = new int[size];
	y_points = new int[size];
	return size;
}

void fill_array(int * x_points, int *y_points, int from_x, int to_x) {
	int inner_iterator = 0;
	for (int i = from_x; i <= to_x; i++) {
		x_points[inner_iterator] = i;
		y_points[inner_iterator] = parabola(i);
		inner_iterator++;
	}
}


void main() {
	
	int start_x = -4;
	int finish_x = 4;
	int size = (finish_x - start_x)+1;
	int optimized_size = (size % 2 == 0) ? (size + 1) : size;
	int *x_points = new int[size], *y_points = new int[size];
	
	fill_array(x_points, y_points, start_x, finish_x);
	int maximum_y = max_y(y_points, size);

	char **board = new char *[maximum_y];

	for (int i = 0; i < maximum_y+1; i++) {
		board[i] = new char[optimized_size];
		for (int j = 0; j < optimized_size; j++) {
			board[i][j] = 0;
		}
	}

	int mid_x = size / 2;
	board[maximum_y - 1][mid_x] = 1;

	for (int i = 0; i < maximum_y+1; i++) {
		for (int j = 0; j < optimized_size; j++) {
			board[i][j] = ' ';
			//cout << board[i][j] << "  ";
		}
		//cout << endl;
	}
	cout << "==============================" << endl;
	
		
	for (int i = 0; i < size; i++) {
		int x_to_fill = mid_x + x_points[i];
		int y_to_fill = maximum_y +1 - 1 - (x_points[i] * x_points[i]);
		board[y_to_fill][x_to_fill] = '#';
	}

	for (int i = 0; i < maximum_y+1; i++) {
		for (int j = 0; j < optimized_size; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}

	for (int i = 0; i < size; i++) {
		cout << x_points[i] << "  ";
	}
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << y_points[i] << "  ";
	}
	cout << endl;
	cout << "==============================" << endl;
	
	system("pause");
}