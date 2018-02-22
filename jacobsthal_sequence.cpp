//#include <iostream>
//using namespace std;
//
//int jacobsthal_sequence_with_memo(int n, int *memo) {
//	if (memo[n] == -1) {
//		memo[n] = jacobsthal_sequence_with_memo(n - 1, memo) + (2 * jacobsthal_sequence_with_memo(n - 2, memo));
//	}
//	return memo[n];
//}
//
//void main() {	
//	int n;
//	int memo[10] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171 };
//
//	cout << "Remember: indecies starts from 0" << endl;
//	cout << "Enter the index of sequence : ";
//	cin >> n;
//	
//	//Necessary to our jacobsthal_sequence_with_memo function
//	for (int i = 10; i <= n; i++) {
//		memo[i] = -1;
//	}
//
//	cout << "Number of sequence in this index is: " << jacobsthal_sequence_with_memo(n, memo) << endl;
//
//	system("pause");
//}