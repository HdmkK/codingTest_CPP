#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> solution(vector<vector<int>> arr, int n) {

	int N = arr.size();

	for (int k = 0; k < n; ++k) {
		vector<vector<int>> new_arr(N, vector<int>(N, 0));

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				new_arr[(N - 1) - j][i] = arr[i][j];
			}
		}
		arr = new_arr;
	}
	return arr;
}

void print_arr(const vector<vector<int>>& arr) {
	for (int i = 0; i < arr.size(); ++i) {
		cout << "[";
		for (int j = 0; j < arr[0].size(); ++j) {
			cout << arr[i][j] << ", ";
		}
		cout << "]" << endl;
	}
}
int main() {

	vector<vector<int>> arr{
			{1, 2, 3, 4},
			{5, 6, 7, 8},
			{9, 10, 11, 12},
			{13, 14, 15, 16}
	};

	int n = 3;
	print_arr(solution(arr, n));
	return 0;
}