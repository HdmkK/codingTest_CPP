#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



int T, n;

int main() {

	cin >> T;

	for (int TC = 0; TC < T; ++TC) {
		cin >> n;

		vector<vector<int>> board(2, vector<int>(n));
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < n; ++j) {
				int input;
				cin >> input;
				board[i][j] = input;
			}
		}

		vector<vector<int>> dp(3, vector<int>(n));

		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				dp[0][0] = board[0][0];
				dp[1][0] = board[1][0];
				dp[2][0] = 0;
				continue;
			}

			dp[0][i] = max(dp[1][i - 1], dp[2][i - 1]) + board[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + board[1][i];
			dp[2][i] = max({ dp[0][i - 1], dp[1][i - 1], dp[2][i - 1] });
		}

		cout << max({ dp[0][n - 1], dp[1][n - 1], dp[2][n - 1] }) << endl;
	}
	return 0;
}