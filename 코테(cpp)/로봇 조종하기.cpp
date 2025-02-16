#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main() {

	cin >> N >> M;
	vector<vector<int>> board(N, vector<int>(M));
	vector<vector<int>> dp(N, vector<int>(M, -200));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			int input;
			cin >> input;
			board[i][j] = input;
		}
	}

	//∏« ¿≠ ¡Ÿ
	dp[0][0] = board[0][0];
	for (int i = 1; i < M; ++i) {
		dp[0][i] = dp[0][i - 1] + board[0][i];
	}

	vector<int> temp1(M);
	vector<int> temp2(M);

	for (int i = 1; i < N; ++i) {
		temp1[0] = dp[i - 1][0] + board[i][0];

		for (int j = 1; j < M; ++j) {
			temp1[j] = max(temp1[j - 1], dp[i - 1][j]) + board[i][j];
		}

		temp2[M - 1] = dp[i - 1][M - 1] + board[i][M - 1];

		for (int j = M - 2; j >= 0; --j) {
			temp2[j] = max(dp[i - 1][j], temp2[j + 1]) + board[i][j];
		}

		for (int j = 0; j < M; ++j) {
			dp[i][j] = max(temp1[j], temp2[j]);
		}
	}

	cout << dp[N - 1][M - 1] << endl;

	return 0;
}
