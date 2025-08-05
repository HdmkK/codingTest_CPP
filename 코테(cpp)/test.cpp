#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
using namespace std;

int T;
vector<vector<int>> A;
vector<vector<int>> DP;
vector<vector<bool>> mem;

void init() {
	A.assign(10, vector<int>(10, 0));
	DP.assign(10, vector<int>(10, 0));
	mem.assign(10, vector<bool>(10, false));

	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			cin >> A[x][y];

			if (A[x][y] == 1) DP[x][y] = 1;
		}
	}
}

int dx[] = { -1, -1, 0 };
int dy[] = { 0, -1, -1 };

void memoization() {

	for (int x = 0; x < 10; ++x) {
		for (int y = 0; y < 10; ++y) {
			if (A[x][y] == 0) continue;

			int minV = numeric_limits<int>::max();

			for (int i = 0; i < 3; ++i) {
				int n_x = x + dx[i];
				int n_y = y + dy[i];
				if (n_x < 0 || n_x >= 10 || n_y < 0 || n_y >= 10) continue;

				minV = min(minV, DP[n_x][n_y]);
			}

			if (minV == numeric_limits<int>::max())
				DP[x][y] = 1;
			else
				DP[x][y] = minV + 1;
		}
	}
}

int calc() {

	int sum = 0;
	for (int k = 5; k >= 1; --k) {

		for (int x = 0; x < 10; ++x) {
			for (int y = 0; y < 10; ++y) {
				
				if (DP[x][y] == k && mem[x][y]) {
					sum++;

					for (int i = x - 5 + 1; i <= x; ++i) {
						for (int j = y - 5 + 1; j <= y; ++j) {
							mem[i][j] = true;
						}
					}
				}
			}
		}
	}

	return sum;
}

int main() {
	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {

		init();

		memoization();

		int ret = calc();
	}
	return 0;
}